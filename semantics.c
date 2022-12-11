#include "semantics.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getToken(char *type)
{
	if (strcmp(type, "Assign") == 0)
		return "=";
	else if (strcmp(type, "Add") == 0 || strcmp(type, "Plus") == 0)
		return "+";
	else if (strcmp(type, "Minus") == 0 || strcmp(type, "Sub") == 0)
		return "-";
	else if (strcmp(type, "Mul") == 0)
		return "*";
	else if (strcmp(type, "Mod") == 0)
		return "%";
	else if (strcmp(type, "Div") == 0)
		return "/";
	else if (strcmp(type, "Ne") == 0)
		return "!=";
	else if (strcmp(type, "Lt") == 0)
		return "<";
	else if (strcmp(type, "Le") == 0)
		return "<=";
	else if (strcmp(type, "Gt") == 0)
		return ">";
	else if (strcmp(type, "Ge") == 0)
		return ">=";
	else if (strcmp(type, "Eq") == 0)
		return "==";
	else if (strcmp(type, "And") == 0)
		return "&&";
	else if (strcmp(type, "Or") == 0)
		return "||";
	else if (strcmp(type, "Not") == 0)
		return "!";
	else if (strcmp(type, "Print") == 0)
		return "System.out.print";
	else if (strcmp(type, "If") == 0)
		return "if";
	else if (strcmp(type, "While") == 0)
		return "while";
	else if (strcmp(type, "Return") == 0)
		return "return";
	else if (strcmp(type, "Length") == 0)
		return ".length";
	else if (strcmp(type, "ParseArgs") == 0)
		return "Integer.parseInt";
	else if (strcmp(type, "Xor") == 0)
		return "^";
	else
		return type;
}

void methodRecursive(ast_tree *node, symtab_line *method, bool isCall)
{

	char *type = node->type;
	int line = node->line, col = node->collum;

	bool call = 0, print = 0, returnBool = 0, logic = 0, comp = 0;
	bool length = 0, parseArgs = 0, mat = 0, ifStatement = 0, assign = 0;

	if (type == NULL)
	{

		if (node->brother != NULL)
		{
			methodRecursive(node->brother, method, isCall);
		}

		return;
	}

	//--------- INICIAR VARIAVEL LOCAL ----------
	if (strcmp(type, "VarDecl") == 0)
	{

		putVariableL(node, method);

		if (node->brother != NULL)
		{
			methodRecursive(node->brother, method, isCall);
		}

		return;
	}

	//---------- VERIFICAR SE VARIAVEL JA FOI DECLARADA ---------
	else if (strcmp(type, "Id") == 0)
	{

		if (!isCall)
		{
			node->type2 = inspectSymb(node, method);
		}
	}
	else if (strcmp(type, "DecLit") == 0)
	{

		node->type2 = "int";

		char *number = verifyNum(node->value);

		if ((strcmp(number, "2147483648") >= 0 && strlen(number) == strlen("2147483648")) || strlen(number) > strlen("2147483648"))
		{
			printf("Line %d, col %d: Number %s out of bounds\n", line, col, node->value);
		}
	}
	else if (strcmp(type, "RealLit") == 0)
	{

		node->type2 = "double";
	}
	else if (strcmp(type, "BoolLit") == 0)
	{

		node->type2 = "boolean";
	}
	else if (strcmp(type, "StrLit") == 0)
	{

		node->type2 = "String";
	}
	//----------- CHAMADA DE FUNCAO ---------
	else if (strcmp(type, "Call") == 0)
	{

		call = 1;

		isCall = 1;
	}
	else if (strcmp(type, "If") == 0 || strcmp(type, "While") == 0)
	{

		ifStatement = 1;
	}
	else if (strcmp(type, "Return") == 0)
	{

		returnBool = 1;
	}
	else if (strcmp(type, "Print") == 0)
	{

		print = 1;
	}
	else if (strcmp(type, "Length") == 0)
	{

		length = 1;
	}
	else if (strcmp(type, "ParseArgs") == 0)
	{

		parseArgs = 1;
	}
	else if (strcmp(type, "Lshift") == 0 || strcmp(type, "Rshift") == 0)
	{

		if (strcmp(node->son->brother->type, "DecLit") == 0)
		{
			node->type2 = "int";
			if (node->son != NULL)
				node->son->type2 = node->type2;
			if (node->son->brother != NULL)
				node->son->brother->type2 = node->type2;
		}
		else
		{
			node->type2 = "none";
		}
		if (node->brother != NULL)
		{
			methodRecursive(node->brother, method, isCall);
		}

		if(strcmp(node->type2, "none") == 0)
		{
			node->son->type2 = "none";
			node->son->brother->type2 = "none";
		}
			
		return;
	}


	else if (strcmp(type, "Assign") == 0)
	{

		assign = 1;
	}
	else if (strcmp(type, "Mul") == 0 || strcmp(type, "Add") == 0 || strcmp(type, "Sub") == 0 || strcmp(type, "Div") == 0 || strcmp(type, "Mod") == 0 || strcmp(type, "Plus") == 0 || strcmp(type, "Minus") == 0)
	{

		mat = 1;
	}
	else if (strcmp(type, "And") == 0 || strcmp(type, "Or") == 0 || strcmp(type, "Not") == 0 || strcmp(type, "Xor") == 0)
	{

		logic = 1;
	}
	else if (strcmp(type, "Ne") == 0 || strcmp(type, "Lt") == 0 || strcmp(type, "Le") == 0 || strcmp(type, "Gt") == 0 || strcmp(type, "Ge") == 0 || strcmp(type, "Eq") == 0)
	{

		comp = 1;
	}

	if (!call)
		isCall = 0;

	if (node->son != NULL)
	{
		methodRecursive(node->son, method, isCall);
	}

	isCall = 0;

	if (assign)
	{

		if (strcmp(node->son->type2, node->son->brother->type2) != 0 || (strcmp(node->son->type2, "undef") == 0) || (strcmp(node->son->brother->type2, "undef") == 0 || strcmp(node->son->type2, "none") == 0) || strcmp(node->son->type2, "none") == 0 || (strcmp(node->son->type2, "String[]") == 0) || (strcmp(node->son->brother->type2, "String[]") == 0))
		{
			if (!(strcmp(node->son->type2, "double") == 0 && strcmp(node->son->brother->type2, "int") == 0))
			{
				node->type2 = node->son->type2;
				printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", line, col, getToken(type), node->son->type2, node->son->brother->type2);
			}
			else
			{

				node->type2 = node->son->type2;
			}
		}
		else
		{

			node->type2 = node->son->type2;
		}
	}
	else if (mat)
	{
		if (node->son->brother != NULL)
		{
			if ((strcmp(node->son->type2, "int") != 0 && strcmp(node->son->type2, "double") != 0) || (strcmp(node->son->brother->type2, "int") != 0 && strcmp(node->son->brother->type2, "double") != 0))
			{

				node->type2 = "undef";

				printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", line, col, getToken(type), node->son->type2, node->son->brother->type2);
			}
			else
			{

				if (strcmp(node->son->type2, "double") == 0 || strcmp(node->son->brother->type2, "double") == 0)
					node->type2 = "double";
				else
					node->type2 = "int";
			}
		}
		else
		{
			if (strcmp(node->son->type2, "int") != 0 && strcmp(node->son->type2, "double") != 0)
			{

				node->type2 = "undef";

				printf("Line %d, col %d: Operator %s cannot be applied to type %s\n", line, col, getToken(type), node->son->type2);
			}
			else
			{

				if (strcmp(node->son->type2, "double") == 0)
					node->type2 = "double";
				else
					node->type2 = "int";
			}
		}
	}
	else if (logic || comp)
	{
		node->type2 = "boolean";
		int validar = 0;

		if (node->son->brother != NULL)
		{
			if(node == NULL) validar = 1;
			if (strcmp(node->type, "Xor") != 0) validar = 1; 
			if (node->son->type2 != NULL && validar == 0){
				if (strchr(node->son->value, '.') != NULL)
        	{
            	// É double
            	node->type2 = "undef";
            	printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", node->line, node->collum, getToken(node->type), node->son->type2, node->son->brother->type2);
        	}
        	else
        	{
            // Verificar se é int
            	if (strcmp(node->son->type2, "int") == 0 && strcmp(node->son->brother->type2, "int") == 0)
            	{
                	node->type2 = "int";
            	}
        	}
			}
				
			if (strcmp(node->son->type2, node->son->brother->type2) != 0 || (strcmp(node->son->type2, "undef") == 0) || (strcmp(node->son->brother->type2, "undef") == 0) || (strcmp(node->son->type2, "String[]") == 0) || (strcmp(node->son->brother->type2, "String[]") == 0))
			{
				if (!((strcmp(node->son->type2, "int") == 0 && strcmp(node->son->brother->type2, "double") == 0) || (strcmp(node->son->type2, "double") == 0 && strcmp(node->son->brother->type2, "int") == 0)))
				{
					printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", line, col, getToken(type), node->son->type2, node->son->brother->type2);
				}
				else if ((strcmp(node->son->type2, node->son->brother->type2) == 0) && (strcmp(node->son->type, "Id") == 0) && (strcmp(node->son->brother->type, "BoolLit") == 0) && (strcmp(node->type, "Eq") != 0) && (strcmp(node->type, "Ne") != 0))
            {
                printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", line, col, getToken(type), node->son->type2, node->son->brother->type2);
            }
			}
		}
		else
		{

			if (strcmp(node->son->type2, "boolean") != 0)
				printf("Line %d, col %d: Operator %s cannot be applied to type %s\n", line, col, getToken(type), node->son->type2);
		}
	}
	else if (call)
	{
		inspectCall(node, method);
	}
	else if (ifStatement)
	{

		if (strcmp(node->son->type2, "boolean") != 0)
			printf("Line %d, col %d: Incompatible type %s in %s statement\n", node->son->line, node->son->collum, node->son->type2, getToken(type));
	}
	else if (print)
	{

		if (node->son != NULL && (strcmp(node->son->type2, "undef") == 0 || strcmp(node->son->type2, "void") == 0 || strcmp(node->son->type2, "String[]") == 0))
			printf("Line %d, col %d: Incompatible type %s in %s statement\n", node->son->line, node->son->collum, node->son->type2, getToken(type));
	}
	else if (returnBool)
	{

		if (node->son != NULL)
		{
			if (strcmp(node->son->type2, method->type) != 0 || strcmp(node->son->type2, "undef") == 0 || strcmp(node->son->type2, "void") == 0)
			{
				if (!(strcmp(node->son->type2, "int") == 0 && strcmp(method->type, "double") == 0))
				{
					printf("Line %d, col %d: Incompatible type %s in %s statement\n", node->son->line, node->son->collum, node->son->type2, getToken(type));
				}
			}
		}
		else
		{
			if (strcmp(method->type, "void") != 0)
				printf("Line %d, col %d: Incompatible type void in %s statement\n", node->line, node->collum, getToken(type));
		}
	}
	else if (length)
	{
		node->type2 = "int";

		if (strcmp(node->son->type2, "String[]") != 0)
			printf("Line %d, col %d: Operator %s cannot be applied to type %s\n", node->line, node->collum, getToken(type), node->son->type2);
	}
	else if (parseArgs)
	{
		node->type2 = "int";

		if (strcmp(node->son->type2, "String[]") != 0 || strcmp(node->son->brother->type2, "int") != 0)
			printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", node->line, node->collum, getToken(type), node->son->type2, node->son->brother->type2);
	}

	if (node->brother != NULL)
		methodRecursive(node->brother, method, isCall);
}

void methodCreate(ast_tree *node)
{

	symtab_line *line =  generateLineAndHeaderMethod(node);

	putParam(node, line);
}

void programCheck(ast_tree *tree)
{

	ast_tree *tmp = tree;
	int count = 0;

	tmp = tmp->son;
	while (tmp != NULL)
	{

		if (tmp->type != NULL)
		{
			if (count == 0)
			{
				classCreate(tmp);
			}
			else if (strcmp(tmp->type, "FieldDecl") == 0)
			{
				generateVariableG(tmp);
			}
			else if (strcmp(tmp->type, "MethodDecl") == 0)
			{
				methodCreate(tmp);
			}

		}

		tmp = tmp->brother;
		count++;
	}

	tmp = tree->son;
	count = 1;
	while (tmp != NULL)
	{
		if (tmp->type != NULL)
		{
			if (strcmp(tmp->type, "MethodDecl") == 0 && tmp->valid)
			{
				methodRecursive(tmp->son->brother, obtainTableMethod(count), 0);
				count++;
			}
		}

		tmp = tmp->brother;
	}
}
