#ifndef SEMANTICS_H
#define SEMANTICS_H

#include "symtab.h"
char* getToken(char* name);
void methodRecursive(ast_tree* node, symtab_line* method, bool isCall);
void methodCreate(ast_tree* node);
void programCheck(ast_tree* tree);
extern symbab_tab *symtab;
#endif