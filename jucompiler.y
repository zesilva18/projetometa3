/*
José Pedro Ferreira Dinis e Silva Nº 2020237724
André Magalhães de Carvalho Nº 2020237655

*/

%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
#include "semantics.h"

symtab_header* symtab;

struct ast_tree *raiz;
struct ast_tree *aux;
struct ast_tree *temp;

int flag = 1;
int error = 0;
char *type;
int n_sons;
int yydebug = 1;
int flag_erro = 0;
int flag_erro2 = 0;

extern int yylex(void);
extern int yyerror(char *s);
extern int yylineno;
extern int line;
extern int collum;

int flag_while = 0;

void mantertipo(ast_tree* no,char* type){
        ast_tree* auxiliar = NULL;
        for (ast_tree *atual = no; atual; atual = atual->brother){
            auxiliar=ast_node(type, "",0,0);
            auxiliar->brother=atual->son;
            atual->son=auxiliar;
        }
}

%}

%union{
char* string;
struct ast_tree* ast_tree;
struct info_lex *lex;  
}

/* TOKENS */
%token CLASS PUBLIC STATIC
%token COMMA LBRACE RBRACE LPAR RPAR LSQ RSQ 
%token ELSE  
%token ARROW 
%token RESERVED

%type <ast_tree>  StatementAux Statement MethodDecl ShiftReduce MethodBody HelpProgam HelpMethod Program Expr MethodInvocation  ParseArgs  MethodInvocationaux  VarDecl Type VarDeclAux FieldDecl HelpField FormalParams FormalParamsAux MethodHeader ExprAux


%token <lex> WHILE SEMICOLON ID STRLIT INTLIT REALLIT BOOLLIT BOOL INT DOUBLE PLUS MINUS STAR DIV MOD AND OR XOR LSHIFT RSHIFT EQ GE GT LE LT NE NOT ASSIGN PRINT RETURN PARSEINT DOTLENGTH VOID IF STRING



/* Precedências */
%left COMMA
%right ASSIGN
%left OR
%left AND
%left XOR
%left LSHIFT RSHIFT
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left STAR DIV MOD
%right NOT 
%left LPAR RPAR
%nonassoc ELSE



%%

Program: CLASS ID LBRACE HelpProgam RBRACE                  {
                                                                $$ = ast_node("Program","",0,0);       
                                                                add_childs($$, ast_node("Id", $2->name,$2->line,$2->collum));
                                                                add_childs($$,$4);
                                                                raiz = $$;
                                                            }
        ;

HelpProgam: MethodDecl HelpProgam                            {
                                                                $$ = $1;
                                                                add_brother($$, $2);
                                                            }
          | FieldDecl HelpProgam                             {                                                           
                                                                $$ = $1;
                                                                
                                                                add_brother($$, $2);
                                                                
                                                            }
          | SEMICOLON HelpProgam                             {
                                                                $$ = $2;
                                                            }
            |                                               {$$=NULL;}

          ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody                                   {
                                                                                    $$ = ast_node("MethodDecl","",0,0);
                                                                                    add_childs($$,$3);
                                                                                    add_childs($$,$4);
                                                                                    }                                             
           ;


MethodHeader: Type ID LPAR FormalParams RPAR                   {
                                                                $$ = ast_node("MethodHeader","",0,0);
                                                                aux = ast_node("MethodParams","",0,0);
                                                                add_childs($$,$1); 
                                                                add_childs($$,ast_node("Id", $2->name,$2->line,$2->collum));
                                                                add_childs($$, aux);
                                                                add_childs(aux,$4);
                                                               }

        | VOID ID LPAR FormalParams RPAR                       {
                                                                $$ = ast_node("MethodHeader","",0,0);
                                                                aux = ast_node("MethodParams","",0,0);
                                                                add_childs($$,ast_node("Void", "", $1->line, $1->collum)); 
                                                                add_childs($$,ast_node("Id", $2->name,$2->line,$2->collum));
                                                                add_childs($$, aux);
                                                                add_childs(aux,$4);
                                                               }

        ;

MethodBody: LBRACE HelpMethod RBRACE                                             {$$ = ast_node("MethodBody","",0,0); 
                                                                                    add_childs($$,$2);
                                                                                    }
          ;


HelpMethod: Statement HelpMethod                                              {if($1!=NULL){
                                                                                    $$ = $1;
                                                                                    add_brother($$, $2);
                                                                                    }
                                                                                    else{
                                                                                        $$ = $2;
                                                                                    }
                                                                                    }
             | VarDecl HelpMethod                                                {$$ = $1; add_brother($$, $2);}
             |                                                                      {$$ = NULL;}
             ;

FieldDecl: PUBLIC STATIC Type ID HelpField SEMICOLON     {
                                                                $$ = ast_node("FieldDecl", "",0,0);
                                                                add_childs($$,$3);
                                                                add_childs($$, ast_node("Id", $4->name,$4->line,$4->collum));
                                                                mantertipo($5, $3->type);
                                                                add_brother($$, $5);
                                                                
                                                            }
        | error SEMICOLON                                    {$$ = NULL;flag_erro = 1; flag_erro2 = 1;}
        ;


HelpField: COMMA ID HelpField                         {
                                                                $$ = ast_node("FieldDecl","",0,0);                                                                
                                                                add_childs($$, ast_node("Id", $2->name,$2->line,$2->collum));
                                                                add_brother($$, $3);
                                                                
                                                            }

            |                                              {$$ = NULL; }                                                
            ;

Type: INT                                                   {$$ = ast_node($1->name,"",$1->line,$1->collum);}
    | DOUBLE                                                {$$ = ast_node($1->name,"",$1->line,$1->collum);}
    | BOOL                                                  {$$ = ast_node($1->name,"",$1->line,$1->collum);}                
    ;

FormalParams: Type ID FormalParamsAux                                      {$$ = ast_node("ParamDecl","",0,0);
                                                                            add_childs($$,$1);
                                                                            add_childs($$,ast_node("Id", $2->name,$2->line,$2->collum));
                                                                            add_brother($$,$3);}
                                                                            
            | STRING LSQ RSQ ID                                            {
                                                                           $$ = ast_node("ParamDecl","",0,0);
                                                                           add_childs($$,ast_node("StringArray","",$1->line,$1->collum));
                                                                           add_childs($$,ast_node("Id", $4->name,$4->line,$4->collum));
                                                                           }

            |                                                               {$$ = NULL;}
            ;                               


FormalParamsAux: COMMA Type ID FormalParamsAux                            { $$ = ast_node("ParamDecl","",0,0);
                                                                            add_childs($$,$2);
                                                                            add_childs($$,ast_node("Id",$3->name,$3->line,$3->collum));
                                                                            add_brother($$,$4);
                                                                            }
                                                                            
                |                                                         {$$ = NULL;}
                ;


VarDecl: Type ID VarDeclAux SEMICOLON                                   {
    
                                                                $$ = ast_node("VarDecl", "",0,0);
                                                                add_childs($$, $1);
                                                                add_childs($$, ast_node("Id", $2->name,$2->line,$2->collum));
                                                                mantertipo($3, $1->type);
                                                                add_brother($$, $3);
                                                                
                                                                }
        ;

VarDeclAux: COMMA ID VarDeclAux                            { 
                                                                $$ = ast_node("VarDecl","",0,0);
                                                                add_childs($$, ast_node("Id", $2->name,$2->line,$2->collum));                                                              
                                                                add_brother($$, $3);
                                                                
                                                            }
        |                                                   {$$ = NULL;}
        ;

Statement:    LBRACE Statement StatementAux RBRACE        {
                                                                int count = 0;
                                                                if($2 != NULL){
                                                                    count++;
                                                                }
                                                                aux = $3;
                                                                while(aux != NULL){
                                                                    if(aux->type != NULL && strcmp(aux->type,"Semicolon")!=0){
                                                                        count++;
                                                                    }

                                                                    aux = aux->brother;
                                                                }
                                                                
                                                                if(count > 1){
                                                                    $$ = ast_node("Block","",0,0);
                                                                    add_childs($$,$2);
                                                                    add_childs($$,$3);
                                                                }
                                                                else {
                                                                    $$ = $2;
                                                                }
                                                            }

            | LBRACE RBRACE 								     {$$ = NULL;}


            | IF LPAR Expr RPAR Statement                                   {
                                                                               $$ = ast_node("If","", $1->line,$1->collum);
                                                                               

                                                                               add_childs($$,$3);


                                                                               if($5 == NULL || strcmp($5->type, "Semicolon") == 0){
                                                                                    add_childs($$,ast_node("Block","",0,0));
                                                                                    add_childs($$,ast_node("Block","",0,0));
                                                                               }else{
                                                                                    add_childs($$,$5);
                                                                                    add_childs($$,ast_node("Block","",0,0));
                                                                               }
                                                                            }

            | IF LPAR Expr RPAR Statement ELSE Statement                    {
                                                                                $$ = ast_node("If","",$1->line,$1->collum);
                                                                                add_childs($$,$3);
                                                                                if($5 == NULL || strcmp($5->type,"Semicolon") == 0){  
                                                                                    add_childs($$,ast_node("Block","",0,0));}
                                                                                else{
                                                                                    add_childs($$,$5);
                                                                                    }
                                                                                if($7 == NULL|| strcmp($7->type,"Semicolon") == 0){ 
                                                                                    add_childs($$,ast_node("Block","",0,0));}
                                                                                else{
                                                                                    add_childs($$,$7);
                                                                                    }

                                                                            }
            | WHILE LPAR Expr RPAR Statement                                {
                                                                             $$ = ast_node("While","",$1->line,$1->collum);
                                                                             add_childs($$,$3);
                                                                             if($5 == NULL || strcmp($5->type,"Semicolon") == 0){
                                                                                add_childs($$,ast_node("Block","",0,0));
                                                                                }
                                                                             else {
                                                                                    add_childs($$,$5);
                                                                                }
                                                                                
                                                                             
                                                                             
                                                                            }
                                                            
            | ID ASSIGN Expr SEMICOLON                                      {
                                                                                $$ = ast_node("Assign","",$2->line,$2->collum);
                                                                                add_childs($$,ast_node("Id",$1->name,$1->line,$1->collum));
                                                                                add_childs($$,$3);
                                                                            }

            | RETURN SEMICOLON                                                      {$$ = ast_node("Return", "",$1->line,$1->collum);}

            | RETURN Expr SEMICOLON                                                 {$$ = ast_node("Return","",$1->line,$1->collum);
                                                                                    add_childs($$,$2);
                                                                                    } 

            | PRINT LPAR Expr RPAR SEMICOLON                                        {$$ = ast_node("Print","",$1->line,$1->collum);
                                                                                    add_childs($$,$3);
                                                                                    }   

            | PRINT LPAR STRLIT RPAR SEMICOLON                                      {$$ = ast_node("Print","",$1->line,$1->collum);
                                                                                    add_childs($$, ast_node("StrLit", $3->name,$3->line,$3->collum));
                                                                                    }

            | MethodInvocation SEMICOLON                                            {$$ = $1;}

           
            | ParseArgs SEMICOLON                                                   {$$ = $1;}
            | SEMICOLON                                                             {$$ = ast_node("Semicolon","",$1->line,$1->collum);}
            | error SEMICOLON                                                       {$$ = NULL;flag_erro = 1;flag_erro2 = 1;}
            ;

StatementAux: Statement StatementAux                                                {$$ = $1; add_brother($$,$2);}
            |                                                                       {$$ = NULL;}
            ;

MethodInvocation: ID LPAR ShiftReduce RPAR                             {$$ = ast_node("Call", "",$1->line, $1->collum);
                                                                        add_childs($$, ast_node("Id", $1->name,$1->line,$1->collum));add_childs($$, $3);}

                | ID LPAR RPAR                                                {$$ = ast_node("Call", "",$1->line, $1->collum);
                                                                                add_childs($$, ast_node("Id", $1->name,$1->line,$1->collum));}

                | ID LPAR error RPAR                                                {$$ = NULL;flag_erro = 1; flag_erro2 = 1;}                            
                ;

ShiftReduce: Expr MethodInvocationaux			     {$$ = $1;add_brother($$,$2);}
    

MethodInvocationaux: COMMA Expr MethodInvocationaux                                 {$$ = $2;add_brother($$, $3);}  

                    |                                                               {$$ = NULL;}               
                    ;

ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR                                       {$$ = ast_node("ParseArgs","",$1->line,$1->collum);
                                                                                    add_childs($$, ast_node("Id", $3->name,$3->line,$3->collum));add_childs($$, $5);}

        | PARSEINT LPAR error RPAR                                                  {$$ = NULL;flag_erro = 1; flag_erro2 = 1;}
        ;


Expr: ExprAux                                                                             {$$ = $1;}
    | ID ASSIGN Expr                                                                          {$$ = ast_node("Assign","",$2->line,$2->collum); add_childs($$, ast_node("Id", $1->name,$1->line,$1->collum)); add_childs($$, $3);}
    ;

ExprAux: ExprAux PLUS ExprAux                                                             {$$ = ast_node("Add","",$2->line,$2->collum);add_childs($$,$1);add_brother($1,$3);}
    | ExprAux MINUS ExprAux                                                               {$$ = ast_node("Sub","",$2->line,$2->collum);add_childs($$,$1);add_brother($1,$3);}
    | ExprAux STAR ExprAux                                                                {$$ = ast_node("Mul","",$2->line,$2->collum);add_childs($$,$1);add_brother($1,$3);}
    | ExprAux DIV ExprAux                                                                 {$$ = ast_node("Div","",$2->line,$2->collum);add_childs($$,$1);add_brother($1,$3);}
    | ExprAux MOD ExprAux                                                                 {$$ = ast_node("Mod","",$2->line,$2->collum);add_childs($$,$1);add_brother($1,$3);}
    | ExprAux OR ExprAux                                                                  {$$ = ast_node("Or","",$2->line,$2->collum);add_childs($$,$1);add_brother($1,$3);}
    | ExprAux XOR ExprAux                                                                 {$$ = ast_node("Xor","",$2->line,$2->collum);add_childs($$,$1);add_brother($1,$3);}
    | ExprAux AND ExprAux                                                                 {$$ = ast_node("And","",$2->line,$2->collum);add_childs($$,$1);add_brother($1,$3);}
    | ExprAux LSHIFT ExprAux                                                              {$$ = ast_node("Lshift","",$2->line,$2->collum);add_childs($$,$1);add_brother($1,$3);} 
    | ExprAux RSHIFT ExprAux                                                              {$$ = ast_node("Rshift","",$2->line,$2->collum);add_childs($$,$1);add_brother($1,$3);} 
    | ExprAux EQ ExprAux                                                                  {$$ = ast_node("Eq","",$2->line,$2->collum);add_childs($$,$1);add_brother($1,$3);}   
    | ExprAux NE ExprAux                                                                  {$$ = ast_node("Ne","",$2->line,$2->collum);add_childs($$,$1);add_brother($1,$3);}
    | ExprAux LT ExprAux                                                                  {$$ = ast_node("Lt","",$2->line,$2->collum);add_childs($$,$1);add_brother($1,$3);}
    | ExprAux GT ExprAux                                                                  {$$ = ast_node("Gt","",$2->line,$2->collum);add_childs($$,$1);add_brother($1,$3);}
    | ExprAux LE ExprAux                                                                  {$$ = ast_node("Le","",$2->line,$2->collum);add_childs($$,$1);add_brother($1,$3);}
    | ExprAux GE ExprAux                                                                  {$$ = ast_node("Ge","",$2->line,$2->collum);add_childs($$,$1);add_brother($1,$3);}
    | MINUS ExprAux %prec NOT                                                          {$$ = ast_node("Minus","",$1->line,$1->collum);add_childs($$,$2);} 
    | NOT ExprAux                                                                      {$$ = ast_node("Not","",$1->line,$1->collum);add_childs($$,$2);}
    | PLUS ExprAux  %prec NOT                                                          {$$ = ast_node("Plus","",$1->line,$1->collum);add_childs($$,$2);}
    | LPAR ExprAux RPAR                                                                {$$ = $2;} 
    | ID                                                                            {$$ = ast_node("Id",$1->name,$1->line,$1->collum);}
    | ID DOTLENGTH                                                                  {$$ = ast_node("Length","",$2->line,$2->collum); add_childs($$,ast_node("Id",$1->name,$1->line,$1->collum));}
    | INTLIT                                                                        {$$ = ast_node("DecLit",$1->name,$1->line,$1->collum);}
    | REALLIT                                                                       {$$ = ast_node("RealLit",$1->name,$1->line,$1->collum);} 
    | BOOLLIT                                                                       {$$ = ast_node("BoolLit",$1->name,$1->line,$1->collum);}
    | MethodInvocation                                                              {$$ = $1;}
    | ParseArgs                                                                     {$$ = $1;}
    | LPAR error RPAR                                                               {$$ = NULL;flag_erro = 1; flag_erro2 = 1;}
    ;

%%



int main(int argc, char *argv[]){
    if(argc >= 2){
        if(strcmp(argv[1],"-e1") == 0){
            /* Analise Lexical : Mostra so os erros */
            flag=0;
            yylex();
        }else if(strcmp(argv[1],"-l") == 0){
            /* Analise Lexical : Mostra os erros e os tokens */
            flag=1;
            yylex();
        }
        if(strcmp(argv[1],"-e2") == 0){
            /* Analise Sintatica : Mostra so os erros */
            flag=2;
            yyparse();
        }
        else if(strcmp(argv[1],"-t") == 0){
            /* Analise Sintatica : Mostra os erros e a arvore */
            flag=2;
            yyparse();
            if(flag_erro == 0){
                ast_print(raiz,0);
            }
        }
        else if(strcmp(argv[1],"-s") == 0){
            flag=2;
            yyparse();
            check_program(raiz);
            printTable();
            if(flag_erro == 0){
                ast_print(raiz,0);
            }
        }
    }else{
            flag=2;
            yyparse();
            if(raiz != NULL){
                check_program(raiz);
            }
            
        }
    return 0;
}