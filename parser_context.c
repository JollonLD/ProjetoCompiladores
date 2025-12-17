#include "parser_context.h"
#include <stdlib.h>

ParserContext* parser_context_create(void) {
    ParserContext *ctx = (ParserContext*)malloc(sizeof(ParserContext));
    if (!ctx) return NULL;
    ctx->ast_root = NULL;
    ctx->escopo_atual = NULL;
    ctx->lista_escopos = NULL;
    ctx->has_errors = 0;
    return ctx;
}

void parser_context_destroy(ParserContext *ctx) {
    if (!ctx) return;
    free(ctx);
}
