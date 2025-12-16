#ifndef CGEN_H
#define CGEN_H

#include "parser_context.h"

/* Forward declaration */
typedef struct treeNode TreeNode;

/* Função principal de geração de código intermediário */
void codeGen(TreeNode* syntaxTree);

#endif
