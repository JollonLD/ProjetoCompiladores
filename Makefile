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

# Arquivos gerados
LEX_GEN = lex.yy.c
YACC_GEN_C = cminus.tab.c
YACC_GEN_H = cminus.tab.h

# Arquivos objeto
CONTEXT_OBJ = parser_context.o
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

# Cria o arquivo parser_context.h se não existir
create-context-header:
	@echo "/* parser_context.h - Contexto do Parser */" > $(CONTEXT_HDR)
	@echo "#ifndef PARSER_CONTEXT_H" >> $(CONTEXT_HDR)
	@echo "#define PARSER_CONTEXT_H" >> $(CONTEXT_HDR)
	@echo "" >> $(CONTEXT_HDR)
	@echo "#include <stdio.h>" >> $(CONTEXT_HDR)
	@echo "" >> $(CONTEXT_HDR)
	@echo "/* Declarações */" >> $(CONTEXT_HDR)
	@echo "struct TreeNode;" >> $(CONTEXT_HDR)
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

# Gera o analisador léxico
$(LEX_GEN): $(LEX_SRC) $(YACC_GEN_H)
	$(LEX) $(LEX_SRC)

# Gera o analisador sintático/semântico
$(YACC_GEN_C) $(YACC_GEN_H): $(YACC_SRC)
	$(YACC) -d $(YACC_SRC) -o $(YACC_GEN_C)

# Compila parser_context.c
$(CONTEXT_OBJ): $(CONTEXT_SRC) $(CONTEXT_HDR)
	$(CC) $(CFLAGS) -c $(CONTEXT_SRC) -o $(CONTEXT_OBJ)

# Compila o analisador léxico
$(LEX_OBJ): $(LEX_GEN)
	$(CC) $(CFLAGS) -c $(LEX_GEN) -o $(LEX_OBJ)

# Compila o analisador sintático
$(YACC_OBJ): $(YACC_GEN_C) $(YACC_GEN_H) $(CONTEXT_HDR)
	$(CC) $(CFLAGS) -c $(YACC_GEN_C) -o $(YACC_OBJ)

# Compila o executável final
$(TARGET): $(LEX_OBJ) $(YACC_OBJ) $(CONTEXT_OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(LEX_OBJ) $(YACC_OBJ) $(CONTEXT_OBJ)

# Limpa arquivos gerados
clean:
	rm -f $(LEX_GEN) $(YACC_GEN_C) $(YACC_GEN_H) $(TARGET)
	rm -f $(CONTEXT_OBJ) $(YACC_OBJ) $(LEX_OBJ)
	rm -f *.exe *.o
	rm -f ast.dot ast_*.dot ast.png ast_*.png ast.svg ast_*.svg

# Limpa arquivos de contexto gerados automaticamente
distclean: clean
	@if [ -f $(CONTEXT_HDR) ]; then \
		rm -f $(CONTEXT_HDR); \
	fi
	@if [ -f $(CONTEXT_SRC) ]; then \
		rm -f $(CONTEXT_SRC); \
	fi

# Testa com um exemplo (crie um arquivo test.cm para testar)
test: $(TARGET)
	@echo "========================================="
	@echo "Testando o compilador C-Minus..."
	@echo "========================================="
	@if [ -f test.cm ]; then \
		./$(TARGET) test.cm; \
	else \
		echo "Arquivo test.cm não encontrado!"; \
		echo "Crie um arquivo test.cm com código C-Minus para testar."; \
	fi

# Testa e gera visualização GraphViz
test-graphviz: $(TARGET) test
	@echo "========================================="
	@echo "Testando com geração de visualização..."
	@echo "========================================="
	@if ! command -v $(DOT) > /dev/null; then \
		echo "GraphViz (dot) não encontrado!"; \
		echo "Instale com: sudo apt-get install graphviz"; \
	fi
	@if [ -f test_simple.cm ]; then \
		echo "Teste: test_simple.cm"; \
		./$(TARGET) test_simple.cm; \
		if [ -f ast.dot ]; then \
			echo "Gerando imagem PNG..."; \
			$(DOT) -Tpng ast.dot -o ast.png 2>/dev/null && echo "ast.png gerado" || echo "Erro ao gerar PNG"; \
			echo "Gerando imagem SVG..."; \
			$(DOT) -Tsvg ast.dot -o ast.svg 2>/dev/null && echo "ast.svg gerado" || echo "Erro ao gerar SVG"; \
		fi \
	fi

# Testa com entrada padrão
test-stdin: $(TARGET)
	@echo "Digite o código C-Minus (Ctrl+D para finalizar):"
	./$(TARGET)

# Verifica se GraphViz está instalado
check-graphviz:
	@if command -v $(DOT) > /dev/null; then \
		echo "$(GREEN)✓ GraphViz instalado: $$($(DOT) -V 2>&1)$(NC)"; \
	else \
		echo "$(RED)✗ GraphViz não encontrado$(NC)"; \
		echo "$(YELLOW)Instale com:$(NC)"; \
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
	@echo "  make test         - Testa com test_simple.cm"
	@echo "  make test-stdin   - Testa com entrada padrão"
	@echo "  make test-graphviz - Testa e gera visualização (PNG/SVG)"
	@echo ""
	@echo "Utilitários:"
	@echo "  make info         - Mostra informações do projeto"
	@echo "  make check-graphviz - Verifica instalação do GraphViz"
	@echo "  make help         - Mostra esta mensagem"
	@echo ""
	@echo "Uso manual:"
	@echo "  ./$(TARGET) arquivo.cm           - Compila arquivo"
	@echo "  ./$(TARGET) < arquivo.cm         - Compila via stdin"
	@echo ""
	@echo "Exemplos:"
	@echo "  make                             - Compila o compilador"
	@echo "  make test                        - Testa exemplo simples"
	@echo "  make test-graphviz               - Gera visualização da AST"

# Declara alvos que não são arquivos
.PHONY: all clean distclean test test-all test-stdin test-file test-graphviz \
        check-headers create-context-header create-context-source \
        create-tests check-graphviz rebuild info help
