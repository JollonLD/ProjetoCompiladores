/* parser_context.h - Contexto do Parser */
#ifndef PARSER_CONTEXT_H
#define PARSER_CONTEXT_H

#include <stdio.h>

/* Declarações */
struct treeNode;
struct Escopo;

typedef struct ParserContext {
    struct treeNode *ast_root;
    struct Escopo *escopo_atual;
    struct Escopo *lista_escopos;
    int has_errors;
} ParserContext;

ParserContext* parser_context_create(void);
void parser_context_destroy(ParserContext *ctx);

#endif /* PARSER_CONTEXT_H */
