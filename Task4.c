#include <stdio.h>
#include <string.h>
#include <ctype.h>

char a[10][10], f[10];
int n, m = 0;
void first(char c);
void follow(char c);

int main() {
    int i, j, x, n1;
    char t[10];
    printf("Enter no of terminals: ");
    scanf("%d %s", &n1, t);
    printf("Enter no of productions: ");
    scanf("%d", &n);
    printf("Enter productions:\n");
    for(i = 0; i < n; i++)
        scanf("%s", a[i]);
    for(i = 0; i < n1; i++)
        printf("\t%c", t[i]);
    printf("\n");
    for(i = 0; i < n; i++) {
        if(islower(a[i][2]) && a[i][2] != 'e') {
            printf("%c\t", a[i][0]);
            for(x = 0; x < n1; x++) {
                if(a[i][2] == t[x])
                    printf("%c->%s", a[i][0], a[i]+2);
                printf("\t");
            }
            printf("\n");
        }
        else if(isupper(a[i][2])) {
            m = 0;
            first(a[i][2]);
            for(j = 0; j < m; j++) {
                if(f[j] == 'e') {
                    m = 0;
                    follow(a[i][0]);
                }
            }
            printf("%c\t", a[i][0]);
            for(j = 0; j < m; j++) {
                for(x = 0; x < n1; x++) {
                    if(f[j] == t[x])
                        printf("%c->e", a[i][0]);
                    printf("\t");
                }
            }
            printf("\n");
        }
    }
    return 0;
}

void first(char c) {
    if(!isupper(c)) {
        f[m++] = c;
        return;
    }

    for(int k = 0; k < n; k++) {
        if(a[k][0] == c) {
            if(a[k][2] == 'e')
                follow(a[k][0]);
            else if(islower(a[k][2]))
                f[m++] = a[k][2];
            else
                first(a[k][2]);
        }
    }
}

void follow(char c) {
    if(a[0][0] == c)
        f[m++] = '$';
    for(int k = 0; k < n; k++) {
        for(int l = 2; l < strlen(a[k]); l++) {
            if(a[k][l] == c) {
                if(a[k][l+1] != '\0')
                    first(a[k][l+1]);
                else if(c != a[k][0])
                    follow(a[k][0]);
            }
        }
    }
}
