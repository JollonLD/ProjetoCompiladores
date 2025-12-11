#ifndef PARSER_CONTEXT_H
#define PARSER_CONTEXT_H

#include <stdio.h>

typedef struct treeNode TreeNode;
typedef struct Escopo Escopo;

typedef struct ParserContext {
    /* AST */
    TreeNode *ast_root;

    /* Tabela de símbolos */
    Escopo *escopo_atual;
    Escopo *lista_escopos;

    int has_errors;
} ParserContext;

ParserContext *parser_context_create();
void parser_context_destroy(ParserContext *ctx);

#endif