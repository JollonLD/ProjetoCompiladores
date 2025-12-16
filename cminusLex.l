%option noyywrap
%option yylineno

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    #define YY_DECL int yylex()
    
    #include "cminus.tab.h"
%}

%x COMMENT

%%

[ \t\r]+           ; /* ignorar espaços, tabs */
\n                 ; /* ignorar quebras de linha */

"/*"               { BEGIN(COMMENT); }
<COMMENT>"*/"      { BEGIN(INITIAL); }
<COMMENT>\n        ;
<COMMENT>.         ;
<COMMENT><<EOF>>   { fprintf(stderr, "ERRO LEXICO: 'comentario nao fechado' - LINHA: %d\n", yylineno); return 0; }

"//".*             ; /* comentários de linha única */

"else"             { return ELSE; }
"if"               { return IF; }
"int"              { return INT; }
"return"           { return RETURN; }
"void"             { return VOID; }
"while"            { return WHILE; }

[a-zA-Z][a-zA-Z0-9]* { 
    yylval.id = strdup(yytext); 
    return ID; 
}

[0-9]+             { 
    yylval.ival = atoi(yytext); 
    return NUM; 
}

"<="               { return LE; }
"<"                { return LT; }
">"                { return GT; }
">="               { return GE; }
"=="               { return EQ; }
"!="               { return NE; }

"="                { return ASSIGN; }
";"                { return SEMI; }
","                { return COMMA; }

"("                { return LPAREN; }
")"                { return RPAREN; }
"["                { return LBRACK; }
"]"                { return RBRACK; }
"{"                { return LBRACE; }
"}"                { return RBRACE; }

"+"                { return PLUS; }
"-"                { return MINUS; }
"*"                { return TIMES; }
"/"                { return DIVIDE; }

.                  {
    fprintf(stderr, "ERRO LEXICO:    caractere nao reconhecido: '%s' - LINHA: %d\n", yytext, yylineno);
}

%%