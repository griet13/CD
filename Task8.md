Task8.l
#
%{  
    #include <stdio.h>  
    #include <stdlib.h>  
    #include "y.tab.h"  
%}  
%%  
    [0-9]+ {  
    yylval.dval = atof(yytext);  
    return NUMBER;  
    }  
    \n return '\n';  
    [ \t] ;  
    . return yytext[0];  
%%  
int yywrap(void)  
{  
    return 1;  
}  

###
Task8.y
#
%{  
#include <stdio.h>  
#include <stdlib.h>  
int yylex(void);  
int yyerror(const char *s);  
%}  
%union {  
    double dval;  
}  
%token <dval> NUMBER  
%type <dval> expr
%%
input:
      input expr '\n' { printf("Result = %lf\n", $2); }  
    |  
    ;  
expr:  
      expr '+' expr { $$ = $1 + $3; }  
    | expr '-' expr { $$ = $1 - $3; }  
    | expr '*' expr { $$ = $1 * $3; }  
    | expr '/' expr { $$ = $1 / $3; }  
    | NUMBER        { $$ = $1; }  
    ;
%%
int yyerror(const char *s)  
{  
    printf("Syntax error\n");    
    return 0;   
}
int main(void)  
{  
    yyparse();  
    return 0;  
}  
