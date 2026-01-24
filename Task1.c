#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
const char *keys[]={
    "auto","break","case","char","const","continue","default","do","double",
    "else","enum","extern","float","for","goto","if","int","long","register",
    "return","short","signed","sizeof","static","struct","switch","typedef",
    "union","unsigned","void","volatile","while"
};
int isKeyword(char *s){
    for(int i=0;i<32;i++){
        if(!strcmp(s,keys[i])){
            return 1;
        }
    }
    return 0;
}
int main(){
    FILE *fp;
    char f[20],ch,buff[100];
    int i=0;
    printf("Enter file: ");
    scanf("%s", f);
    fp=fopen(f,"r");
    if (!fp) return printf("Cannot open file\n");
    while((ch=fgetc(fp))!=EOF){
        if(ch=='#'){
            while((ch=fgetc(fp))!='\n'){
                putchar(ch);
            }
            printf(" is preprocessor directive\n");
        }
        else if(isalpha(ch) || ch=='_'){
            i=0;
            buff[i++]=ch;
            while(isalnum(ch=fgetc(fp)) || ch=='_'){
                buff[i++]=ch;
            }
            buff[i]='\0';
            ungetc(ch,fp);
            if (isKeyword(buff)){
                printf("%s is keyword\n", buff);
            }
            else{
                printf("%s is identifier\n", buff);
            }
        }
        else if(isdigit(ch)){
            putchar(ch);
            while(isdigit(ch=fgetc(fp)) || ch == '.'){
                putchar(ch);
            }
            ungetc(ch,fp);
            printf(" is number\n");
        }
        else if(ch=='"') {
            putchar('"');
            while ((ch=fgetc(fp))!='"'){
                putchar(ch);
            }
            printf("\" is string\n");
        }
        else if (ch=='/') {
            char n=fgetc(fp);
            if (n=='/'){
                while((ch=fgetc(fp))!='\n'){
                    putchar(ch);
                }
                printf(" is comment\n");
            }
            else if(n=='*'){
                while (!((ch=fgetc(fp))=='*' && fgetc(fp)=='/')){
                    putchar(ch);
                }
                printf(" is comment\n");
            }
            else{
                ungetc(n,fp);
            }
        }
        else if(strchr("+-*/%=<>!&|",ch)){
            printf("%c is operator\n",ch);
        }
        else if(strchr("(){}[]",ch)){
            printf("%c is special symbol\n", ch);
        }
        else if(ch==';'){
            printf("; is terminator\n");
        }
    }
    fclose(fp);
    return 0;
}
