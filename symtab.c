#include "symtab.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

extern symbab_tab *symtab;

void classCreate(ast_tree *node)
{

	symtab = (symbab_tab *)malloc(sizeof(symbab_tab));

	symtab->type = "Class";
	symtab->name = node->value;
}

symtab_line * generateLineAndHeaderMethod(ast_tree *node)
{

	char *name = node->son->son->brother->value;
	char *paramTypes = obtainTypeParam(node->son->son->brother->brother);
	char *type = changeType(node->son->son->type);

	int line = node->son->son->brother->line;
	int col = node->son->son->brother->collum;

	if (strcmp(name, "_") == 0)
		printf("Line %d, col %d: Symbol _ is reserved\n", line, col);

	//----------PRIMEIRO VERIFICAR SE O METODO JA EXISTE

	if (confirmMethod(name, paramTypes))
	{

		//---------- CRIA LINHA DO METODO NA TABELA DA CLASS

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

		symbab_tab *tab = (symbab_tab *)malloc(sizeof(symbab_tab));

		tab->type = "Method";
		tab->name = name;
		tab->params = paramTypes;
		tab->son = method_line;

		symbab_tab *tmp_header = symtab->brother;

		symbab_tab *saveTmp_header = symtab;

		while (tmp_header != NULL)
		{

			saveTmp_header = tmp_header;
			tmp_header = tmp_header->brother;
		}

		saveTmp_header->brother = tab;

		node->valid = 1;

		return method_line;
	}
	else
	{

		printf("Line %d, col %d: Symbol %s(%s) already defined\n", line, col, name, paramTypes);
		node->valid = 0;
		return NULL;
	}
}

void putParam(ast_tree *node, symtab_line *line)
{

	char *name;
	char *type;
	int savLine;
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
		type = changeType(tmp->son->type);
		savLine = tmp->son->brother->line;
		col = tmp->son->brother->collum;

		if (strcmp(name, "_") == 0)
		{
			printf("Line %d, col %d: Symbol _ is reserved\n", savLine, col);
		}
		else
		{
			if (checkVariableL(name, line))
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

				printf("Line %d, col %d: Symbol %s already defined\n", savLine, col, name);
			}
		}

		tmp = tmp->brother;
	}
}

void putVariableL(ast_tree *node, symtab_line *line)
{

	char *name = node->son->brother->value;
	char *type = changeType(node->son->type);
	int savLine = node->son->brother->line;
	int col = node->son->brother->collum;

	if (strcmp(name, "_") == 0)
	{
		printf("Line %d, col %d: Symbol _ is reserved\n", savLine, col);
		return;
	}

	if (checkVariableL(name, line))
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

		printf("Line %d, col %d: Symbol %s already defined\n", savLine, col, name);
	}
}

char *obtainTypeParam(ast_tree *params)
{

	char *string = "";
	int count = 0;

	ast_tree *tmp = params->son;

	while (tmp != NULL)
	{

		if (count == 0)
		{

			string = scat(string, changeType(tmp->son->type));
		}
		else
		{
			string = scat(string, ",");
			string = scat(string, changeType(tmp->son->type));
		}

		count++;
		tmp = tmp->brother;
	}

	return string;
}

char *changeType(char *type) //funcao para converter o tipo 
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
		int count = 0;
		for (; *tmp; ++tmp)
		{
			string[count] = tolower(*tmp); 
			count++;
		}
		return string;
	}
}

void generateVariableG(ast_tree *node)
{

	char *name = node->son->brother->value;
	char *type = changeType(node->son->type);

	int line = node->son->brother->line;
	int col = node->son->brother->collum;

	if (strcmp(name, "_") == 0)
	{
		printf("Line %d, col %d: Symbol _ is reserved\n", line, col);
		return;
	}

	if (checkVariableG(name))  //verificar se a name e paramTypes existem
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

bool checkVariableG(char *name) //
{

	symtab_line *tmp = symtab->son;

	while (tmp != NULL)
	{

		if (strcmp(tmp->name, name) == 0 && tmp->paramTypes == NULL)
		{
			return 0;
		}

		tmp = tmp->brother;
	}

	return 1;
}

bool checkVariableL(char *name, symtab_line *line)
{

	symtab_line *tmp = line->brother;

	while (tmp != NULL)
	{

		if (strcmp(tmp->name, name) == 0)
			return 0;

		tmp = tmp->brother;
	}

	return 1;
}

bool confirmMethod(char *name, char *paramTypes)
{

	symtab_line *tmp = symtab->son;

	while (tmp != NULL)
	{

		if (strcmp(tmp->name, name) == 0 && tmp->paramTypes != NULL && strcmp(tmp->paramTypes, paramTypes) == 0)
		{
			return 0;
		}

		tmp = tmp->brother;
	}

	return 1;
}

char *inspectSymb(ast_tree *node, symtab_line *method)
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

void inspectCall(ast_tree *node, symtab_line *method)
{

	char *params = "";

	ast_tree *tmp = node->son->brother;

	int count = 0;

	while (tmp != NULL)
	{

		if (count == 0)
		{
			params = scat(params, tmp->type2);
		}
		else
		{
			params = scat(params, ",");
			params = scat(params, tmp->type2);
		}

		count++;

		tmp = tmp->brother;
	}

	inspectParamsMethod(node, params);
}

void inspectParamsMethod(ast_tree *node, char *params_call)
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
				int count = 0;

				char *tmp_call = (char *)malloc(strlen(params_call) + 1);
				strcpy(tmp_call, params_call);

				char *tmp_method = (char *)malloc(strlen(params_method) + 1);
				strcpy(tmp_method, params_method);

				char *rest_call = tmp_call;
				char *rest_method = tmp_method;

				bool vf = 1;

				char *token_call = strtok_r(rest_call, ",", &rest_call);
				char *token_method = strtok_r(rest_method, ",", &rest_method);

				while (token_call != NULL)
				{

					if (token_method == NULL)
					{
						vf = 0;
						break;
					}

					if (strcmp(token_call, token_method) != 0 && !(strcmp(token_method, "double") == 0 && strcmp(token_call, "int") == 0))
					{
						vf = 0;
						break;
					}

					if (count == 0)
					{
						params = scat(params, token_method);
					}
					else
					{
						params = scat(params, ",");
						params = scat(params, token_method);
					}

					count++;

					token_call = strtok_r(rest_call, ",", &rest_call);
					token_method = strtok_r(rest_method, ",", &rest_method);
				}

				if (vf && token_method == NULL)
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

char *obtainTypeReturn(ast_tree *node)
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

symtab_line *obtainTableMethod(int k)
{

	symbab_tab *tmp = symtab;

	int count;
	for (count = 0; count < k; count++)
	{
		if (strcmp(tmp->type, "FieldDecl") == 0)
			count--;

		tmp = tmp->brother;
	}

	return tmp->son;
}

char *verifyNum(char *number)
{

	char *tmp_number = (char *)malloc(strlen(number) + 1);
	strcpy(tmp_number, number);

	char *numNew = "";

	char *token = strtok(tmp_number, "_");

	while (token != NULL)
	{

		numNew = scat(numNew, token);

		token = strtok(NULL, "_");
	}

	return numNew;
}

char *scat(char *s, char *t)
{
	char *pont = (char *)malloc(strlen(s) + strlen(t) + 1); /* 3: you will have to reserve memory to hold the copy. */
	int ptr = 0, temp = 0;								 /* 4 initialise some helpers */

	while (s[temp] != '\0')
	{ /* 5. use the temp to "walk" over string 1 */
		pont[ptr++] = s[temp++];
	}
	temp = 0;
	while (t[temp] != '\0')
	{ /* and string two */
		pont[ptr++] = t[temp++];
	}
	s = NULL;
	free(s);

	t = NULL;
	free(t);
	return pont;
}

void Table()
{

	symbab_tab *tmp = symtab;

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