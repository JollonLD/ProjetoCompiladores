# Makefile para o compilador C-Minus
# Compilador C-Minus com análise léxica, sintática e semântica

CC = gcc
CFLAGS = -Wall -Wno-unused-function -g
LEX = flex
YACC = bison
DOT = dot

# Arquivos fonte
LEX_SRC = cminusLex.l
YACC_SRC = cminusSintSem.y
CONTEXT_SRC = parser_context.c
CONTEXT_HDR = parser_context.h
CODEGEN_SRC = code_generator.c
CODEGEN_HDR = code_generator.h

# Arquivos gerados
LEX_GEN = lex.yy.c
YACC_GEN_C = cminus.tab.c
YACC_GEN_H = cminus.tab.h

# Arquivos objeto
CONTEXT_OBJ = parser_context.o
CODEGEN_OBJ = code_generator.o
LEX_OBJ = lex.yy.o
YACC_OBJ = cminus.tab.o

# Executável final
TARGET = cminus

# Regra padrão: compila tudo
all: check-headers $(TARGET)
	@echo "Compilação concluída com sucesso!"
	@echo ""
	@echo "Executável gerado: ./$(TARGET)"
	@echo "Uso: ./$(TARGET) programa.cm"
	@echo "A visualização da AST será gerada automaticamente se GraphViz estiver instalado."
	@echo "Arquivos gerados: ast.dot, ast.png, ast.svg"

check-headers:
	@if [ ! -f $(CONTEXT_HDR) ]; then \
		echo "Arquivo $(CONTEXT_HDR) não encontrado!"; \
		echo "Criando $(CONTEXT_HDR)..."; \
		$(MAKE) create-context-header; \
	fi
	@if [ ! -f $(CONTEXT_SRC) ]; then \
		echo "Arquivo $(CONTEXT_SRC) não encontrado!"; \
		echo "Criando $(CONTEXT_SRC)..."; \
		$(MAKE) create-context-source; \
	fi
	@if [ ! -f $(CODEGEN_HDR) ]; then \
		echo "Arquivo $(CODEGEN_HDR) não encontrado!"; \
		echo "Criando $(CODEGEN_HDR)..."; \
		$(MAKE) create-codegen-header; \
	fi
	@if [ ! -f $(CODEGEN_SRC) ]; then \
		echo "Arquivo $(CODEGEN_SRC) não encontrado!"; \
		echo "Criando $(CODEGEN_SRC)..."; \
		$(MAKE) create-codegen-source; \
	fi

# Cria o arquivo parser_context.h se não existir
create-context-header:
	@echo "#ifndef PARSER_CONTEXT_H" >> $(CONTEXT_HDR)
	@echo "#define PARSER_CONTEXT_H" >> $(CONTEXT_HDR)
	@echo "" >> $(CONTEXT_HDR)
	@echo "#include <stdio.h>" >> $(CONTEXT_HDR)
	@echo "" >> $(CONTEXT_HDR)
	@echo "/* Forward declarations */" >> $(CONTEXT_HDR)
	@echo "typedef struct treeNode TreeNode;" >> $(CONTEXT_HDR)
	@echo "struct Escopo;" >> $(CONTEXT_HDR)
	@echo "" >> $(CONTEXT_HDR)
	@echo "typedef struct ParserContext {" >> $(CONTEXT_HDR)
	@echo "    struct TreeNode *ast_root;" >> $(CONTEXT_HDR)
	@echo "    struct Escopo *escopo_atual;" >> $(CONTEXT_HDR)
	@echo "    struct Escopo *lista_escopos;" >> $(CONTEXT_HDR)
	@echo "    int has_errors;" >> $(CONTEXT_HDR)
	@echo "} ParserContext;" >> $(CONTEXT_HDR)
	@echo "" >> $(CONTEXT_HDR)
	@echo "ParserContext* parser_context_create(void);" >> $(CONTEXT_HDR)
	@echo "void parser_context_destroy(ParserContext *ctx);" >> $(CONTEXT_HDR)
	@echo "" >> $(CONTEXT_HDR)
	@echo "#endif /* PARSER_CONTEXT_H */" >> $(CONTEXT_HDR)
	@echo "$(CONTEXT_HDR) criado!"

# Cria o arquivo parser_context.c se não existir
create-context-source:
	@echo "#include \"$(CONTEXT_HDR)\"" > $(CONTEXT_SRC)
	@echo "#include <stdlib.h>" >> $(CONTEXT_SRC)
	@echo "" >> $(CONTEXT_SRC)
	@echo "ParserContext* parser_context_create(void) {" >> $(CONTEXT_SRC)
	@echo "    ParserContext *ctx = (ParserContext*)malloc(sizeof(ParserContext));" >> $(CONTEXT_SRC)
	@echo "    if (!ctx) return NULL;" >> $(CONTEXT_SRC)
	@echo "    ctx->ast_root = NULL;" >> $(CONTEXT_SRC)
	@echo "    ctx->escopo_atual = NULL;" >> $(CONTEXT_SRC)
	@echo "    ctx->lista_escopos = NULL;" >> $(CONTEXT_SRC)
	@echo "    ctx->has_errors = 0;" >> $(CONTEXT_SRC)
	@echo "    return ctx;" >> $(CONTEXT_SRC)
	@echo "}" >> $(CONTEXT_SRC)
	@echo "" >> $(CONTEXT_SRC)
	@echo "void parser_context_destroy(ParserContext *ctx) {" >> $(CONTEXT_SRC)
	@echo "    if (!ctx) return;" >> $(CONTEXT_SRC)
	@echo "    free(ctx);" >> $(CONTEXT_SRC)
	@echo "}" >> $(CONTEXT_SRC)
	@echo "$(CONTEXT_SRC) criado!"

# Cria o arquivo code_generator.h
create-codegen-header:
	@echo "#ifndef CGEN_H" >> $(CODEGEN_HDR)
	@echo "#define CGEN_H" >> $(CODEGEN_HDR)
	@echo "" >> $(CODEGEN_HDR)
	@echo "#include \"parser_context.h\"" >> $(CODEGEN_HDR)
	@echo "" >> $(CODEGEN_HDR)
	@echo "/* Forward declaration */" >> $(CODEGEN_HDR)
	@echo "typedef struct treeNode TreeNode;" >> $(CODEGEN_HDR)
	@echo "" >> $(CODEGEN_HDR)
	@echo "/* Função principal de geração de código intermediário */" >> $(CODEGEN_HDR)
	@echo "void codeGen(TreeNode* syntaxTree);" >> $(CODEGEN_HDR)
	@echo "" >> $(CODEGEN_HDR)
	@echo "#endif" >> $(CODEGEN_HDR)
	@echo "$(CODEGEN_HDR) criado!"

# Cria o arquivo code_generator.c
create-codegen-source:
	@printf '%s\n' \
		'/* code_generator.c */' \
		'#include "code_generator.h"' \
		'#include "cminus.tab.h"' \
		'#include <stdlib.h>' \
		'#include <stdio.h>' \
		'#include <string.h>' \
		'' \
		'static int contadorTemporarios = 0;' \
		'static int contadorLabels = 0;' \
		'' \
		'static char* gerarExpressao(TreeNode* no);' \
		'static void gerarComando(TreeNode* no);' \
		'static void gerarComandoExpressao(TreeNode* no);' \
		'' \
		'static char* novoTemporario(void) {' \
		'    char* nomeTemp = (char*)malloc(10 * sizeof(char));' \
		'    sprintf(nomeTemp, "t%d", contadorTemporarios++);' \
		'    return nomeTemp;' \
		'}' \
		'' \
		'static char* novoLabel(void) {' \
		'    char* nomeLabel = (char*)malloc(10 * sizeof(char));' \
		'    sprintf(nomeLabel, "L%d", contadorLabels++);' \
		'    return nomeLabel;' \
		'}' \
		'' > $(CODEGEN_SRC)
	@printf '%s\n' \
		'static char* gerarExpressao(TreeNode* no) {' \
		'    char* temp; char* esquerda; char* direita; char* operador;' \
		'    if (no == NULL) return NULL;' \
		'    if (no->nodekind == EXPK) {' \
		'        switch (no->kind.exp) {' \
		'            case CONSTK:' \
		'                temp = novoTemporario();' \
		'                printf("%s = %d\n", temp, no->kind.var.attr.val);' \
		'                return temp;' \
		'            case IDK:' \
		'                return no->kind.var.attr.name;' \
		'            case OPK:' \
		'                esquerda = gerarExpressao(no->child[0]);' \
		'                direita = gerarExpressao(no->child[1]);' \
		'                temp = novoTemporario();' \
		'                switch (no->op) {' \
		'                    case PLUS: operador = "+"; break;' \
		'                    case MINUS: operador = "-"; break;' \
		'                    case TIMES: operador = "*"; break;' \
		'                    case DIVIDE: operador = "/"; break;' \
		'                    case LT: operador = "<"; break;' \
		'                    case LE: operador = "<="; break;' \
		'                    case GT: operador = ">"; break;' \
		'                    case GE: operador = ">="; break;' \
		'                    case EQ: operador = "=="; break;' \
		'                    case NE: operador = "!="; break;' \
		'                    default: operador = "?"; break;' \
		'                }' \
		'                printf("%s = %s %s %s\n", temp, esquerda, operador, direita);' \
		'                return temp;' \
		'            case CALLK: {' \
		'                TreeNode* argumento = no->child[0];' \
		'                int numArgumentos = 0;' \
		'                while (argumento != NULL) {' \
		'                    char* tempArg = gerarExpressao(argumento);' \
		'                    printf("param %s\n", tempArg);' \
		'                    numArgumentos++; argumento = argumento->sibling;' \
		'                }' \
		'                temp = novoTemporario();' \
		'                printf("%s = call %s, %d\n", temp, no->kind.var.attr.name, numArgumentos);' \
		'                return temp;' \
		'            }' \
		'            case ASSIGNK: return NULL;' \
		'            default: return NULL;' \
		'        }' \
		'    } else if (no->nodekind == VARK) {' \
		'        if (no->kind.var.varKind == KIND_ARRAY && no->child[0] != NULL) {' \
		'            char* indice = gerarExpressao(no->child[0]);' \
		'            temp = novoTemporario();' \
		'            printf("%s = %s[%s]\n", temp, no->kind.var.attr.name, indice);' \
		'            return temp;' \
		'        } else { return no->kind.var.attr.name; }' \
		'    }' \
		'    return NULL;' \
		'}' \
		'' >> $(CODEGEN_SRC)
	@printf '%s\n' \
		'static void gerarComando(TreeNode* no) {' \
		'    char* teste; char* labelFalso; char* labelFim; char* labelInicio; char* valor;' \
		'    if (no == NULL) return;' \
		'    if (no->nodekind == STMTK) {' \
		'        switch (no->kind.stmt) {' \
		'            case IFK:' \
		'                teste = gerarExpressao(no->child[0]);' \
		'                labelFalso = novoLabel(); labelFim = novoLabel();' \
		'                printf("if_false %s goto %s\n", teste, labelFalso);' \
		'                gerarComando(no->child[1]);' \
		'                if (no->child[2] != NULL) {' \
		'                    printf("goto %s\n", labelFim);' \
		'                    printf("%s:\n", labelFalso);' \
		'                    gerarComando(no->child[2]);' \
		'                    printf("%s:\n", labelFim);' \
		'                } else { printf("%s:\n", labelFalso); }' \
		'                break;' \
		'            case WHILEK:' \
		'                labelInicio = novoLabel(); labelFim = novoLabel();' \
		'                printf("%s:\n", labelInicio);' \
		'                teste = gerarExpressao(no->child[0]);' \
		'                printf("if_false %s goto %s\n", teste, labelFim);' \
		'                gerarComando(no->child[1]);' \
		'                printf("goto %s\n", labelInicio);' \
		'                printf("%s:\n", labelFim);' \
		'                break;' \
		'            case RETURNK:' \
		'                if (no->child[0] != NULL) {' \
		'                    valor = gerarExpressao(no->child[0]);' \
		'                    printf("return %s\n", valor);' \
		'                } else { printf("return\n"); }' \
		'                break;' \
		'            case COMPK:' \
		'                if (no->child[0] != NULL) {' \
		'                    TreeNode* declaracao = no->child[0];' \
		'                    while (declaracao != NULL) {' \
		'                        gerarComando(declaracao);' \
		'                        declaracao = declaracao->sibling;' \
		'                    }' \
		'                }' \
		'                if (no->child[1] != NULL) {' \
		'                    TreeNode* comando = no->child[1];' \
		'                    while (comando != NULL) {' \
		'                        if (comando->nodekind == STMTK) gerarComando(comando);' \
		'                        else if (comando->nodekind == EXPK) gerarComandoExpressao(comando);' \
		'                        comando = comando->sibling;' \
		'                    }' \
		'                }' \
		'                break;' \
		'            case INTEGERK:' \
		'            case VOIDK:' \
		'                if (no->child[0] != NULL && no->child[0]->nodekind == VARK) {' \
		'                    TreeNode* noIdentificador = no->child[0];' \
		'                    if (noIdentificador->kind.var.varKind == KIND_FUNC) {' \
		'                        printf("\nfunc %s:\n", noIdentificador->kind.var.attr.name);' \
		'                        if (noIdentificador->child[0] != NULL) {' \
		'                            TreeNode* parametro = noIdentificador->child[0];' \
		'                            while (parametro != NULL) {' \
		'                                if (parametro->nodekind == STMTK && parametro->child[0] != NULL)' \
		'                                    printf("param %s\n", parametro->child[0]->kind.var.attr.name);' \
		'                                parametro = parametro->sibling;' \
		'                            }' \
		'                        }' \
		'                        if (noIdentificador->child[1] != NULL)' \
		'                            gerarComando(noIdentificador->child[1]);' \
		'                        printf("endfunc\n");' \
		'                    } else if (noIdentificador->kind.var.varKind == KIND_ARRAY && noIdentificador->kind.var.acesso == DECLK) {' \
		'                        if (noIdentificador->child[0] != NULL)' \
		'                            printf("array %s[%d]\n", noIdentificador->kind.var.attr.name, noIdentificador->child[0]->kind.var.attr.val);' \
		'                    }' \
		'                }' \
		'                break;' \
		'            default: break;' \
		'        }' \
		'    } else if (no->nodekind == EXPK) { gerarComandoExpressao(no); }' \
		'}' \
		'' >> $(CODEGEN_SRC)
	@printf '%s\n' \
		'static void gerarComandoExpressao(TreeNode* no) {' \
		'    char* valor;' \
		'    if (no == NULL) return;' \
		'    if (no->nodekind == EXPK) {' \
		'        switch (no->kind.exp) {' \
		'            case ASSIGNK:' \
		'                if (no->child[0] != NULL && no->child[1] != NULL) {' \
		'                    valor = gerarExpressao(no->child[1]);' \
		'                    if (no->child[0]->nodekind == VARK) {' \
		'                        if (no->child[0]->kind.var.varKind == KIND_ARRAY && no->child[0]->child[0] != NULL) {' \
		'                            char* indice = gerarExpressao(no->child[0]->child[0]);' \
		'                            printf("%s[%s] = %s\n", no->child[0]->kind.var.attr.name, indice, valor);' \
		'                        } else { printf("%s = %s\n", no->child[0]->kind.var.attr.name, valor); }' \
		'                    }' \
		'                }' \
		'                break;' \
		'            case CALLK: {' \
		'                TreeNode* argumento = no->child[0];' \
		'                int numArgumentos = 0;' \
		'                while (argumento != NULL) {' \
		'                    char* tempArg = gerarExpressao(argumento);' \
		'                    printf("param %s\n", tempArg);' \
		'                    numArgumentos++; argumento = argumento->sibling;' \
		'                }' \
		'                printf("call %s, %d\n", no->kind.var.attr.name, numArgumentos);' \
		'            }' \
		'            break;' \
		'            default: break;' \
		'        }' \
		'    }' \
		'}' \
		'' >> $(CODEGEN_SRC)
	@printf '%s\n' \
		'static void percorrerArvore(TreeNode* no) {' \
		'    while (no != NULL) {' \
		'        if (no->nodekind == STMTK) gerarComando(no);' \
		'        else if (no->nodekind == EXPK) gerarComandoExpressao(no);' \
		'        no = no->sibling;' \
		'    }' \
		'}' \
		'' >> $(CODEGEN_SRC)
	@printf '%s\n' \
		'void codeGen(TreeNode* arvoreSintatica) {' \
		'    printf("\n*** CODIGO INTERMEDIARIO (3 ENDERECOS) ***\n\n");' \
		'    percorrerArvore(arvoreSintatica);' \
		'    printf("\n******************************************\n\n");' \
		'}' >> $(CODEGEN_SRC)
	@echo "$(CODEGEN_SRC) criado!"

# Gera o analisador léxico
$(LEX_GEN): $(LEX_SRC) $(YACC_GEN_H)
	$(LEX) $(LEX_SRC)

# Gera o analisador sintático/semântico
$(YACC_GEN_C) $(YACC_GEN_H): $(YACC_SRC)
	$(YACC) -d $(YACC_SRC) -o $(YACC_GEN_C)

# Compila parser_context.c
$(CONTEXT_OBJ): $(CONTEXT_SRC) $(CONTEXT_HDR)
	$(CC) $(CFLAGS) -c $(CONTEXT_SRC) -o $(CONTEXT_OBJ)

# Compila code_generator.c
$(CODEGEN_OBJ): $(CODEGEN_SRC) $(CODEGEN_HDR) $(YACC_GEN_H)
	@echo "Compilando gerador de código..."
	@echo "Fonte: $(CODEGEN_SRC)"
	@echo "Destino: $(CODEGEN_OBJ)"
	$(CC) $(CFLAGS) -c $(CODEGEN_SRC) -o $(CODEGEN_OBJ)
	@if [ -f $(CODEGEN_OBJ) ]; then \
		echo "$(CODEGEN_OBJ) criado com sucesso"; \
	else \
		echo "ERRO: Falha ao criar $(CODEGEN_OBJ)"; \
		exit 1; \
	fi

# Compila o analisador léxico
$(LEX_OBJ): $(LEX_GEN)
	$(CC) $(CFLAGS) -c $(LEX_GEN) -o $(LEX_OBJ)

# Compila o analisador sintático
$(YACC_OBJ): $(YACC_GEN_C) $(YACC_GEN_H) $(CONTEXT_HDR)
	$(CC) $(CFLAGS) -c $(YACC_GEN_C) -o $(YACC_OBJ)

# Compila o executável final
$(TARGET): $(LEX_OBJ) $(YACC_OBJ) $(CONTEXT_OBJ) $(CODEGEN_OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(LEX_OBJ) $(YACC_OBJ) $(CONTEXT_OBJ) $(CODEGEN_OBJ)

# Limpa arquivos gerados
clean:
	rm -f $(LEX_GEN) $(YACC_GEN_C) $(YACC_GEN_H) $(TARGET)
	rm -f $(CONTEXT_OBJ) $(CODEGEN_OBJ) $(YACC_OBJ) $(LEX_OBJ)
	rm -f *.exe *.o
	rm -f ast.dot ast_*.dot ast.png ast_*.png ast.svg ast_*.svg

# Limpa arquivos de contexto gerados automaticamente
distclean: clean
	@if [ -f $(CONTEXT_HDR) ]; then rm -f $(CONTEXT_HDR); fi
	@if [ -f $(CONTEXT_SRC) ]; then rm -f $(CONTEXT_SRC); fi
	@if [ -f $(CODEGEN_HDR) ]; then rm -f $(CODEGEN_HDR); fi
	@if [ -f $(CODEGEN_SRC) ]; then rm -f $(CODEGEN_SRC); fi

# Testa com um exemplo (crie um arquivo test.cm para testar)
test: $(TARGET)
	@echo "========================================="
	@echo "Testando o compilador C-Minus..."
	@echo "========================================="
	@if [ -f test.cm ]; then \
		./$(TARGET) test.cm; \
		echo ""; \
		if [ -f ast.dot ]; then \
			echo "Arquivo ast.dot gerado"; \
			echo "Use 'make view-ast' para visualizar a AST"; \
		fi; \
	else \
		echo "Arquivo test.cm não encontrado!"; \
		echo "Crie um arquivo test.cm com código C-Minus para testar."; \
	fi

# Visualiza a AST gerada
view-ast:
	@echo "========================================="
	@echo "Gerando visualização da AST..."
	@echo "========================================="
	@if [ ! -f ast.dot ]; then \
		echo "✗ Arquivo ast.dot não encontrado!"; \
		echo "  Execute primeiro: ./$(TARGET) arquivo.cm"; \
		exit 1; \
	fi
	@if ! command -v $(DOT) > /dev/null; then \
		echo "✗ GraphViz (dot) não encontrado!"; \
		echo "  Instale com: sudo apt-get install graphviz"; \
		exit 1; \
	fi
	@echo "Gerando ast.png..."
	@$(DOT) -Tpng ast.dot -o ast.png && echo "✓ ast.png gerado com sucesso"
	@echo "Gerando ast.svg..."
	@$(DOT) -Tsvg ast.dot -o ast.svg && echo "✓ ast.svg gerado com sucesso"
	@echo ""
	@echo "Arquivos gerados:"
	@echo "  - ast.png (imagem PNG)"
	@echo "  - ast.svg (imagem vetorial)"
	@echo ""
	@if command -v xdg-open > /dev/null 2>&1; then \
		echo "Abrindo ast.png..."; \
		xdg-open ast.png 2>/dev/null || echo "Não foi possível abrir automaticamente"; \
	elif command -v open > /dev/null 2>&1; then \
		echo "Abrindo ast.png..."; \
		open ast.png 2>/dev/null || echo "Não foi possível abrir automaticamente"; \
	else \
		echo "Abra manualmente: ast.png ou ast.svg"; \
	fi

# Compila e visualiza a AST em um único comando
run-and-view: $(TARGET)
	@if [ -z "$(FILE)" ]; then \
		echo "Uso: make run-and-view FILE=arquivo.cm"; \
		exit 1; \
	fi
	@echo "========================================="
	@echo "Compilando $(FILE)..."
	@echo "========================================="
	@./$(TARGET) $(FILE)
	@echo ""
	@$(MAKE) -s view-ast

# Testa com entrada padrão
test-stdin: $(TARGET)
	@echo "Digite o código C-Minus (Ctrl+D para finalizar):"
	./$(TARGET)

# Verifica se GraphViz está instalado
check-graphviz:
	@if command -v $(DOT) > /dev/null; then \
		echo "GraphViz instalado: $$($(DOT) -V 2>&1)"; \
	else \
		echo "GraphViz não encontrado"; \
		echo "Instale com:"; \
		echo "  Ubuntu/Debian: sudo apt-get install graphviz"; \
		echo "  Fedora: sudo dnf install graphviz"; \
		echo "  macOS: brew install graphviz"; \
	fi

# Recompila tudo do zero
rebuild: clean all

# Mostra informações sobre o projeto
info:
	@echo "========================================="
	@echo "  Compilador C-Minus - Informações"
	@echo "========================================="
	@echo "Arquivos fonte:"
	@echo "  Lexer:    $(LEX_SRC)"
	@echo "  Parser:   $(YACC_SRC)"
	@echo "  Contexto: $(CONTEXT_SRC), $(CONTEXT_HDR)"
	@echo "  CodeGen:  $(CODEGEN_SRC), $(CODEGEN_HDR)"
	@echo ""
	@echo "Ferramentas:"
	@echo "  Compilador C: $(CC)"
	@echo "  Flex:         $(LEX)"
	@echo "  Bison:        $(YACC)"
	@echo "  GraphViz:     $(DOT)"
	@echo ""
	@echo "Executável:    $(TARGET)"
	@echo ""
	@$(MAKE) -s check-graphviz

# Mostra ajuda
help:
	@echo "========================================="
	@echo "  Makefile para o compilador C-Minus"
	@echo "========================================="
	@echo ""
	@echo "Compilação:"
	@echo "  make              - Compila o compilador"
	@echo "  make rebuild      - Recompila tudo do zero"
	@echo "  make clean        - Remove arquivos gerados"
	@echo "  make distclean    - Remove tudo (incluindo arquivos de contexto)"
	@echo ""
	@echo "Testes:"
	@echo "  make test         - Testa com test.cm"
	@echo "  make test-stdin   - Testa com entrada padrão"
	@echo ""
	@echo "Visualização da AST:"
	@echo "  make view-ast                - Gera PNG/SVG do ast.dot existente"
	@echo "  make run-and-view FILE=x.cm  - Compila e visualiza em um único comando"
	@echo ""
	@echo "Utilitários:"
	@echo "  make info           - Mostra informações do projeto"
	@echo "  make check-graphviz - Verifica instalação do GraphViz"
	@echo "  make help           - Mostra esta mensagem"
	@echo ""
	@echo "Uso manual:"
	@echo "  ./$(TARGET) arquivo.cm              - Compila arquivo"
	@echo "  ./$(TARGET) < arquivo.cm            - Compila via stdin"
	@echo ""
	@echo "Exemplos:"
	@echo "  make                             - Compila o compilador"
	@echo "  make test                        - Testa exemplo simples"
	@echo "  make test-graphviz               - Gera visualização da AST"
	@echo "  make view-ast                    - Visualiza a AST gerada"
	@echo "  make run-and-view FILE=test.cm   - Faz tudo de uma vez"

# Declara alvos que não são arquivos
.PHONY: all clean distclean test test-stdin view-ast run-and-view \
        check-headers create-context-header create-context-source \
        create-codegen-header create-codegen-source \
        check-graphviz rebuild info help
