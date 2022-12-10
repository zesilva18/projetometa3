#include "symtab.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

extern symtab_header *symtab;

void createClass(ast_tree *node)
{

	symtab = (symtab_header *)malloc(sizeof(symtab_header));

	symtab->type = "Class";
	symtab->name = node->value;
}

symtab_line *createMethodLineAndHeader(ast_tree *node)
{

	char *name = node->son->son->brother->value;
	char *paramTypes = getParamTypes(node->son->son->brother->brother);
	char *type = convertType(node->son->son->type);

	int line = node->son->son->brother->line;
	int col = node->son->son->brother->collum;

	if (strcmp(name, "_") == 0)
		printf("Line %d, col %d: Symbol _ is reserved\n", line, col);

	//----------PRIMEIRO VERIFICAR SE O METODO JA EXISTE--------------

	if (verifyMethod(name, paramTypes))
	{

		//---------- CRIA LINHA DO METODO NA TABELA DA CLASS----------------

		symtab_line *class_line = (symtab_line *)malloc(sizeof(symtab_line));

		class_line->name = name;

		class_line->paramTypes = paramTypes;

		class_line->type = type;

		symtab_line *tmp = symtab->son;
		symtab_line *saveTmp;

		if (tmp == NULL)
		{
			symtab->son = class_line;
		}
		else
		{

			while (tmp != NULL)
			{
				saveTmp = tmp;

				tmp = tmp->brother;
			}

			saveTmp->brother = class_line;
		}

		//--------- CRIAR LINHA NA TABELA DO METODO------------

		symtab_line *method_line = (symtab_line *)malloc(sizeof(symtab_line));

		method_line->name = "return";

		method_line->type = type;

		//---------- CRIAR HEADER DA TABELA DO METODO----------

		symtab_header *header = (symtab_header *)malloc(sizeof(symtab_header));

		header->type = "Method";
		header->name = name;
		header->params = paramTypes;
		header->son = method_line;

		symtab_header *tmp_header = symtab->brother;

		symtab_header *saveTmp_header = symtab;

		while (tmp_header != NULL)
		{

			saveTmp_header = tmp_header;
			tmp_header = tmp_header->brother;
		}

		saveTmp_header->brother = header;

		node->valid = true;

		return method_line;
	}
	else
	{

		printf("Line %d, col %d: Symbol %s(%s) already defined\n", line, col, name, paramTypes);
		node->valid = false;
		return NULL;
	}
}

void createGlobalVariable(ast_tree *node)
{

	char *name = node->son->brother->value;
	char *type = convertType(node->son->type);

	int line = node->son->brother->line;
	int col = node->son->brother->collum;

	if (strcmp(name, "_") == 0)
	{
		printf("Line %d, col %d: Symbol _ is reserved\n", line, col);
		return;
	}

	if (verifyGlobalVariable(name))  //verificar se a name e paramTypes existem
	{

		symtab_line *line = (symtab_line *)malloc(sizeof(symtab_line));

		line->name = name;
		line->type = type;

		symtab_line *tmp = symtab->son;
		symtab_line *saveTmp;

		if (tmp == NULL)
		{
			symtab->son = line;
		}
		else
		{

			while (tmp != NULL)
			{
				saveTmp = tmp;

				tmp = tmp->brother;
			}

			saveTmp->brother = line;
		}
	}
	else
	{

		printf("Line %d, col %d: Symbol %s already defined\n", line, col, name); 
	}
}

void addParametros(ast_tree *node, symtab_line *line)
{

	char *name;
	char *type;
	int linesave;
	int col;

	//adicionar parametros a um no 

	ast_tree *tmp = node->son->son->brother->brother->son;

	if (line == NULL)
	{
		line = (symtab_line *)malloc(sizeof(symtab_line));
	}

	symtab_line *saveTmp = line;

	while (tmp != NULL)
	{

		name = tmp->son->brother->value;
		type = convertType(tmp->son->type);
		linesave = tmp->son->brother->line;
		col = tmp->son->brother->collum;

		if (strcmp(name, "_") == 0)
		{
			printf("Line %d, col %d: Symbol _ is reserved\n", linesave, col);
		}
		else
		{
			if (verifyLocalVariable(name, line))
			{
				symtab_line *param_line = (symtab_line *)malloc(sizeof(symtab_line));

				// Atribuir atributos a linha na tabela
				param_line->name = name;
				param_line->type = type;
				param_line->param = "param";

				saveTmp->brother = param_line;

				saveTmp = param_line;
			}
			else
			{

				printf("Line %d, col %d: Symbol %s already defined\n", linesave, col, name);
			}
		}

		tmp = tmp->brother;
	}
}

void addLocalVariable(ast_tree *node, symtab_line *line)
{

	char *name = node->son->brother->value;
	char *type = convertType(node->son->type);
	int linesave = node->son->brother->line;
	int col = node->son->brother->collum;

	if (strcmp(name, "_") == 0)
	{
		printf("Line %d, col %d: Symbol _ is reserved\n", linesave, col);
		return;
	}

	if (verifyLocalVariable(name, line))
	{

		symtab_line *param_line = (symtab_line *)malloc(sizeof(symtab_line));

		// Atribuir atributos a linha na tabela
		param_line->name = name;
		param_line->type = type;

		symtab_line *saveTmp = line;
		symtab_line *tmp = line->brother;

		while (tmp != NULL)
		{

			saveTmp = tmp;

			tmp = tmp->brother;
		}

		saveTmp->brother = param_line;
	}
	else
	{

		printf("Line %d, col %d: Symbol %s already defined\n", linesave, col, name);
	}
}

char *getParamTypes(ast_tree *params)
{

	char *string = "";
	int i = 0;

	ast_tree *tmp = params->son;

	while (tmp != NULL)
	{

		if (i == 0)
		{

			string = scat(string, convertType(tmp->son->type));
		}
		else
		{
			string = scat(string, ",");
			string = scat(string, convertType(tmp->son->type));
		}

		i++;
		tmp = tmp->brother;
	}

	return string;
}

char *convertType(char *type) //funcao para converter o tipo 
{

	if (strcmp(type, "StringArray") == 0)
	{
		return "String[]";
	}
	else if (strcmp(type, "Bool") == 0)
	{
		return "boolean";
	}
	else
	{
		char *string = (char *)malloc(strlen(type) + 1);
		char *tmp = type;
		int i = 0;
		for (; *tmp; ++tmp)
		{
			string[i] = tolower(*tmp); 
			i++;
		}
		return string;
	}
}

bool verifyGlobalVariable(char *name) //
{

	symtab_line *tmp = symtab->son;

	while (tmp != NULL)
	{

		if (strcmp(tmp->name, name) == 0 && tmp->paramTypes == NULL)
		{
			return false;
		}

		tmp = tmp->brother;
	}

	return true;
}

bool verifyLocalVariable(char *name, symtab_line *line)
{

	symtab_line *tmp = line->brother;

	while (tmp != NULL)
	{

		if (strcmp(tmp->name, name) == 0)
			return false;

		tmp = tmp->brother;
	}

	return true;
}

bool verifyMethod(char *name, char *paramTypes)
{

	symtab_line *tmp = symtab->son;

	while (tmp != NULL)
	{

		if (strcmp(tmp->name, name) == 0 && tmp->paramTypes != NULL && strcmp(tmp->paramTypes, paramTypes) == 0)
		{
			return false;
		}

		tmp = tmp->brother;
	}

	return true;
}

char *checkSymbol(ast_tree *node, symtab_line *method)
{

	char *param = node->value;
	int line = node->line;
	int col = node->collum;

	//Verificar as variaveis locais do metodo

	symtab_line *tmp = method->brother;

	while (tmp != NULL)
	{

		if (strcmp(tmp->name, param) == 0)
		{
			return tmp->type;
		}
		tmp = tmp->brother;
	}

	//--------AGORA VERIFICAR VARIAVEIS GLOBAIS-------

	tmp = symtab->son;

	while (tmp != NULL)
	{

		if (strcmp(tmp->name, param) == 0 && tmp->paramTypes == NULL)
		{
			return tmp->type;
		}

		tmp = tmp->brother;
	}

	printf("Line %d, col %d: Cannot find symbol %s\n", line, col, param);

	return "undef";
}

void checkCall(ast_tree *node, symtab_line *method)
{

	char *params = "";

	ast_tree *tmp = node->son->brother;

	int i = 0;

	while (tmp != NULL)
	{

		if (i == 0)
		{
			params = scat(params, tmp->type2);
		}
		else
		{
			params = scat(params, ",");
			params = scat(params, tmp->type2);
		}

		i++;

		tmp = tmp->brother;
	}

	checkMethodParams(node, params);
}

void checkMethodParams(ast_tree *node, char *params_call)
{

	char *name = node->son->value;

	char *final_params, *final_type;

	int checkFunc = 0;

	symtab_line *tmp = symtab->son;

	while (tmp != NULL && checkFunc < 2)
	{

		char *params_method = tmp->paramTypes;

		if (params_method != NULL && strcmp(tmp->name, name) == 0 && strcmp(tmp->paramTypes, params_call) == 0)
		{

			checkFunc++;

			final_params = (char *)malloc(strlen(params_call) + 1);
			strcpy(final_params, params_call);

			final_type = (char *)malloc(strlen(tmp->type) + 1);
			strcpy(final_type, tmp->type);
		}

		tmp = tmp->brother;
	}

	tmp = symtab->son;

	if (checkFunc == 0)  //casos para int e double
	{
		while (tmp != NULL && checkFunc < 2)
		{

			char *params_method = tmp->paramTypes;

			if (params_method != NULL && strcmp(tmp->type, name) == 0)
			{

				char *params = "";
				int i = 0;

				char *tmp_call = (char *)malloc(strlen(params_call) + 1);
				strcpy(tmp_call, params_call);

				char *tmp_method = (char *)malloc(strlen(params_method) + 1);
				strcpy(tmp_method, params_method);

				char *rest_call = tmp_call;
				char *rest_method = tmp_method;

				bool check = true;

				char *token_call = strtok_r(rest_call, ",", &rest_call);
				char *token_method = strtok_r(rest_method, ",", &rest_method);

				while (token_call != NULL)
				{

					if (token_method == NULL)
					{
						check = false;
						break;
					}

					if (strcmp(token_call, token_method) != 0 && !(strcmp(token_method, "double") == 0 && strcmp(token_call, "int") == 0))
					{
						check = false;
						break;
					}

					if (i == 0)
					{
						params = scat(params, token_method);
					}
					else
					{
						params = scat(params, ",");
						params = scat(params, token_method);
					}

					i++;

					token_call = strtok_r(rest_call, ",", &rest_call);
					token_method = strtok_r(rest_method, ",", &rest_method);
				}

				if (check && token_method == NULL)
				{

					checkFunc++;
					final_params = (char *)malloc(strlen(params_call) + 1);
					strcpy(final_params, params);

					final_type = (char *)malloc(strlen(tmp->type) + 1);
					strcpy(final_type, tmp->type);
				}
			}

			tmp = tmp->brother;
		}
	}

	if (checkFunc == 1)
	{
		node->type2 = final_type;

		node->son->paramtype = final_params;

		node->son->type2 = NULL;
	}
	else if (checkFunc == 0)
	{
		node->type2 = "undef";

		node->son->type2 = node->type2;

		printf("Line %d, col %d: Cannot find symbol %s(%s)\n", node->son->line, node->son->collum, node->son->value, params_call);
	}
	else
	{
		node->type2 = "undef";

		node->son->type2 = node->type2;

		printf("Line %d, col %d: Reference to method %s(%s) is ambiguous\n", node->son->line, node->son->collum, node->son->value, params_call);
	}

	return;
}

char *getReturnType(ast_tree *node)
{

	// char* name = node->son->param;
	char *paramTypes = node->son->paramtype;

	symtab_line *tmp = symtab->son;

	while (tmp != NULL)
	{

		if (tmp->paramTypes != NULL && strcmp(tmp->paramTypes, paramTypes) == 0)
			return tmp->type;

		tmp = tmp->brother;
	}

	return "undef";
}

symtab_line *getMethodTable(int k)
{

	symtab_header *tmp = symtab;

	int i;
	for (i = 0; i < k; i++)
	{
		if (strcmp(tmp->type, "FieldDecl") == 0)
			i--;

		tmp = tmp->brother;
	}

	return tmp->son;
}

char *checkNumber(char *number)
{

	char *tmp_number = (char *)malloc(strlen(number) + 1);
	strcpy(tmp_number, number);

	char *new_number = "";

	char *token = strtok(tmp_number, "_");

	while (token != NULL)
	{

		new_number = scat(new_number, token);

		token = strtok(NULL, "_");
	}

	return new_number;
}

char *scat(char *s, char *t)
{
	char *p = (char *)malloc(strlen(s) + strlen(t) + 1); /* 3: you will have to reserve memory to hold the copy. */
	int ptr = 0, temp = 0;								 /* 4 initialise some helpers */

	while (s[temp] != '\0')
	{ /* 5. use the temp to "walk" over string 1 */
		p[ptr++] = s[temp++];
	}
	temp = 0;
	while (t[temp] != '\0')
	{ /* and string two */
		p[ptr++] = t[temp++];
	}
	s = NULL;
	free(s);

	t = NULL;
	free(t);
	return p;
}

void printTable()
{

	symtab_header *tmp = symtab;

	while (tmp != NULL)
	{

		if (strcmp(tmp->type, "Class") == 0)
			printf("===== %s %s Symbol Table =====\n", tmp->type, tmp->name);
		else
			printf("\n===== %s %s(%s) Symbol Table =====\n", tmp->type, tmp->name, tmp->params);

		symtab_line *tmp_line = tmp->son;

		while (tmp_line != NULL)
		{

			if (strcmp(tmp_line->name, "return") == 0)
			{
				printf("%s\t\t%s\n", tmp_line->name, tmp_line->type);
			}
			else if (tmp_line->param != NULL)
			{
				printf("%s\t\t%s\t%s\n", tmp_line->name, tmp_line->type, tmp_line->param);
			}
			else if (tmp_line->paramTypes == NULL)
			{
				printf("%s\t\t%s\n", tmp_line->name, tmp_line->type);
			}
			else
			{
				printf("%s\t(%s)\t%s\n", tmp_line->name, tmp_line->paramTypes, tmp_line->type);
			}

			tmp_line = tmp_line->brother;
		}

		tmp = tmp->brother;
	}
	printf("\n");
}