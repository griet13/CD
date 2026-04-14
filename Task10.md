Task10.l
#
%{  
#include <stdio.h>  
#include <stdlib.h>  
#include <math.h>  
int op = 0;  
float a = 0, b;  
%}  
dig [0-9]+(\.[0-9]+)?  
optr [+\-*/^]  
%%  
{dig} {  
    if(op == 0)  
        a = atof(yytext);  
    else {  
        b = atof(yytext);  
        switch(op){  
            case '+': a += b;  
                      break;  
            case '-': a -= b;  
                      break;  
            case '*': a *= b;  
                      break;  
            case '/': a /= b;  
                      break;   
            case '^': a = pow(a,b);  
                      break;  
        }  
        op = 0;  
    }  
}  
{optr} { op = yytext[0]; }  
\n { printf("\nResult: %f\n", a); }  
[ \t] ;  
. ;  
%%  
int main(){  
    yylex();  
    return 0;  
}  
int yywrap(){  
    return 1;  
}  
