#ifndef SEMANTICS_H
#define SEMANTICS_H

#include "symtab.h"
void check_program(ast_tree* tree);
void createMethod(ast_tree* node);
void recursiveMethod(ast_tree* node, symtab_line* method, bool isCall);
char* getToken(char* name);

extern symtab_header *symtab;

#endif