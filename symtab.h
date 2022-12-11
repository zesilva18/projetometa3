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

typedef struct tab{
	char* type;
	char* name;
	char* params;

	struct tab* brother;
	symtab_line* son;
	
}symbab_tab;

void classCreate(ast_tree* node);
symtab_line* generateLineAndHeaderMethod(ast_tree* node);
bool confirmMethod(char* name, char* paramTypes);

char* inspectSymb(ast_tree* node, symtab_line* method);
void inspectCall(ast_tree* node, symtab_line* method);
void inspectParamsMethod(ast_tree* node, char* params_call);

char* obtainTypeReturn(ast_tree* node);
char* obtainTypeParam(ast_tree* params);
symtab_line* obtainTableMethod(int k);

char* verifyNum(char* number);
char *scat(char *s,char *t);
void putParam(ast_tree* node, symtab_line* line);
char* changeType(char* type);

void generateVariableG(ast_tree* node);
void putVariableL(ast_tree* node, symtab_line* line);
bool checkVariableG(char* name);
bool checkVariableL(char* name, symtab_line* line);

void Table();



#endif