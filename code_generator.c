/* code_generator.c */
#include "code_generator.h"
#include "cminus.tab.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int contadorTemporarios = 0;
static int contadorLabels = 0;

static char* gerarExpressao(TreeNode* no);
static void gerarComando(TreeNode* no);
static void gerarComandoExpressao(TreeNode* no);

static char* novoTemporario(void) {
    char* nomeTemp = (char*)malloc(10 * sizeof(char));
    sprintf(nomeTemp, "t%d", contadorTemporarios++);
    return nomeTemp;
}

static char* novoLabel(void) {
    char* nomeLabel = (char*)malloc(10 * sizeof(char));
    sprintf(nomeLabel, "L%d", contadorLabels++);
    return nomeLabel;
}

static char* gerarExpressao(TreeNode* no) {
    char* temp; char* esquerda; char* direita; char* operador;
    if (no == NULL) return NULL;
    if (no->nodekind == EXPK) {
        switch (no->kind.exp) {
            case CONSTK:
                temp = novoTemporario();
                printf("%s = %d\n", temp, no->kind.var.attr.val);
                return temp;
            case IDK:
                return no->kind.var.attr.name;
            case OPK:
                esquerda = gerarExpressao(no->child[0]);
                direita = gerarExpressao(no->child[1]);
                temp = novoTemporario();
                switch (no->op) {
                    case PLUS: operador = "+"; break;
                    case MINUS: operador = "-"; break;
                    case TIMES: operador = "*"; break;
                    case DIVIDE: operador = "/"; break;
                    case LT: operador = "<"; break;
                    case LE: operador = "<="; break;
                    case GT: operador = ">"; break;
                    case GE: operador = ">="; break;
                    case EQ: operador = "=="; break;
                    case NE: operador = "!="; break;
                    default: operador = "?"; break;
                }
                printf("%s = %s %s %s\n", temp, esquerda, operador, direita);
                return temp;
            case CALLK: {
                TreeNode* argumento = no->child[0];
                int numArgumentos = 0;
                while (argumento != NULL) {
                    char* tempArg = gerarExpressao(argumento);
                    printf("param %s\n", tempArg);
                    numArgumentos++; argumento = argumento->sibling;
                }
                temp = novoTemporario();
                printf("%s = call %s, %d\n", temp, no->kind.var.attr.name, numArgumentos);
                return temp;
            }
            case ASSIGNK: return NULL;
            default: return NULL;
        }
    } else if (no->nodekind == VARK) {
        if (no->kind.var.varKind == KIND_ARRAY && no->child[0] != NULL) {
            char* indice = gerarExpressao(no->child[0]);
            temp = novoTemporario();
            printf("%s = %s[%s]\n", temp, no->kind.var.attr.name, indice);
            return temp;
        } else { return no->kind.var.attr.name; }
    }
    return NULL;
}

static void gerarComando(TreeNode* no) {
    char* teste; char* labelFalso; char* labelFim; char* labelInicio; char* valor;
    if (no == NULL) return;
    if (no->nodekind == STMTK) {
        switch (no->kind.stmt) {
            case IFK:
                teste = gerarExpressao(no->child[0]);
                labelFalso = novoLabel(); labelFim = novoLabel();
                printf("if_false %s goto %s\n", teste, labelFalso);
                gerarComando(no->child[1]);
                if (no->child[2] != NULL) {
                    printf("goto %s\n", labelFim);
                    printf("%s:\n", labelFalso);
                    gerarComando(no->child[2]);
                    printf("%s:\n", labelFim);
                } else { printf("%s:\n", labelFalso); }
                break;
            case WHILEK:
                labelInicio = novoLabel(); labelFim = novoLabel();
                printf("%s:\n", labelInicio);
                teste = gerarExpressao(no->child[0]);
                printf("if_false %s goto %s\n", teste, labelFim);
                gerarComando(no->child[1]);
                printf("goto %s\n", labelInicio);
                printf("%s:\n", labelFim);
                break;
            case RETURNK:
                if (no->child[0] != NULL) {
                    valor = gerarExpressao(no->child[0]);
                    printf("return %s\n", valor);
                } else { printf("return\n"); }
                break;
            case COMPK:
                if (no->child[0] != NULL) {
                    TreeNode* declaracao = no->child[0];
                    while (declaracao != NULL) {
                        gerarComando(declaracao);
                        declaracao = declaracao->sibling;
                    }
                }
                if (no->child[1] != NULL) {
                    TreeNode* comando = no->child[1];
                    while (comando != NULL) {
                        if (comando->nodekind == STMTK) gerarComando(comando);
                        else if (comando->nodekind == EXPK) gerarComandoExpressao(comando);
                        comando = comando->sibling;
                    }
                }
                break;
            case INTEGERK:
            case VOIDK:
                if (no->child[0] != NULL && no->child[0]->nodekind == VARK) {
                    TreeNode* noIdentificador = no->child[0];
                    if (noIdentificador->kind.var.varKind == KIND_FUNC) {
                        printf("\nfunc %s:\n", noIdentificador->kind.var.attr.name);
                        if (noIdentificador->child[0] != NULL) {
                            TreeNode* parametro = noIdentificador->child[0];
                            while (parametro != NULL) {
                                if (parametro->nodekind == STMTK && parametro->child[0] != NULL)
                                    printf("param %s\n", parametro->child[0]->kind.var.attr.name);
                                parametro = parametro->sibling;
                            }
                        }
                        if (noIdentificador->child[1] != NULL)
                            gerarComando(noIdentificador->child[1]);
                        printf("endfunc\n");
                    } else if (noIdentificador->kind.var.varKind == KIND_ARRAY && noIdentificador->kind.var.acesso == DECLK) {
                        if (noIdentificador->child[0] != NULL)
                            printf("array %s[%d]\n", noIdentificador->kind.var.attr.name, noIdentificador->child[0]->kind.var.attr.val);
                    }
                }
                break;
            default: break;
        }
    } else if (no->nodekind == EXPK) { gerarComandoExpressao(no); }
}

static void gerarComandoExpressao(TreeNode* no) {
    char* valor;
    if (no == NULL) return;
    if (no->nodekind == EXPK) {
        switch (no->kind.exp) {
            case ASSIGNK:
                if (no->child[0] != NULL && no->child[1] != NULL) {
                    valor = gerarExpressao(no->child[1]);
                    if (no->child[0]->nodekind == VARK) {
                        if (no->child[0]->kind.var.varKind == KIND_ARRAY && no->child[0]->child[0] != NULL) {
                            char* indice = gerarExpressao(no->child[0]->child[0]);
                            printf("%s[%s] = %s\n", no->child[0]->kind.var.attr.name, indice, valor);
                        } else { printf("%s = %s\n", no->child[0]->kind.var.attr.name, valor); }
                    }
                }
                break;
            case CALLK: {
                TreeNode* argumento = no->child[0];
                int numArgumentos = 0;
                while (argumento != NULL) {
                    char* tempArg = gerarExpressao(argumento);
                    printf("param %s\n", tempArg);
                    numArgumentos++; argumento = argumento->sibling;
                }
                printf("call %s, %d\n", no->kind.var.attr.name, numArgumentos);
            }
            break;
            default: break;
        }
    }
}

static void percorrerArvore(TreeNode* no) {
    while (no != NULL) {
        if (no->nodekind == STMTK) gerarComando(no);
        else if (no->nodekind == EXPK) gerarComandoExpressao(no);
        no = no->sibling;
    }
}

void codeGen(TreeNode* arvoreSintatica) {
    printf("\n*** CODIGO INTERMEDIARIO (3 ENDERECOS) ***\n\n");
    percorrerArvore(arvoreSintatica);
    printf("\n******************************************\n\n");
}
