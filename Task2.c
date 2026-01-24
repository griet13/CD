#include <stdio.h>
#include <stdlib.h>
int main(){
    char s[20],c;
    int state=0,i=0;
    printf("Enter string: ");
    scanf("%s",s);
    while((c=s[i++])!='\0'){
        switch(state){
            case 0:
                if(c=='a')
                    state=1;
                else if(c=='b')
                    state=2;
                else
                    state=6;
                break;
            case 1:
                if(c=='a')
                    state=3;
                else if(c=='b')
                    state=4;
                else
                    state=6;
                break;
            case 2:
                if(c=='b')
                    state=2;
                else
                    state=6;
                break;
            case 3:
                if(c=='a')
                    state=3;
                else if(c=='b')
                    state=2;
                else
                    state=6;
                break;
            case 4:
                if(c=='b')
                    state=5;
                else
                    state=6;
                break;
            case 5:
                if(c=='b')
                    state=2;
                else
                    state=6;
                break;
            case 6:
                printf("%s is not recognised\n",s);
                exit(0);
            }
        }
    if (state==1){
        printf("%s accepted under rule 'a'\n",s);
    }
    else if(state==2 || state==4){
        printf("%s accepted under rule 'a*b+'\n",s);
    }
    else if(state==5){
        printf("%s accepted under rule 'abb'\n",s);
    }
    else{
        printf("%s is not recognised\n",s);
    }
    return 0;
}
