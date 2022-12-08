#ifndef SYMTAB_H
#define SYMTAB_H


#include "tree.h"
#include <stdbool.h>
typedef struct line{
	char* name;
	char* paramTypes;
	char* type;
	char* param;

	struct line* brother;

}symtab_line;




typedef struct header{
	char* type;
	char* name;
	char* params;

	struct header* brother;
	symtab_line* son;
	
}symtab_header;

void createClass(ast_tree* node);
symtab_line* createMethodLineAndHeader(ast_tree* node);
void createGlobalVariable(ast_tree* node);
void addParametros(ast_tree* node, symtab_line* line);
void addLocalVariable(ast_tree* node, symtab_line* line);
char* getParamTypes(ast_tree* params);
char* convertType(char* type);
bool verifyGlobalVariable(char* name);
bool verifyLocalVariable(char* name, symtab_line* line);
bool verifyMethod(char* name, char* paramTypes);
char* checkMethod(char* name, char* paramTypes);
char* checkSymbol(ast_tree* node, symtab_line* method);
void checkCall(ast_tree* node, symtab_line* method);
void checkMethodParams(ast_tree* node, char* params_call);
char* getReturnType(ast_tree* node);
symtab_line* getMethodTable(int k);
char* checkNumber(char* number);
char *scat(char *s,char *t);
void printSymbolTable();


#endif