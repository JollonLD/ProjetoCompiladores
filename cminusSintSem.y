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

}

%union {
    int ival;
    char *id;
    TipoVar tipo;
    struct {
        TipoVar tipo;
        int is_array;
    } var_info;
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
%type<tipo> type_specifier expression simple_expression
%type<tipo> additive_expression term factor
%type<var_info> var

%start program

%%

/* 1. program → declaration-list */
program : 
    declaration_list 
    { 
        printf("Analise sintatica concluida com sucesso!\n"); 
        if (!has_errors) {
            printf("Analise semantica: Nenhum erro encontrado.\n");
        }
    }
    ;

/* 2. declaration-list → declaration-list declaration | declaration */
declaration_list :
    declaration_list declaration
    | declaration
    ;

/* 3. declaration → var-declaration | fun-declaration */
declaration :
    var_declaration
    | fun_declaration
    ;

/* 4. var-declaration → type-specifier ID ; | type-specifier ID [ NUM ] ; */
var_declaration :
    type_specifier ID SEMI
    {
        insert_symbol($2, $1, KIND_VAR, yylineno);
        free($2);
    }
    | type_specifier ID LBRACK NUM RBRACK SEMI
    {
        if ($1 == TYPE_VOID) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: array '%s' nao pode ser void\n", 
                    yylineno, $2);
            has_errors = 1;
        } else {
            insert_array($2, $4, yylineno);
        }
        free($2);
    }
    ;

/* 5. type-specifier → int | void */
type_specifier :
    INT  { $$ = TYPE_INT; }
    | VOID { $$ = TYPE_VOID; }
    ;

/* 6. fun-declaration → type-specifier ID ( params ) compound-stmt */
fun_declaration :
    type_specifier ID 
    {
        insert_function($2, $1, yylineno);
        /* pega o símbolo da função no escopo atual (onde foi inserida) */
        Simbolo *func_sym = lookup_symbol_current($2);
        enter_scope();
        if (func_sym) {
            func_sym->def_scope = escopo_atual; /* associa escopo da função */
        }
    }
    LPAREN params RPAREN compound_stmt
    {
        leave_scope();
        free($2);
    }
    ;

/* 7. params → param-list | void */
params :
    param_list
    | VOID
    | /* empty */
    ;

/* 8. param-list → param-list , param | param */
param_list :
    param_list COMMA param
    | param
    ;

/* 9. param → type-specifier ID | type-specifier ID [ ] */
param :
    type_specifier ID
    {
        if ($1 == TYPE_VOID) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: parametro '%s' nao pode ser void\n",
                    yylineno, $2);
            has_errors = 1;
        } else {
            insert_symbol($2, $1, KIND_VAR, yylineno);
            Simbolo *p = lookup_symbol_current($2);
            if (p) p->is_param = 1;
        }
        free($2);
    }
    | type_specifier ID LBRACK RBRACK
    {
        if ($1 == TYPE_VOID) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: parametro array '%s' nao pode ser void\n",
                    yylineno, $2);
            has_errors = 1;
        } else {
            insert_symbol($2, TYPE_INT_ARRAY, KIND_ARRAY, yylineno);
            Simbolo *p = lookup_symbol_current($2);
            if (p) p->is_param = 1;
        }
        free($2);
    }
    ;

/* 10. compound-stmt → { local-declarations statement-list } */
compound_stmt :
    LBRACE local_declarations statement_list RBRACE
    ;

/* 11. local-declarations → local-declarations var-declaration | empty */
local_declarations :
    local_declarations var_declaration
    | /* empty */
    ;

/* 12. statement-list → statement-list statement | empty */
statement_list :
    statement_list statement
    | /* empty */
    ;

/* 13. statement → expression-stmt | compound-stmt | selection-stmt | iteration-stmt | return-stmt */
statement :
    expression_stmt
    | compound_stmt_with_scope
    | selection_stmt
    | iteration_stmt
    | return_stmt
    ;

compound_stmt_with_scope :
    { enter_scope(); } 
    compound_stmt 
    { leave_scope(); }
    ;

/* 14. expression-stmt → expression ; | ; */
expression_stmt :
    expression SEMI
    | SEMI
    ;

/* 15. selection-stmt → if ( expression ) statement | if ( expression ) statement else statement */
selection_stmt :
    IF LPAREN expression RPAREN statement
    {
        if ($3 != TYPE_INT) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: condicao do IF deve ser inteira\n", yylineno);
            has_errors = 1;
        }
    }
    | IF LPAREN expression RPAREN statement ELSE statement
    {
        if ($3 != TYPE_INT) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: condicao do IF deve ser inteira\n", yylineno);
            has_errors = 1;
        }
    }
    ;

/* 16. iteration-stmt → while ( expression ) statement */
iteration_stmt :
    WHILE LPAREN expression RPAREN statement
    {
        if ($3 != TYPE_INT) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: condicao do WHILE deve ser inteira\n", yylineno);
            has_errors = 1;
        }
    }
    ;

/* 17. return-stmt → return ; | return expression ; */
return_stmt :
    RETURN SEMI
    | RETURN expression SEMI
    ;

/* 18. expression → var = expression | simple-expression */
expression :
    var ASSIGN expression
    {
        if ($1.is_array) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: nao e possivel atribuir a array completo\n", yylineno);
            has_errors = 1;
            $$ = TYPE_ERROR;
        } else if ($1.tipo != $3 && $3 != TYPE_ERROR) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: tipos incompativeis na atribuicao\n", yylineno);
            has_errors = 1;
            $$ = TYPE_ERROR;
        } else {
            $$ = $1.tipo;
        }
    }
    | simple_expression { $$ = $1; }
    ;

/* 19. var → ID | ID [ expression ] */
var :
    ID
    {
        Simbolo *s = lookup_symbol($1);
        if (!s) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: variavel '%s' nao declarada\n", yylineno, $1);
            has_errors = 1;
            $$.tipo = TYPE_ERROR;
            $$.is_array = 0;
        } else {
            $$.tipo = s->tipo;
            $$.is_array = (s->kind == KIND_ARRAY);
        }
        free($1);
    }
    | ID LBRACK expression RBRACK
    {
        Simbolo *s = lookup_symbol($1);
        if (!s) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: variavel '%s' nao declarada\n", yylineno, $1);
            has_errors = 1;
            $$.tipo = TYPE_ERROR;
        } else if (s->kind != KIND_ARRAY) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: '%s' nao e um array\n", yylineno, $1);
            has_errors = 1;
            $$.tipo = TYPE_ERROR;
        } else if ($3 != TYPE_INT) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: indice de array deve ser inteiro\n", yylineno);
            has_errors = 1;
            $$.tipo = TYPE_ERROR;
        } else {
            $$.tipo = TYPE_INT;
        }
        $$.is_array = 0;
        free($1);
    }
    ;

/* 20. simple-expression → additive-expression relop additive-expression | additive-expression */
simple_expression :
    additive_expression relop additive_expression
    {
        $$ = check_expression_type("relacional", $1, $3, yylineno);
    }
    | additive_expression { $$ = $1; }
    ;

/* 21. relop → <= | < | > | >= | == | != */
relop : LE | LT | GT | GE | EQ | NE ;

/* 22. additive-expression → additive-expression addop term | term */
additive_expression :
    additive_expression addop term
    {
        $$ = check_expression_type("aditivo", $1, $3, yylineno);
    }
    | term { $$ = $1; }
    ;

/* 23. addop → + | - */
addop : PLUS | MINUS ;

/* 24. term → term mulop factor | factor */
term :
    term mulop factor
    {
        $$ = check_expression_type("multiplicativo", $1, $3, yylineno);
    }
    | factor { $$ = $1; }
    ;

/* 25. mulop → * | / */
mulop : TIMES | DIVIDE ;

/* 26. factor → ( expression ) | var | call | NUM */
factor :
    LPAREN expression RPAREN { $$ = $2; }
    | var 
    { 
        if ($1.is_array) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: uso de array sem indexacao\n", yylineno);
            has_errors = 1;
            $$ = TYPE_ERROR;
        } else {
            $$ = $1.tipo; 
        }
    }
    | call { $$ = TYPE_INT; } /* simplificacao: assume que funcoes retornam int */
    | NUM { $$ = TYPE_INT; }
    ;

/* 27. call → ID ( args ) */
call :
    ID LPAREN args RPAREN
    {
        Simbolo *s = lookup_symbol($1);
        if (!s) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: funcao '%s' nao declarada\n", yylineno, $1);
            has_errors = 1;
        } else if (s->kind != KIND_FUNC) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: '%s' nao e uma funcao\n", yylineno, $1);
            has_errors = 1;
        }
        free($1);
    }
    ;

/* 28. args → arg-list | empty */
args :
    arg_list
    | /* empty */
    ;

/* 29. arg-list → arg-list , expression | expression */
arg_list :
    arg_list COMMA expression
    | expression
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