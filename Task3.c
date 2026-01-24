#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
    char expr[20],c;
    int i=0;
    printf("Expression terminated by $: ");
    while((c=getchar())!='$'){
        expr[i++]=c;
    }
    expr[i]='\0';
    printf("\nGiven Expression: %s\n", expr);
    printf("\nSymbol\tAddress\tType\n");
    for(i=0;expr[i]!='\0';i++){
        if(isalpha(expr[i])){
            void *p=malloc(1);
            printf("%c\t%p\tIdentifier\n",expr[i],p);
        }
        else if(expr[i]=='+' || expr[i]=='-' || expr[i]=='*' || expr[i]=='='){
            void *p=malloc(1);
            printf("%c\t%p\tOperator\n",expr[i],p);
        }
    }
    return 0;
}
