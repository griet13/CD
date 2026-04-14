#include <stdio.h>
#include <string.h>
int main(){
    char prod[10][20],in[20],stack[20];
    int n,top=0,ip=0,len;
    printf("Enter number of productions: ");
    scanf("%d",&n);
    printf("Enter productions (E=E+E):\n");
    for(int i=0;i<n;i++){
        scanf("%s",prod[i]);
    }
    printf("Enter input string ending with $: ");
    scanf("%s",in);
    stack[top]='$';
    stack[top+1]='\0';
    printf("\nStack\tInput\n");
    printf("%s\t%s\n",stack,&in[ip]);
    while(in[ip]!='$'){
        stack[++top]=in[ip++];
        stack[top+1]='\0';
        printf("Shift\n");
        printf("%s\t%s\n",stack,&in[ip]);
        for(int i=0;i<n;i++){
            len=strlen(prod[i])-3;
            if (top>=len && !strncmp(&stack[top-len+1],&prod[i][3],len)){
                top-=len;
                stack[top]=prod[i][0];
                stack[top+1]='\0';
                printf("Reduce %s\n",prod[i]);
                printf("%s\t%s\n",stack,&in[ip]);
            }
        }
    }
    if(stack[1]==prod[0][0] && stack[2]=='\0'){
        printf("Accepted\n");
    }
    else{
        printf("Rejected\n");
    }
    return 0;
}
