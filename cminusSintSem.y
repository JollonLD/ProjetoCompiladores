%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    extern int yylex(void);
    extern int yyparse(void);
    extern FILE *yyin;
    extern int yylineno;

    void yyerror(const char *s);
    
    int has_errors = 0;
%}

%expect 1

%code requires {
    /* ===== TIPOS DE DADOS ===== */
    typedef enum {
        TYPE_INT,
        TYPE_VOID,
        TYPE_INT_ARRAY,
        TYPE_ERROR
    } TipoVar;

    typedef enum {
        KIND_VAR,
        KIND_ARRAY,
        KIND_FUNC
    } TipoSimbolo;

    typedef struct Simbolo {
        char *nome;
        TipoVar tipo;
        TipoSimbolo kind;
        int tamanho;        /* para arrays */
        int num_params;     /* para funcoes (mantido por compatibilidade) */
        TipoVar *param_types; /* tipos dos parametros */
        int linha;
        int is_param;           /* 1 se este simbolo é um parâmetro */
        struct Escopo *def_scope; /* escopo associado (para funções: o escopo do corpo) */
        struct Simbolo *prox;
    } Simbolo;

    typedef struct Escopo {
        Simbolo *simbolos;
        struct Escopo *pai;
        struct Escopo *next_all; /* link para lista de todos os escopos */
    } Escopo;

    /* Funcoes da tabela de simbolos */
    void enter_scope();
    void leave_scope();
    Simbolo* lookup_symbol(const char *nome);
    Simbolo* lookup_symbol_current(const char *nome);
    void insert_symbol(const char *nome, TipoVar tipo, TipoSimbolo kind, int linha);
    void insert_array(const char *nome, int tamanho, int linha);
    void insert_function(const char *nome, TipoVar tipo_retorno, int linha);
    void add_param_to_function(const char *func_nome, TipoVar tipo_param);
    TipoVar check_expression_type(const char *op, TipoVar t1, TipoVar t2, int linha);
    void check_return_type(TipoVar tipo_func, TipoVar tipo_exp, int linha);
    void check_function_call(const char *nome, int num_args, int linha);

    /* libera todos os escopos no final */
    void free_all_scopes();

    extern Escopo *escopo_atual;
    extern Escopo *lista_escopos;

    /* ===== ESTRUTURA DA AST ===== */
    typedef enum {STMTK, EXPK, VARK} NodeKind;
    typedef enum {INTEGERK, VOIDK, IFK, WHILEK, RETURNK, COMPK} StmtKind;
    typedef enum {OPK, CONSTK, IDK, ASSIGNK, CALLK, VECTORK} ExpKind;
    typedef enum {DECLK, ACCESSK} VarAccessK;
    
    #define MAXCHILDREN 3
    
    typedef struct Identifier {
        TipoSimbolo varKind;
        VarAccessK acesso;
        union {
            int val;
            char *name;
        } attr;
    } Identifier;
    
    typedef struct treeNode {
        struct treeNode *child[MAXCHILDREN];
        struct treeNode *sibling;
        int lineno;
        NodeKind nodekind;
        union {
            StmtKind stmt;
            ExpKind exp;
            struct Identifier var;
        } kind;
        int op;                    /* token para operadores */
        TipoVar type;              /* tipo de dado */
    } TreeNode;
    
    /* Funções para criar nós */
    TreeNode* newStmtNode(StmtKind kind);
    TreeNode* newExpNode(ExpKind kind);
    TreeNode* newVarNode(ExpKind kind);
    void printTree(TreeNode *tree, int indent);

}

%union {
    int ival;
    char *id;
    TipoVar tipo;
    struct {
        TipoVar tipo;
        int is_array;
    } var_info;
    TreeNode *node;
}

/* ===== TOKENS ===== */
%token<id> ID
%token<ival> NUM
%token ELSE IF INT RETURN VOID WHILE
%token LE LT GT GE EQ NE
%token ASSIGN SEMI COMMA
%token LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE
%token PLUS MINUS TIMES DIVIDE

/* ===== PRECEDÊNCIA ===== */
%left PLUS MINUS
%left TIMES DIVIDE
%right ASSIGN
%left LT LE GT GE EQ NE

/* ===== TIPOS NÃO-TERMINAIS ===== */
%type<tipo> type_specifier
%type<ival> relop addop mulop
%type<node> expression simple_expression
%type<node> additive_expression term factor var
%type<node> program declaration_list declaration
%type<node> var_declaration fun_declaration
%type<node> params param_list param
%type<node> compound_stmt compound_stmt_with_scope local_declarations statement_list
%type<node> statement expression_stmt selection_stmt
%type<node> iteration_stmt return_stmt call args arg_list

%start program

%%

/* 1. program → declaration-list */
program : 
    declaration_list 
    { 
        $$ = $1;
        printf("Analise sintatica concluida com sucesso!\n"); 
        if (!has_errors) {
            printf("Analise semantica: Nenhum erro encontrado.\n");
            
            /* Imprime a AST */
            printf("\n");
            printf("================================================================================\n");
            printf("                      ARVORE SINTATICA ABSTRATA (AST)\n");
            printf("================================================================================\n");
            printTree($$, 0);
            printf("================================================================================\n");
        }
    }
    ;

/* 2. declaration-list → declaration-list declaration | declaration */
declaration_list :
    declaration_list declaration
    {
        TreeNode *t = $1;
        if (t != NULL) {
            while (t->sibling != NULL)
                t = t->sibling;
            t->sibling = $2;
            $$ = $1;
        } else {
            $$ = $2;
        }
    }
    | declaration { $$ = $1; }
    ;

/* 3. declaration → var-declaration | fun-declaration */
declaration :
    var_declaration { $$ = $1; }
    | fun_declaration { $$ = $1; }
    ;

/* 4. var-declaration → type-specifier ID ; | type-specifier ID [ NUM ] ; */
var_declaration :
    type_specifier ID SEMI
    {
        /* Análise semântica */
        insert_symbol($2, $1, KIND_VAR, yylineno);
        
        /* Construção da AST - padrão correto */
        $$ = newStmtNode($1 == TYPE_INT ? INTEGERK : VOIDK);
        $$->type = $1;
        
        /* Criar nó ID e anexar como filho */
        $$->child[0] = newVarNode(IDK);
        $$->child[0]->kind.var.attr.name = strdup($2);
        $$->child[0]->kind.var.varKind = KIND_VAR;
        $$->child[0]->kind.var.acesso = DECLK;
        $$->child[0]->type = $1;
        $$->child[0]->lineno = yylineno;
        
        free($2);
    }
    | type_specifier ID LBRACK NUM RBRACK SEMI
    {
        /* Análise semântica */
        if ($1 == TYPE_VOID) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: array '%s' nao pode ser void\n", 
                    yylineno, $2);
            has_errors = 1;
        } else {
            insert_array($2, $4, yylineno);
        }
        
        /* Construção da AST - padrão correto */
        $$ = newStmtNode($1 == TYPE_INT ? INTEGERK : VOIDK);
        $$->type = $1;
        
        /* Criar nó ID array e anexar como filho */
        $$->child[0] = newVarNode(VECTORK);
        $$->child[0]->kind.var.attr.name = strdup($2);
        $$->child[0]->kind.var.varKind = KIND_ARRAY;
        $$->child[0]->kind.var.acesso = DECLK;
        $$->child[0]->type = $1;
        $$->child[0]->lineno = yylineno;
        
        /* Adicionar tamanho do array como filho do nó array */
        $$->child[0]->child[0] = newExpNode(CONSTK);
        $$->child[0]->child[0]->kind.var.attr.val = $4;
        $$->child[0]->child[0]->type = TYPE_INT;
        $$->child[0]->child[0]->lineno = yylineno;
        
        free($2);
    }
    ;

/* 5. type-specifier → int | void */
type_specifier :
    INT  { 
        $$ = TYPE_INT;
    }
    | VOID { 
        $$ = TYPE_VOID;
    }
    ;

/* 6. fun-declaration → type-specifier ID ( params ) compound-stmt */
fun_declaration :
    type_specifier ID 
    {
        /* Análise semântica */
        insert_function($2, $1, yylineno);
        Simbolo *func_sym = lookup_symbol_current($2);
        enter_scope();
        if (func_sym) {
            func_sym->def_scope = escopo_atual;
        }
    }
    LPAREN params RPAREN compound_stmt
    {
        leave_scope();
        
        /* Construção da AST - padrão correto */
        $$ = newStmtNode($1 == TYPE_INT ? INTEGERK : VOIDK);
        $$->type = $1;
        
        /* Criar nó ID função e anexar como filho */
        $$->child[0] = newVarNode(IDK);
        $$->child[0]->kind.var.attr.name = strdup($2);
        $$->child[0]->kind.var.varKind = KIND_FUNC;
        $$->child[0]->kind.var.acesso = DECLK;
        $$->child[0]->type = $1;
        $$->child[0]->lineno = yylineno;
        
        /* Adicionar parâmetros e corpo como filhos do nó função */
        $$->child[0]->child[0] = $5;  /* parâmetros */
        $$->child[0]->child[1] = $7;  /* corpo */
        
        free($2);
    }
    ;

/* 7. params → param-list | void */
params :
    param_list { $$ = $1; }
    | VOID { $$ = NULL; }
    | /* empty */ { $$ = NULL; }
    ;

/* 8. param-list → param-list , param | param */
param_list :
    param_list COMMA param
    {
        TreeNode *t = $1;
        if (t != NULL) {
            while (t->sibling != NULL)
                t = t->sibling;
            t->sibling = $3;
            $$ = $1;
        } else {
            $$ = $3;
        }
    }
    | param { $$ = $1; }
    ;

/* 9. param → type-specifier ID | type-specifier ID [ ] */
param :
    type_specifier ID
    {
        /* Análise semântica */
        if ($1 == TYPE_VOID) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: parametro '%s' nao pode ser void\n",
                    yylineno, $2);
            has_errors = 1;
        } else {
            insert_symbol($2, $1, KIND_VAR, yylineno);
            Simbolo *p = lookup_symbol_current($2);
            if (p) p->is_param = 1;
        }
        
        /* Construção da AST - padrão correto */
        $$ = newStmtNode($1 == TYPE_INT ? INTEGERK : VOIDK);
        $$->type = $1;
        
        $$->child[0] = newVarNode(IDK);
        $$->child[0]->kind.var.attr.name = strdup($2);
        $$->child[0]->kind.var.varKind = KIND_VAR;
        $$->child[0]->kind.var.acesso = DECLK;
        $$->child[0]->type = $1;
        $$->child[0]->lineno = yylineno;
        
        free($2);
    }
    | type_specifier ID LBRACK RBRACK
    {
        /* Análise semântica */
        if ($1 == TYPE_VOID) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: parametro array '%s' nao pode ser void\n",
                    yylineno, $2);
            has_errors = 1;
        } else {
            insert_symbol($2, TYPE_INT_ARRAY, KIND_ARRAY, yylineno);
            Simbolo *p = lookup_symbol_current($2);
            if (p) p->is_param = 1;
        }
        
        /* Construção da AST - padrão correto */
        $$ = newStmtNode($1 == TYPE_INT ? INTEGERK : VOIDK);
        $$->type = $1;
        
        $$->child[0] = newVarNode(VECTORK);
        $$->child[0]->kind.var.attr.name = strdup($2);
        $$->child[0]->kind.var.varKind = KIND_ARRAY;
        $$->child[0]->kind.var.acesso = DECLK;
        $$->child[0]->type = TYPE_INT_ARRAY;
        $$->child[0]->lineno = yylineno;
        
        free($2);
    }
    ;

/* 10. compound-stmt → { local-declarations statement-list } */
compound_stmt :
    LBRACE local_declarations statement_list RBRACE
    {
        $$ = newStmtNode(COMPK);
        $$->child[0] = $2;  /* declarações locais */
        $$->child[1] = $3;  /* lista de statements */
        $$->lineno = yylineno;
    }
    ;
/* 11. local-declarations → local-declarations var-declaration | empty */
local_declarations :
    local_declarations var_declaration
    {
        TreeNode *t = $1;
        if (t != NULL) {
            while (t->sibling != NULL)
                t = t->sibling;
            t->sibling = $2;
            $$ = $1;
        } else {
            $$ = $2;
        }
    }
    | /* empty */ { $$ = NULL; }
    ;

/* 12. statement-list → statement-list statement | empty */
statement_list :
    statement_list statement
    {
        TreeNode *t = $1;
        if (t != NULL) {
            while (t->sibling != NULL)
                t = t->sibling;
            t->sibling = $2;
            $$ = $1;
        } else {
            $$ = $2;
        }
    }
    | /* empty */ { $$ = NULL; }
    ;

/* 13. statement → expression-stmt | compound-stmt | selection-stmt | iteration-stmt | return-stmt */
statement :
    expression_stmt { $$ = $1; }
    | compound_stmt_with_scope { $$ = $1; }
    | selection_stmt { $$ = $1; }
    | iteration_stmt { $$ = $1; }
    | return_stmt { $$ = $1; }
    ;

compound_stmt_with_scope :
    { enter_scope(); } 
    compound_stmt 
    { 
        leave_scope();
        $$ = $2;
    }
    ;

/* 14. expression-stmt → expression ; | ; */
expression_stmt :
    expression SEMI { $$ = $1; }
    | SEMI { $$ = NULL; }
    ;

/* 15. selection-stmt → if ( expression ) statement | if ( expression ) statement else statement */
selection_stmt :
    IF LPAREN expression RPAREN statement
    {
        /* Análise semântica */
        if ($3 && $3->type != TYPE_INT) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: condicao do IF deve ser inteira\n", yylineno);
            has_errors = 1;
        }
        
        /* Construção da AST */
        $$ = newStmtNode(IFK);
        $$->child[0] = $3;    /* condição */
        $$->child[1] = $5;    /* then */
        $$->child[2] = NULL;  /* else */
        $$->lineno = yylineno;
    }
    | IF LPAREN expression RPAREN statement ELSE statement
    {
        /* Análise semântica */
        if ($3 && $3->type != TYPE_INT) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: condicao do IF deve ser inteira\n", yylineno);
            has_errors = 1;
        }
        
        /* Construção da AST */
        $$ = newStmtNode(IFK);
        $$->child[0] = $3;    /* condição */
        $$->child[1] = $5;    /* then */
        $$->child[2] = $7;    /* else */
        $$->lineno = yylineno;
    }
    ;

/* 16. iteration-stmt → while ( expression ) statement */
iteration_stmt :
    WHILE LPAREN expression RPAREN statement
    {
        /* Análise semântica */
        if ($3 && $3->type != TYPE_INT) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: condicao do WHILE deve ser inteira\n", yylineno);
            has_errors = 1;
        }
        
        /* Construção da AST */
        $$ = newStmtNode(WHILEK);
        $$->child[0] = $3;    /* condição */
        $$->child[1] = $5;    /* corpo */
        $$->lineno = yylineno;
    }
    ;

/* 17. return-stmt → return ; | return expression ; */
return_stmt :
    RETURN SEMI
    {
        $$ = newStmtNode(RETURNK);
        $$->child[0] = NULL;  /* sem expressão */
        $$->lineno = yylineno;
    }
    | RETURN expression SEMI
    {
        $$ = newStmtNode(RETURNK);
        $$->child[0] = $2;    /* expressão */
        $$->lineno = yylineno;
    }
    ;

/* 18. expression → var = expression | simple-expression */
expression :
    var ASSIGN expression
    {
        /* Análise semântica */
        TipoVar var_type = $1 ? $1->type : TYPE_ERROR;
        TipoVar exp_type = $3 ? $3->type : TYPE_ERROR;
        
        if ($1 && $1->nodekind == VARK && $1->kind.var.varKind == KIND_ARRAY && 
            $1->child[0] == NULL) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: nao e possivel atribuir a array completo\n", yylineno);
            has_errors = 1;
        } else if (var_type != exp_type && exp_type != TYPE_ERROR && var_type != TYPE_ERROR) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: tipos incompativeis na atribuicao\n", yylineno);
            has_errors = 1;
        }
        
        /* Construção da AST */
        $$ = newExpNode(ASSIGNK);
        $$->child[0] = $1;
        $$->child[1] = $3;
        $$->type = var_type;
        $$->lineno = yylineno;
    }
    | simple_expression { $$ = $1; }
    ;

/* 19. var → ID | ID [ expression ] */
var :
    ID
    {
        Simbolo *s = lookup_symbol($1);
        TipoVar tipo = TYPE_ERROR;
        TipoSimbolo kind = KIND_VAR;
        
        if (!s) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: variavel '%s' nao declarada\n", yylineno, $1);
            has_errors = 1;
        } else {
            tipo = s->tipo;
            kind = s->kind;
        }
        
        /* Cria nó de variável */
        if (kind == KIND_ARRAY) {
            $$ = newVarNode(VECTORK);
            $$->type = TYPE_INT_ARRAY;
        } else {
            $$ = newVarNode(IDK);
            $$->type = tipo;
        }
        $$->kind.var.attr.name = strdup($1);
        $$->kind.var.varKind = kind;
        $$->kind.var.acesso = ACCESSK;
        $$->lineno = yylineno;
        free($1);
    }
    | ID LBRACK expression RBRACK
    {
        Simbolo *s = lookup_symbol($1);
        TipoVar tipo = TYPE_ERROR;
        
        if (!s) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: variavel '%s' nao declarada\n", yylineno, $1);
            has_errors = 1;
        } else if (s->kind != KIND_ARRAY) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: '%s' nao e um array\n", yylineno, $1);
            has_errors = 1;
        } else if ($3 && $3->type != TYPE_INT) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: indice de array deve ser inteiro\n", yylineno);
            has_errors = 1;
        } else {
            tipo = TYPE_INT;
        }
        
        /* Cria nó de acesso a array */
        $$ = newVarNode(VECTORK);
        $$->kind.var.attr.name = strdup($1);
        $$->kind.var.varKind = KIND_ARRAY;
        $$->kind.var.acesso = ACCESSK;
        $$->child[0] = $3;  /* índice */
        $$->type = tipo;
        $$->lineno = yylineno;
        free($1);
    }
    ;

/* 20. simple-expression → additive-expression relop additive-expression | additive-expression */
simple_expression :
    additive_expression relop additive_expression
    {
        /* Análise semântica */
        TipoVar t1 = $1 ? $1->type : TYPE_ERROR;
        TipoVar t2 = $3 ? $3->type : TYPE_ERROR;
        TipoVar result = check_expression_type("relacional", t1, t2, yylineno);
        
        /* Construção da AST */
        $$ = newExpNode(OPK);
        $$->child[0] = $1;
        $$->child[1] = $3;
        $$->op = $2;  /* operador relacional */
        $$->type = result;
        $$->lineno = yylineno;
    }
    | additive_expression { $$ = $1; }
    ;

/* 21. relop → <= | < | > | >= | == | != */
relop : LE { $$ = LE; } 
      | LT { $$ = LT; } 
      | GT { $$ = GT; } 
      | GE { $$ = GE; } 
      | EQ { $$ = EQ; } 
      | NE { $$ = NE; }
      ;

/* 22. additive-expression → additive-expression addop term | term */
additive_expression :
    additive_expression addop term
    {
        /* Análise semântica */
        TipoVar t1 = $1 ? $1->type : TYPE_ERROR;
        TipoVar t2 = $3 ? $3->type : TYPE_ERROR;
        TipoVar result = check_expression_type("aditivo", t1, t2, yylineno);
        
        /* Construção da AST */
        $$ = newExpNode(OPK);
        $$->child[0] = $1;
        $$->child[1] = $3;
        $$->op = $2;  /* operador aditivo */
        $$->type = result;
        $$->lineno = yylineno;
    }
    | term { $$ = $1; }
    ;

/* 23. addop → + | - */
addop : PLUS { $$ = PLUS; } 
      | MINUS { $$ = MINUS; }
      ;

/* 24. term → term mulop factor | factor */
term :
    term mulop factor
    {
        /* Análise semântica */
        TipoVar t1 = $1 ? $1->type : TYPE_ERROR;
        TipoVar t2 = $3 ? $3->type : TYPE_ERROR;
        TipoVar result = check_expression_type("multiplicativo", t1, t2, yylineno);
        
        /* Construção da AST */
        $$ = newExpNode(OPK);
        $$->child[0] = $1;
        $$->child[1] = $3;
        $$->op = $2;  /* operador multiplicativo */
        $$->type = result;
        $$->lineno = yylineno;
    }
    | factor { $$ = $1; }
    ;

/* 25. mulop → * | / */
mulop : TIMES { $$ = TIMES; } 
      | DIVIDE { $$ = DIVIDE; }
      ;

/* 26. factor → ( expression ) | var | call | NUM */
factor :
    LPAREN expression RPAREN { $$ = $2; }
    | var { $$ = $1; }
    | call { $$ = $1; }
    | NUM 
    { 
        $$ = newExpNode(CONSTK);
        $$->kind.var.attr.val = $1;
        $$->type = TYPE_INT;
        $$->lineno = yylineno;
    }
    ;

/* 27. call → ID ( args ) */
call :
    ID LPAREN args RPAREN
    {
        Simbolo *s = lookup_symbol($1);
        TipoVar tipo = TYPE_INT;  /* padrão */
        
        if (!s) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: funcao '%s' nao declarada\n", yylineno, $1);
            has_errors = 1;
        } else if (s->kind != KIND_FUNC) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: '%s' nao e uma funcao\n", yylineno, $1);
            has_errors = 1;
        } else {
            tipo = s->tipo;  /* tipo de retorno da função */
        }
        
        /* Cria nó de chamada de função */
        $$ = newExpNode(CALLK);
        $$->kind.var.attr.name = strdup($1);
        $$->child[0] = $3;  /* argumentos */
        $$->type = tipo;
        $$->lineno = yylineno;
        free($1);
    }
    ;

/* 28. args → arg-list | empty */
args :
    arg_list { $$ = $1; }
    | /* empty */ { $$ = NULL; }
    ;

/* 29. arg-list → arg-list , expression | expression */
arg_list :
    arg_list COMMA expression
    {
        TreeNode *t = $1;
        if (t != NULL) {
            while (t->sibling != NULL)
                t = t->sibling;
            t->sibling = $3;
            $$ = $1;
        } else {
            $$ = $3;
        }
    }
    | expression { $$ = $1; }
    ;

%%

/* ===== IMPLEMENTAÇÃO DA TABELA DE SÍMBOLOS ===== */

Escopo *escopo_atual = NULL;
Escopo *lista_escopos = NULL;

void enter_scope() {
    Escopo *novo = (Escopo*) malloc(sizeof(Escopo));
    novo->simbolos = NULL;
    novo->pai = escopo_atual;
    novo->next_all = lista_escopos;
    lista_escopos = novo;
    escopo_atual = novo;
}

void leave_scope() {
    if (!escopo_atual) return;
    escopo_atual = escopo_atual->pai;
}

Simbolo* lookup_symbol_current(const char *nome) {
    if (!escopo_atual) return NULL;
    Simbolo *s = escopo_atual->simbolos;
    while (s) {
        if (strcmp(s->nome, nome) == 0) return s;
        s = s->prox;
    }
    return NULL;
}

Simbolo* lookup_symbol(const char *nome) {
    Escopo *e = escopo_atual;
    while (e) {
        Simbolo *s = e->simbolos;
        while (s) {
            if (strcmp(s->nome, nome) == 0) return s;
            s = s->prox;
        }
        e = e->pai;
    }
    return NULL;
}

void insert_symbol(const char *nome, TipoVar tipo, TipoSimbolo kind, int linha) {
    if (!escopo_atual) {
        fprintf(stderr, "Erro interno: nenhum escopo ativo\n");
        return;
    }
    
    if (lookup_symbol_current(nome)) {
        fprintf(stderr, "ERRO SEMANTICO: linha %d: '%s' ja declarado neste escopo\n", linha, nome);
        has_errors = 1;
        return;
    }
    
    Simbolo *s = (Simbolo*) malloc(sizeof(Simbolo));
    s->nome = strdup(nome);
    s->tipo = tipo;
    s->kind = kind;
    s->tamanho = 0;
    s->num_params = 0;
    s->param_types = NULL;
    s->linha = linha;
    s->prox = escopo_atual->simbolos;
    s->is_param = 0;
    s->def_scope = NULL;
    escopo_atual->simbolos = s;
}

void insert_array(const char *nome, int tamanho, int linha) {
    if (!escopo_atual) return;
    
    if (lookup_symbol_current(nome)) {
        fprintf(stderr, "ERRO SEMANTICO: linha %d: '%s' ja declarado neste escopo\n", linha, nome);
        has_errors = 1;
        return;
    }
    
    Simbolo *s = (Simbolo*) malloc(sizeof(Simbolo));
    s->nome = strdup(nome);
    s->tipo = TYPE_INT_ARRAY;
    s->kind = KIND_ARRAY;
    s->tamanho = tamanho;
    s->num_params = 0;
    s->param_types = NULL;
    s->linha = linha;
    s->prox = escopo_atual->simbolos;
    escopo_atual->simbolos = s;
}

void insert_function(const char *nome, TipoVar tipo_retorno, int linha) {
    if (!escopo_atual) return;
    
    if (lookup_symbol_current(nome)) {
        fprintf(stderr, "ERRO SEMANTICO: linha %d: '%s' ja declarado neste escopo\n", linha, nome);
        has_errors = 1;
        return;
    }
    
    Simbolo *s = (Simbolo*) malloc(sizeof(Simbolo));
    s->nome = strdup(nome);
    s->tipo = tipo_retorno;
    s->kind = KIND_FUNC;
    s->tamanho = 0;
    s->num_params = 0;
    s->param_types = NULL;
    s->linha = linha;
    s->prox = escopo_atual->simbolos;
    escopo_atual->simbolos = s;
}

TipoVar check_expression_type(const char *op, TipoVar t1, TipoVar t2, int linha) {
    if (t1 == TYPE_ERROR || t2 == TYPE_ERROR) {
        return TYPE_ERROR;
    }
    
    if (t1 == TYPE_VOID || t2 == TYPE_VOID) {
        fprintf(stderr, "ERRO SEMANTICO: linha %d: operacao %s com tipo void\n", linha, op);
        has_errors = 1;
        return TYPE_ERROR;
    }
    
    if (t1 != TYPE_INT || t2 != TYPE_INT) {
        fprintf(stderr, "ERRO SEMANTICO: linha %d: operacao %s requer operandos inteiros\n", linha, op);
        has_errors = 1;
        return TYPE_ERROR;
    }
    
    return TYPE_INT;
}

void ExibirTabelaSimbolos() {
    printf("\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("|                      TABELA DE SIMBOLOS DO COMPILADOR C-MINUS                      |\n");
    printf("--------------------------------------------------------------------------------------\n");
    
    printf("\n%-20s | %-10s | %-8s | %-10s | %-8s | %-6s | %s\n", 
           "NOME", "TIPO", "CATEGORIA", "ESCOPO", "TAMANHO", "PARAMS", "LINHA");
    printf("%-20s-%-10s-%-8s-%-10s-%-8s-%-6s---------\n",
           "--------------------", "----------", "--------", "----------", "--------", "------");
    
    /* Conta e armazena ponteiros para todos os escopos */
    int count = 0;
    Escopo *e = lista_escopos;
    while (e) { count++; e = e->next_all; }
    if (count == 0) {
        printf("\n");
        return;
    }
    
    Escopo **arr = (Escopo**) malloc(count * sizeof(Escopo*));
    int i = 0;
    e = lista_escopos;
    while (e) { arr[i++] = e; e = e->next_all; }

    /* printf("%-6d | ", computed_params); */
    
    /* Imprime do escopo mais antigo (global) para o mais interno,
       atribuindo escopo_num começando em 0 */
    int escopo_num = 0;
    for (int idx = count - 1; idx >= 0; idx--) {
        Simbolo *s = arr[idx]->simbolos;
        while (s) {
            printf("%-20s | ", s->nome);
            
            /* Tipo */
            switch (s->tipo) {
                case TYPE_INT:        printf("%-10s | ", "int"); break;
                case TYPE_VOID:       printf("%-10s | ", "void"); break;
                case TYPE_INT_ARRAY:  printf("%-10s | ", "int[]"); break;
                case TYPE_ERROR:      printf("%-10s | ", "ERROR"); break;
            }
            
            /* Tipo de Símbolo */
            switch (s->kind) {
                case KIND_VAR:   printf("%-8s | ", "VAR"); break;
                case KIND_ARRAY: printf("%-8s | ", "ARRAY"); break;
                case KIND_FUNC:  printf("%-8s | ", "FUNC"); break;
            }
            
            /* Escopo */
            printf("%-10d | ", escopo_num);
            
            /* Tamanho ou Params */
            if (s->kind == KIND_ARRAY) {
                printf("%-8d | ", s->tamanho);
            } else if (s->kind == KIND_FUNC) {
                printf("%-8s | ", "-");
            } else {
                printf("%-8s | ", "-");
            }
            
            /* Número de parâmetros */
            if (s->kind == KIND_FUNC) {
                int computed_params = 0;
                if (s->def_scope) {
                    Simbolo *ps = s->def_scope->simbolos;
                    while (ps) {
                        if (ps->is_param) computed_params++;
                        ps = ps->prox;
                    }
                }
                printf("%-6d | ", computed_params);
            } else {
                printf("%-6s | ", "-");
            }
            
            printf("%d\n", s->linha);
            s = s->prox;
        }
        escopo_num++;
    }
    
    free(arr);
    printf("\n");
}

void free_all_scopes() {
    Escopo *e = lista_escopos;
    while (e) {
        Simbolo *s = e->simbolos;
        while (s) {
            Simbolo *tmp = s;
            s = s->prox;
            free(tmp->nome);
            if (tmp->param_types) free(tmp->param_types);
            free(tmp);
        }
        Escopo *tmp_e = e;
        e = e->next_all;
        free(tmp_e);
    }
    lista_escopos = NULL;
    escopo_atual = NULL;
}

/* ===== IMPLEMENTAÇÃO DAS FUNÇÕES DA AST ===== */

/* Cria nó de statement */
TreeNode* newStmtNode(StmtKind kind) {
    TreeNode *t = (TreeNode*) malloc(sizeof(TreeNode));
    if (t == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memória para TreeNode\n");
        exit(1);
    }
    for (int i = 0; i < MAXCHILDREN; i++)
        t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = STMTK;
    t->kind.stmt = kind;
    t->lineno = yylineno;
    t->type = TYPE_VOID;
    t->op = 0;
    return t;
}

/* Cria nó de expressão */
TreeNode* newExpNode(ExpKind kind) {
    TreeNode *t = (TreeNode*) malloc(sizeof(TreeNode));
    if (t == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memória para TreeNode\n");
        exit(1);
    }
    for (int i = 0; i < MAXCHILDREN; i++)
        t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = EXPK;
    t->kind.exp = kind;
    t->lineno = yylineno;
    t->type = TYPE_INT;
    t->op = 0;
    t->kind.var.attr.name = NULL;
    return t;
}

/* Cria nó de variável/identificador */
TreeNode* newVarNode(ExpKind kind) {
    TreeNode *t = (TreeNode*) malloc(sizeof(TreeNode));
    if (t == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memória para TreeNode\n");
        exit(1);
    }
    for (int i = 0; i < MAXCHILDREN; i++)
        t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = VARK;
    t->kind.var.acesso = DECLK;
    t->kind.var.varKind = KIND_VAR;
    t->kind.var.attr.name = NULL;
    t->lineno = yylineno;
    t->type = TYPE_INT;
    t->op = 0;
    return t;
}

/* Imprime a árvore sintática */
void printTree(TreeNode *tree, int indent) {
    if (tree == NULL) return;
    
    /* Imprime indentação */
    for (int i = 0; i < indent; i++)
        printf("  ");
    
    /* Imprime tipo do nó */
    if (tree->nodekind == STMTK) {
        switch (tree->kind.stmt) {
            case INTEGERK:
                printf("[int]");
                if (tree->child[0]) {
                    if (tree->child[0]->nodekind == VARK) {
                        if (tree->child[0]->kind.var.varKind == KIND_FUNC) {
                            printf(" Function");
                        } else if (tree->child[0]->kind.var.varKind == KIND_ARRAY) {
                            printf(" Array");
                        } else {
                            printf(" Var");
                        }
                    }
                }
                printf("\n");
                break;
            case VOIDK:
                printf("[void]");
                if (tree->child[0] && tree->child[0]->nodekind == VARK && 
                    tree->child[0]->kind.var.varKind == KIND_FUNC) {
                    printf(" Function");
                }
                printf("\n");
                break;
            case IFK: printf("If\n"); break;
            case WHILEK: printf("While\n"); break;
            case RETURNK: printf("Return\n"); break;
            case COMPK: printf("Compound Statement\n"); break;
        }
    } else if (tree->nodekind == VARK) {
        printf("[%s]", tree->kind.var.attr.name);
        if (tree->kind.var.varKind == KIND_FUNC) {
            printf(" (function)");
        } else if (tree->kind.var.varKind == KIND_ARRAY) {
            printf(" (array)");
        } else if (tree->kind.var.varKind == KIND_VAR) {
            if (tree->kind.var.acesso == DECLK) {
                printf(" (declaration)");
            } else {
                printf(" (access)");
            }
        }
        printf("\n");
    } else if (tree->nodekind == EXPK) {
        switch (tree->kind.exp) {
            case OPK:
                printf("Op: ");
                switch (tree->op) {
                    case PLUS: printf("+"); break;
                    case MINUS: printf("-"); break;
                    case TIMES: printf("*"); break;
                    case DIVIDE: printf("/"); break;
                    case LT: printf("<"); break;
                    case LE: printf("<="); break;
                    case GT: printf(">"); break;
                    case GE: printf(">="); break;
                    case EQ: printf("=="); break;
                    case NE: printf("!="); break;
                    default: printf("?"); break;
                }
                printf("\n");
                break;
            case CONSTK: printf("Const: %d\n", tree->kind.var.attr.val); break;
            case IDK: printf("Id: %s\n", tree->kind.var.attr.name); break;
            case ASSIGNK: printf("Assign (=)\n"); break;
            case CALLK: printf("Call: %s()\n", tree->kind.var.attr.name); break;
            case VECTORK: printf("Vector: %s", tree->kind.var.attr.name); 
                if (tree->child[0]) printf(" [indexed]");
                printf("\n");
                break;
        }
    }
    
    /* Imprime filhos */
    for (int i = 0; i < MAXCHILDREN; i++)
        printTree(tree->child[i], indent + 1);
    
    /* Imprime irmãos */
    printTree(tree->sibling, indent);
}

int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            fprintf(stderr, "Erro: nao foi possivel abrir arquivo '%s'\n", argv[1]);
            return 1;
        }
    } else {
        yyin = stdin;
    }
    
    /* Cria escopo global */
    enter_scope();
    
    /* Adiciona funções built-in input e output */
    insert_symbol("input", TYPE_INT, KIND_FUNC, 0);
    insert_symbol("output", TYPE_VOID, KIND_FUNC, 0);
    
    yyparse();
    
    ExibirTabelaSimbolos();

    /* Libera todos os escopos e simbolos */
    free_all_scopes();
    
    if (yyin != stdin) fclose(yyin);
    
    return has_errors ? 1 : 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Erro sintatico linha %d: %s\n", yylineno, s);
    has_errors = 1;
}