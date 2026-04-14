Task9.l
#
%{  
#include <stdio.h>  
#include <stdlib.h>  
int COMMENT = 0, cnt = 0;  
%}   
identifier [a-zA-Z][a-zA-Z0-9]*  
%%  
"#".*                  { printf("\n%s PREPROCESSOR", yytext); }  
"/*"                   { COMMENT = 1; }  
"*/"                   { COMMENT = 0; cnt++; }  
[ \t\n]+               ;  
.                      {  
                            if (COMMENT) return 0;    
                            if (strstr("int float char double while for do if break continue void switch case long struct const typedef return else goto", yytext))   
                                printf("\n%s KEYWORD", yytext);  
                            else if (yytext[0] == '{')  
                                printf("\nBLOCK BEGIN");  
                            else if (yytext[0] == '}')  
                                printf("\nBLOCK END");  
                            else if (yytext[0] == '=')  
                                printf("\n= ASSIGN");  
                            else if (strchr("<>=", yytext[0]))  
                                printf("\n%s REL_OP", yytext);  
                            else if (isdigit(yytext[0]))  
                                printf("\n%s NUMBER", yytext);  
                            else if (isalpha(yytext[0]))  
                                printf("\n%s IDENTIFIER", yytext);  
                        }  
%%  
int main(int argc, char **argv)  
{  
    if (argc > 1) {  
        FILE *file = fopen(argv[1], "r");  
        if (!file) {  
            printf("Cannot open file\n");  
            exit(0);  
        }  
        yyin = file;  
    }  
    yylex();  
    printf("\nTotal comments: %d\n", cnt);  
    return 0;  
}  
int yywrap() {  
return 1;  
}  
