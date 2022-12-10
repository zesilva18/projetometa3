#ifndef TREE_H
#define TREE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct info_lex
{
    int line;
    int collum;
    char* name;
} info_lex;

typedef struct ast_tree
{
    char *type;
    char *value;
    char *type2;
    char *paramtype; 
    

    bool valid; 

    int line;
    int collum;

    struct ast_tree *father;
    struct ast_tree *son;
    struct ast_tree *brother;

}ast_tree;

void add_childs(ast_tree *root, ast_tree* new);
ast_tree *ast_node(char *token, char* value, int line, int collum);
void add_brother(ast_tree *brother, ast_tree* newbrother);
void ast_print(ast_tree* ast,int level);


#endif