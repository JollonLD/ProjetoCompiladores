# Compilador C-Minus

Compilador para a linguagem C-Minus com análise léxica, sintática e semântica.

## Requisitos

- GCC (compilador C)
- Flex (analisador léxico)
- Bison (analisador sintático)

### Instalação no Windows

Você pode usar MinGW ou WSL:

**MinGW:**
```bash
# Instale o MinGW e adicione ao PATH
# Baixe em: https://sourceforge.net/projects/mingw/
```

**WSL (recomendado):**
```bash
sudo apt-get update
sudo apt-get install gcc flex bison make
```

### Instalação no Linux/Mac

```bash
# Ubuntu/Debian
sudo apt-get install gcc flex bison make

# Fedora
sudo dnf install gcc flex bison make

# Mac
brew install gcc flex bison make
```

## Compilação

Para compilar o compilador C-Minus:

```bash
make
```

Isso irá gerar o executável `cminus` (ou `cminus.exe` no Windows).

## Uso

### Analisar um arquivo

```bash
./cminus arquivo.cm
```

ou no Windows:

```bash
cminus.exe arquivo.cm
```

### Testar com entrada padrão

```bash
./cminus < arquivo.cm
```

ou interativamente:

```bash
./cminus
# Digite o código e pressione Ctrl+D (Linux/Mac) ou Ctrl+Z (Windows)
```

## Testes

### Teste com arquivo de exemplo

```bash
make test
```

Este comando testa o compilador com o arquivo `test.cm`.

### Teste interativo

```bash
make test-stdin
```

## Arquivos de Teste Incluídos

- `test.cm` - Programa correto (cálculo do MDC)
- `test_errors.cm` - Programa com erros semânticos para teste

### Testar com arquivo de erros

```bash
./cminus test_errors.cm
```

Este comando mostrará os erros semânticos detectados.

## Limpeza

Para remover os arquivos gerados:

```bash
make clean
```

## Estrutura do Projeto

- `cminusLex.l` - Especificação do analisador léxico (Flex)
- `cminusSintSem.y` - Especificação do analisador sintático/semântico (Bison)
- `Makefile` - Script de compilação
- `test.cm` - Arquivo de teste correto
- `test_errors.cm` - Arquivo de teste com erros

## Análises Implementadas

### Análise Léxica
- Reconhecimento de palavras-chave (if, else, while, return, int, void)
- Identificadores e números
- Operadores relacionais, aritméticos e de atribuição
- Comentários de linha (`//`) e bloco (`/* */`)

### Análise Sintática
- Declarações de variáveis e funções
- Expressões aritméticas e relacionais
- Estruturas de controle (if, if-else, while)
- Arrays e chamadas de função

### Análise Semântica
- Verificação de declaração de variáveis
- Verificação de tipos
- Detecção de redeclaração
- Verificação de uso correto de arrays
- Verificação de tipos em expressões e atribuições
- Escopo de variáveis (global e local)

## Exemplos de Uso

### Programa Correto

```c
/* Cálculo do MDC */
int gcd(int u, int v) {
    if (v == 0) return u;
    else return gcd(v, u - u / v * v);
}

int main(void) {
    int x;
    int y;
    x = 48;
    y = 18;
    return gcd(x, y);
}
```

Saída:
```
Análise sintática concluída com sucesso!
Análise semântica: Nenhum erro encontrado.
```

### Programa com Erros

```c
int main(void) {
    void x;      /* Erro: variável não pode ser void */
    z = 10;      /* Erro: z não declarado */
}
```

Saída:
```
Erro sintático linha 2: syntax error
Erro semântico linha 3: variável 'z' não declarada
```

## Ajuda

Para ver as opções do Makefile:

```bash
make help
```
