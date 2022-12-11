#include "tree.h"



ast_tree *ast_node(char *type, char* value, int line, int collum) { //criar arvore
    ast_tree *node = (ast_tree *)malloc(sizeof(ast_tree));
    node->type = type;
    node->value = value;
    node->line = line;
    node->collum = collum;
    node->father = NULL;
    node->brother = NULL;
    node->son = NULL;

    return node;
}

void add_childs(ast_tree *root, ast_tree* new) { //adicionar filhos
    if (new == NULL) {
        return;
    }
    if (root->son == NULL) {
        root->son = new;
    } else {
        ast_tree *temp = root->son;
        while (temp->brother != NULL) {
            temp = temp->brother;
        }
        temp->brother = new;
    }
    new->father = root;
}

void add_brother(ast_tree *brother, ast_tree *newbrother) { //adicionar irmaos
    if (newbrother == NULL) {
        return;
    }
    if (brother == NULL) {
        return;
    } else {
        ast_tree *temp = brother;
        while (temp->brother != NULL) {
            temp = temp->brother;
        }
        temp->brother = newbrother;
    }
    newbrother->father = brother->father;
}

void ast_print(ast_tree* ast,int level)
{
    if (ast == NULL)
    {
        return;
    }
    if (strcmp(ast->type, "Semicolon") != 0)
    {
        for (int i = 0; i < level; i++)
            printf(".");
            
        printf("%s", ast->type);
        if (strcmp(ast->value, "") != 0)
        {
            printf("(%s)", ast->value);
        }
        if (ast->type2 != NULL && strcmp(ast->type2, "none") != 0)
        {
            printf(" - %s\n", ast->type2);
        }
        else if (ast->paramtype != NULL)
        {
            printf(" - (%s)\n", ast->paramtype);
        }
        else
        {
            printf("\n");
        }
    }
    if (ast->son != NULL)
    {
        ast_print(ast->son, level + 2);
    }
    if (ast->brother != NULL)
    {
        ast_print(ast->brother, level);
    }
}

