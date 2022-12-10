#include "semantics.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void check_program(ast_tree *tree)
{

	ast_tree *tmp = tree;
	int i = 0;

	tmp = tmp->son;
	while (tmp != NULL)
	{

		if (tmp->type != NULL)
		{
			if (i == 0)
			{
				createClass(tmp);
			}
			else if (strcmp(tmp->type, "FieldDecl") == 0)
			{
				createGlobalVariable(tmp);
			}
			else if (strcmp(tmp->type, "MethodDecl") == 0)
			{
				createMethod(tmp);
			}

		}

		tmp = tmp->brother;
		i++;
	}

	tmp = tree->son;
	i = 1;
	while (tmp != NULL)
	{
		if (tmp->type != NULL)
		{
			if (strcmp(tmp->type, "MethodDecl") == 0 && tmp->valid)
			{
				recursiveMethod(tmp->son->brother, getMethodTable(i), false);
				i++;
			}
		}

		tmp = tmp->brother;
	}
}

void createMethod(ast_tree *node)
{

	symtab_line *line = createMethodLineAndHeader(node);

	addParametros(node, line);
}

void recursiveMethod(ast_tree *node, symtab_line *method, bool isCall)
{

	char *type = node->type;
	int line = node->line;
	int col = node->collum;

	bool call = false, print = false, returnBool = false, logic = false, comparation = false, length = false, parseArgs = false, maths = false, ifStatement = false, assign = false;

	if (type == NULL)
	{

		if (node->brother != NULL)
		{
			recursiveMethod(node->brother, method, isCall);
		}

		return;
	}

	//--------- INICIAR VARIAVEL LOCAL ----------
	if (strcmp(type, "VarDecl") == 0)
	{

		addLocalVariable(node, method);

		if (node->brother != NULL)
		{
			recursiveMethod(node->brother, method, isCall);
		}

		return;
	}

	//---------- VERIFICAR SE VARIAVEL JA FOI DECLARADA ---------
	else if (strcmp(type, "Id") == 0)
	{

		if (!isCall)
		{
			node->type2 = checkSymbol(node, method);
		}
	}
	else if (strcmp(type, "DecLit") == 0)
	{

		node->type2 = "int";

		char *number = checkNumber(node->value);

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

		call = true;

		isCall = true;
	}
	else if (strcmp(type, "If") == 0 || strcmp(type, "While") == 0)
	{

		ifStatement = true;
	}
	else if (strcmp(type, "Return") == 0)
	{

		returnBool = true;
	}
	else if (strcmp(type, "Print") == 0)
	{

		print = true;
	}
	else if (strcmp(type, "Length") == 0)
	{

		length = true;
	}
	else if (strcmp(type, "ParseArgs") == 0)
	{

		parseArgs = true;
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
			recursiveMethod(node->brother, method, isCall);
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

		assign = true;
	}
	else if (strcmp(type, "And") == 0 || strcmp(type, "Or") == 0 || strcmp(type, "Not") == 0 || strcmp(type, "Xor") == 0)
	{

		logic = true;
	}
	else if (strcmp(type, "Ne") == 0 || strcmp(type, "Lt") == 0 || strcmp(type, "Le") == 0 || strcmp(type, "Gt") == 0 || strcmp(type, "Ge") == 0 || strcmp(type, "Eq") == 0)
	{

		comparation = true;
	}
	else if (strcmp(type, "Mul") == 0 || strcmp(type, "Add") == 0 || strcmp(type, "Sub") == 0 || strcmp(type, "Div") == 0 || strcmp(type, "Mod") == 0 || strcmp(type, "Plus") == 0 || strcmp(type, "Minus") == 0)
	{

		maths = true;
	}

	if (!call)
		isCall = false;

	if (node->son != NULL)
	{
		recursiveMethod(node->son, method, isCall);
	}

	isCall = false;

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
	else if (maths)
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
	else if (logic || comparation)
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
		checkCall(node, method);
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
		recursiveMethod(node->brother, method, isCall);
}

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
