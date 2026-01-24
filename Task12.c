#include <stdio.h>
#include <string.h>
struct reg{
    char var;
}r[10];
int noreg=0;
char code[10][10];
char *opcode(char op){
    if (op=='+') return "ADD";
    if (op=='-') return "SUB";
    if (op=='*') return "MUL";
    if (op=='/') return "DIV";
    return "";
}
int inreg(char v){
    for(int i=1;i<=noreg;i++){
        if(r[i].var==v){
            return i;
        }
    }
    return 0;
}
int main() {
    int n,r1,r2;
    printf("Enter number of statements: ");
    scanf("%d",&n);
    printf("Enter statements (e.g a=b+c):\n");
    for(int i=0;i<n;i++){
        scanf("%s",code[i]);
    }
    printf("\nStatements\tTarget Code\n");
    for(int i=0;i<n;i++) {
        printf("%s\t\t",code[i]);
        r1=inreg(code[i][2]);
        if(!r1){
            r1=++noreg;
            r[r1].var=code[i][2];
            printf("MOV %c,R%d\n\t\t",code[i][2],r1);
        }
        r2=inreg(code[i][4]);
        if(r2){
            printf("%s R%d,R%d\n",opcode(code[i][3]),r2,r1);
        }
        else{
            printf("%s %c,R%d\n",opcode(code[i][3]),code[i][4],r1);
        }
        r[r1].var=code[i][0];
        printf("\t\tMOV R%d,%c\n",r1,code[i][0]);
    }
    return 0;
}
