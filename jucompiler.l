/*
José Pedro Ferreira Dinis e Silva Nº 2020237724
André Magalhães de Carvalho Nº 2020237655

*/

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "tree.h"
    #include "symtab.h"
    #include "semantics.h"
    #include "y.tab.h"


    int line = 1; 
    int collum = 1;
    int nova_coluna = 1;
    int nova_linha = 0; 
    int nova_linha2 = 0;
    int erro_linha = 0;
    int erro_coluna = 0;
    char buffer[1024];
    char strlit[1024];
    extern int flag; 
    int error;
    extern int flag_erro;
    extern int flag_erro2;

    symtab_header* symtab;


    info_lex* createStruct(char* name, int line, int collum){

        info_lex* tmp = (info_lex*)malloc(sizeof(info_lex));

        tmp->name = name;
        tmp->line = line;
        tmp->collum = collum;

        return tmp;

    }
%}

id                   _|$|[A-Za-z]
decimais              [1-9]
numeros              [0-9]|_   
reserved             "switch"|"assert"|"default"|"package"|"finally"|"float"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"synchronized"|"do"|"goto"|"private"|"break"|"++"|"--"|"null"|"Integer"|"System"|"for"|"abstract"|"continue"|"byte"|"case"|"catch"|"char"|"const"|"enum"|"extends"|"final"|"protected"|"short"|"strictfp"|"transient"|"try"|"volatile"|"super"|"this"|"throw"|"throws"

%X COMENTARIOS STRINGS ERRORSTRLIT ERRORESC SL_COMMENT
%%

{reserved}                              {collum += yyleng; if (flag==1){printf("AND\n");}else if (flag==2) {return(RESERVED);};}   

"true"|"false"                          {collum += yyleng; if (flag==1){printf("BOOLLIT(%s)\n",yytext);}else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng);return(BOOLLIT);}}

"&&"                                    {collum += yyleng; if (flag==1){printf("AND\n");}else if (flag==2) {yylval.lex = createStruct((char*)strdup("And"), line, collum - (int) yyleng); return(AND);}}

"="                                     {collum += yyleng; if (flag==1){printf("ASSIGN\n");}else if (flag==2) {yylval.lex = createStruct((char*)strdup("Assign"), line, collum - (int) yyleng);return(ASSIGN);}}

"*"                                     {collum += yyleng; if (flag==1){printf("STAR\n");}else if (flag==2) {yylval.lex = createStruct((char*)strdup("Mul"), line, collum - (int) yyleng);  return(STAR);}} 

","                                     {collum += yyleng; if (flag==1){printf("COMMA\n");}else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng); return(COMMA);}}

"/"                                     {collum += yyleng;if (flag==1){printf("DIV\n");} else if (flag==2) {yylval.lex = createStruct((char*)strdup("Div"), line, collum - (int) yyleng);  return(DIV);}}

"=="                                    {collum += yyleng;if (flag==1){printf("EQ\n");}else if (flag==2) {yylval.lex = createStruct((char*)strdup("Eq"), line, collum - (int) yyleng); return(EQ);}}

">="                                    {collum += yyleng;if (flag==1){printf("GE\n");}else if (flag==2) {yylval.lex = createStruct((char*)strdup("Ge"), line, collum - (int) yyleng);return(GE);}}

">"                                     {collum += yyleng;if (flag==1){printf("GT\n"); }else if (flag==2) {yylval.lex = createStruct((char*)strdup("Gt"), line, collum - (int) yyleng); return(GT);}}

"{"                                     {collum += yyleng;if (flag==1){printf("LBRACE\n");} else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng); return(LBRACE);} }

"<="                                    {collum += yyleng;if (flag==1){printf("LE\n");} else if (flag==2) {yylval.lex = createStruct((char*)strdup("Le"), line, collum - (int) yyleng); return(LE);}}

"("                                     {collum += yyleng;if (flag==1){printf("LPAR\n");} else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng); return(LPAR);}}

"["                                     {collum += yyleng;if (flag==1){printf("LSQ\n"); }else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng); return(LSQ);}}

"<"                                     {collum += yyleng;if (flag==1){printf("LT\n");}else if (flag==2) {yylval.lex = createStruct((char*)strdup("Lt"), line, collum - (int) yyleng); return(LT);}}

"-"                                     {collum += yyleng;if (flag==1){printf("MINUS\n"); }else if (flag==2) {yylval.lex = createStruct((char*)strdup("Sub"), line, collum - (int) yyleng);return(MINUS);}}

"%"                                     {collum += yyleng;if (flag==1){printf("MOD\n");}else if (flag==2) {yylval.lex = createStruct((char*)strdup("Mod"), line, collum - (int) yyleng);return(MOD);}}

"!="                                    {collum += yyleng;if (flag==1){printf("NE\n");}else if (flag==2) {yylval.lex = createStruct((char*)strdup("Ne"), line, collum - (int) yyleng); return(NE);}}

"!"                                     {collum += yyleng;if (flag==1){printf("NOT\n");}else if (flag==2) {yylval.lex = createStruct((char*)strdup("Not"), line, collum - (int) yyleng);return(NOT);}}

"||"                                    {collum += yyleng;if (flag==1){printf("OR\n"); }else if (flag==2) {yylval.lex = createStruct((char*)strdup("Or"), line, collum - (int) yyleng);return(OR);}}

"+"                                     {collum += yyleng;if (flag==1){printf("PLUS\n");}else if (flag==2) {yylval.lex = createStruct((char*)strdup("Add"), line, collum - (int) yyleng);return(PLUS);}}

"}"                                     {collum += yyleng;if (flag==1){printf("RBRACE\n"); }else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng); return(RBRACE);}}

")"                                     {collum += yyleng;if (flag==1){printf("RPAR\n"); }else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng); return(RPAR);}}

"]"                                     {collum += yyleng;if (flag==1){printf("RSQ\n");}else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng); return(RSQ);}}

";"                                     {collum += yyleng;if (flag==1){printf("SEMICOLON\n"); }else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng); return(SEMICOLON);}}

"->"                                    {collum += yyleng;if (flag==1){printf("ARROW\n"); }else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng); return(ARROW);}}

"<<"                                    {collum += yyleng;if (flag==1){printf("LSHIFT\n"); }else if (flag==2) {yylval.lex = createStruct((char*)strdup("Lshift"), line, collum - (int) yyleng); return(LSHIFT);}}

">>"                                    {collum += yyleng;if (flag==1){printf("RSHIFT\n");}else if (flag==2) {yylval.lex = createStruct((char*)strdup("Rshift"), line, collum - (int) yyleng); return(RSHIFT);}}

"^"                                     {collum += yyleng;if (flag==1){printf("XOR\n"); }else if (flag==2) {yylval.lex = createStruct((char*)strdup("Xor"), line, collum - (int) yyleng); return(XOR);}}

"boolean"                               {collum += yyleng;if (flag==1){printf("BOOL\n"); }else if (flag==2) {yylval.lex = createStruct((char*)strdup("Bool"), line, collum - (int) yyleng); return(BOOL);}}

"class"                                 {collum += yyleng;if (flag==1){printf("CLASS\n"); }else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng);  return(CLASS);}}

".length"                               {collum += yyleng;if (flag==1){printf("DOTLENGTH\n"); }else if (flag==2) {yylval.lex = createStruct("Lenght", line, collum - (int) yyleng); return(DOTLENGTH);}}

"double"                                {collum += yyleng;if (flag==1){printf("DOUBLE\n"); }else if (flag==2) {yylval.lex = createStruct("Double", line, collum - (int) yyleng); return(DOUBLE);}}

"else"                                  {collum += yyleng;if (flag==1){printf("ELSE\n"); }else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng); return(ELSE);}}

"if"                                    {collum += yyleng;if (flag==1){printf("IF\n"); }else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng);return(IF);}}

"int"                                   {collum += yyleng;if (flag==1){printf("INT\n"); }else if (flag==2) {yylval.lex = createStruct((char*)strdup("Int"), line, collum - (int) yyleng); return(INT);}}

"System.out.print"                      {collum += yyleng;if (flag==1){printf("PRINT\n");}else if (flag==2) {yylval.lex = createStruct("Print", line, collum - (int) yyleng); return(PRINT);}}

"Integer.parseInt"                      {collum += yyleng;if (flag==1){printf("PARSEINT\n");}else if (flag==2) {yylval.lex = createStruct("ParseArgs", line, collum - (int) yyleng); return(PARSEINT);}}

"public"                                {collum += yyleng;if (flag==1){printf("PUBLIC\n"); }else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng); return(PUBLIC);}}

"return"                                {collum += yyleng;if (flag==1){printf("RETURN\n"); }else if (flag==2) {yylval.lex = createStruct("Return", line, collum - (int) yyleng); return(RETURN);}}

"static"                                {collum += yyleng;if (flag==1){printf("STATIC\n"); }else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng); return(STATIC);}}

"String"                                {collum += yyleng;if (flag==1){printf("STRING\n"); }else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng); return(STRING);}}

"void"                                  {collum += yyleng;if (flag==1){printf("VOID\n");  }else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng); return(VOID);}}

"while"                                 {collum += yyleng;if (flag==1){printf("WHILE\n"); }else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng); return(WHILE);}}


"//"                           {BEGIN SL_COMMENT;collum = 1;line++;}
<SL_COMMENT>"\r"|"\n"|"\r\n"   {BEGIN 0;} 
<SL_COMMENT><<EOF>>            {BEGIN 0;}
<SL_COMMENT>.                  ;   

"/""*"                          {nova_linha = line;nova_coluna=collum; nova_linha2 = 0;collum += 2;BEGIN(COMENTARIOS);}
<COMENTARIOS><<EOF>>            {line += nova_linha2; printf("Line %d, col %d: unterminated comment\n", nova_linha, nova_coluna); BEGIN(0); collum += yyleng; }
<COMENTARIOS>"*""/"             {line += nova_linha2; collum+=2; BEGIN(0);}
<COMENTARIOS>"\r"|"\n"|"\r\n"   {nova_linha2++;collum = 1;}
<COMENTARIOS>.                  {collum += yyleng;}



\"                           {nova_coluna = collum; collum += 1; nova_linha=line; BEGIN STRINGS; buffer[0] = '\0'; error = 0;}
<STRINGS>[^\\"\r\n]*         {collum+=yyleng; strcat(buffer, yytext);}
<STRINGS>\\f                 {collum+=yyleng; strcat(buffer, yytext);}
<STRINGS>\\n                 {collum+=yyleng; strcat(buffer, yytext);}
<STRINGS>\\t                 {collum+=yyleng; strcat(buffer, yytext);}
<STRINGS>\\r                 {collum+=yyleng; strcat(buffer, yytext);}
<STRINGS>\\[\\"]             {collum+=yyleng; strcat(buffer, yytext);}
<STRINGS>\"                  {collum+=yyleng; BEGIN 0; if (error!=1){if(flag==1){printf("STRLIT(\"%s\")\n", buffer);}else if (flag==2) {strlit[0] = '\"'; strcat(strlit, buffer); strcat(strlit, "\""); yylval.lex = createStruct((char*)strdup(strlit), line, collum - (int) yyleng);  bzero(strlit,sizeof(strlit)); return(STRLIT);}}}
<STRINGS>\\.|\\              {error=1; if (yytext[1] != '\r') {printf("Line %d, col %d: invalid escape sequence (%s)\n", line, collum, yytext); collum+=yyleng;} else {printf("Line %d, col %d: invalid escape sequence (\\)\n", line, collum - (int) yyleng); collum+=yyleng;}}
<STRINGS>"\r"|"\n"|"\r\n"    {error=1; printf("Line %d, col %d: unterminated string literal\n", nova_linha, nova_coluna); line++; collum=1; nova_coluna=0; buffer[0] = '\0'; BEGIN 0;}
<STRINGS><<EOF>>             {error=1; printf("Line %d, col %d: unterminated string literal\n", nova_linha, nova_coluna); line++; collum=1; nova_coluna=0; buffer[0] = '\0'; BEGIN 0;}


{decimais}+{numeros}*({decimais}|"0")                                                                                              {collum += yyleng; if (flag==1){ printf("INTLIT(%s)\n", yytext); }else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng);  return(INTLIT);}}

"."({numeros}*("_"*({decimais}|"0")+))+                                                                                            {collum += yyleng; if (flag==1){printf("REALLIT(%s)\n", yytext); }else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng);  return(REALLIT);}}
ç
"-"?(({decimais}+{numeros}*|"0")?({decimais}|"0"))+"."({numeros}*("_"*({decimais}|"0")+))*                                             {collum += yyleng; if (flag==1){printf("REALLIT(%s)\n", yytext); }else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng); return(REALLIT);}}

"-"?({decimais}+{numeros}*|"0"){decimais}*("E-"|"E+"|"e-"|"e+"|"e"|"E")({decimais}|"0"){numeros}*                                      {collum += yyleng; if (flag==1){printf("REALLIT(%s)\n", yytext); }else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng); return(REALLIT);}} //numeros com exponencias

"-"?({decimais}+{numeros}*|"0")("E-"|"E+"|"e-"|"e+"|"e"|"E")({decimais}|"0"){numeros}+"."({decimais}|"0"){numeros}*                    {collum += yyleng; if (flag==1){printf("REALLIT(%s)\n", yytext);}else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng); return(REALLIT);}}

"-"?(({decimais}+{numeros}*|"0")?({decimais}|"0"))*"."{numeros}*({decimais}|"0")("E-"|"E+"|"e-"|"e+"|"e"|"E"){numeros}+                {collum += yyleng; if (flag==1){printf("REALLIT(%s)\n", yytext);}else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng); return(REALLIT);}}

"-"?(({decimais}+{numeros}*|"0")?({decimais}|"0"))+"."({decimais}|"0")*("_"*{decimais}+)?("E-"|"E+"|"e-"|"e+"|"e"|"E"){numeros}+       {collum += yyleng; if (flag==1){printf("REALLIT(%s)\n", yytext); }else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng); return(REALLIT);}}

{id}({id}|{numeros})*                                                                                                              {collum += yyleng; if (flag==1){printf("ID(%s)\n", yytext); }else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng);  return(ID);}}

{decimais}|0                                                                                                                       {collum += yyleng; if (flag==1){printf("INTLIT(%s)\n", yytext);}else if (flag==2) {yylval.lex = createStruct((char*)strdup(yytext), line, collum - (int) yyleng); return(INTLIT);}}


"\f"|"\t"                                    {collum += yyleng;}
" "                                          {collum += yyleng;}
"\n"|"\r"|"\r\n"                             {line++; collum = 1;}
.                                            {printf("Line %d, col %d: illegal character (%s)\n",line,collum, yytext);collum += yyleng;}


%%

void yyerror(char *s) {
    if(strlen(buffer) > 1){
        printf("Line %d, col %d: %s: \"%s\"\n", line, nova_coluna + (int) yyleng - 1, s, buffer);
        buffer[0] = '\0';
    }else{
        if(line == 1 && yytext[-1] != '\n'){
            printf("Line %d, col %d: %s: %s\n", line, collum - (int) yyleng + 1, s, yytext);
        }else{
            printf("Line %d, col %d: %s: %s\n", line, collum - (int) yyleng, s, yytext);
        }
    }
}


int yywrap() {
    return 1;
}
