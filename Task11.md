Task11.l
#
%{  
#include <stdio.h>  
int lines=0, words=0, letters=0, digits=0, spl=0;  
%}  
%%  
\n          { lines++; words++; }  
[ \t]+      { words++; }  
[A-Za-z]    { letters++; }  
[0-9]       { digits++; }  
.           { spl++; }  
%%  
int main()  
{  
    yyin = fopen("myfile.txt", "r");  
    yylex();  
    int total = letters + digits + spl;  
    printf("File contains:\n");  
    printf("%d lines\n", lines);  
    printf("%d words\n", words);  
    printf("%d letters\n", letters);  
    printf("%d digits\n", digits);  
    printf("%d special characters\n", spl);  
    printf("Total characters: %d\n", total);  
    return 0;  
}  

int yywrap() {  
return 1;  
}
