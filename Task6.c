#include <stdio.h>
#include <stdlib.h>
int main(){
    char grm[20][20];
    int n;
    printf("Enter number of productions: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",grm[i]);
    for(int i=0;i<n;i++){
        for(int j=2;grm[i][j]!='\0';j++){
            if(grm[i][j]=='$'){
                printf("Not operator grammar\n");
                exit(0);
            }
            if(grm[i][j]=='+' || grm[i][j]=='-' || grm[i][j]=='*' || grm[i][j]== '/'){
                continue;
            }
            if (grm[i][j]>='A' && grm[i][j]<='Z'){
                continue;
            }
            if (grm[i][j]>='a' && grm[i][j]<='z'){
                continue;
            }
        }
    }
    printf("Operator grammar\n");
    return 0;
}
