%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "y.tab.h"
   // extern YYSTYPE yylval;
%}

%option noyywrap
%option caseless
%option yylineno

W                 [ \t\n]+
ID                [A-Za-z]([A-Za-z]|[0-9])*
N                 [0-9]+
EP                (E|e)[0-9]+
R                 {[0-9]*\.[0-9]+{EP}?} | {[0-9]+\.[0-9]*{EP}?}

%%

{W}                       {;}
"PROGRAM"                 { return(PROGRAM);}
"VAR"                     { return(VAR);}
"BEGIN"                   { return(BN);}
"END."                    { return(END_DOT);}
"END"                     { return(END);}
"REAL"                    { return(REAL);}
"INTEGER"                 { return(INTEGER);}
"FOR"                     { return(FOR);}
"READ"                    { return(READ);}
"WRITE"                   { return(WRITE);}
"TO"                      { return(TO);}
"DO"                      { return(DO);}
";"                       { return(SEMI_COLON);}
":"                       { return(COLON);}
","                       { return(COMMA);}
":="                       { return(EQUAL);}
"+"                       { return(PLUS);}
"-"                       { return(MINUS);}
"*"                       { return(STAR);}
"DIV"                     { return(DIV);}
"("                       { return(OPENBRACE);}
")"                       { return(CLOSEBRACE);}
{ID}                      { yylval.f=strdup(yytext); return(I);}
{N}                       { yylval.tol=strdup(yytext); return(NO);}
[0-9]*\.[0-9]+EP? { yylval.f=yytext; return RNO;}
[0-9]+\.[0-9]*EP? { yylval.f=yytext; return RNO;}

%%
