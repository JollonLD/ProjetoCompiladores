# Makefile para o compilador C-Minus
# Compilador C-Minus com análise léxica, sintática e semântica

CC = gcc
CFLAGS = -Wall -Wno-unused-function
LEX = flex
YACC = bison

# Arquivos fonte
LEX_SRC = cminusLex.l
YACC_SRC = cminusSintSem.y

# Arquivos gerados
LEX_GEN = lex.yy.c
YACC_GEN_C = cminus.tab.c
YACC_GEN_H = cminus.tab.h

# Executável final
TARGET = cminus

# Regra padrão: compila tudo
all: $(TARGET)

# Gera o analisador léxico
$(LEX_GEN): $(LEX_SRC) $(YACC_GEN_H)
	$(LEX) $(LEX_SRC)

# Gera o analisador sintático/semântico
$(YACC_GEN_C) $(YACC_GEN_H): $(YACC_SRC)
	$(YACC) -d $(YACC_SRC) -o $(YACC_GEN_C)

# Compila o executável final
$(TARGET): $(LEX_GEN) $(YACC_GEN_C)
	$(CC) $(CFLAGS) -o $(TARGET) $(YACC_GEN_C) $(LEX_GEN)

# Limpa arquivos gerados
clean:
	rm -f $(LEX_GEN) $(YACC_GEN_C) $(YACC_GEN_H) $(TARGET)
	rm -f *.exe *.o

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

# Testa com entrada padrão
test-stdin: $(TARGET)
	@echo "Digite o código C-Minus (Ctrl+D para finalizar):"
	./$(TARGET)

# Mostra ajuda
help:
	@echo "Makefile para o compilador C-Minus"
	@echo ""
	@echo "Uso:"
	@echo "  make          - Compila o compilador"
	@echo "  make clean    - Remove arquivos gerados"
	@echo "  make test     - Testa com o arquivo test.cm"
	@echo "  make test-stdin - Testa com entrada padrão"
	@echo "  make help     - Mostra esta mensagem"
	@echo ""
	@echo "Para testar manualmente:"
	@echo "  ./cminus arquivo.cm"
	@echo "  ./cminus < arquivo.cm"

.PHONY: all clean test test-stdin help
