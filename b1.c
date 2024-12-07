#include "stdio.h"
#include "string.h"
const int MAX = 99;
char a[100] , b[100] , str[100];

void solve(char a[],char b[]) {
    char *pos;
    int lenB = strlen(b);
    while ((pos = strstr(a, b)) != NULL) {
        for (int i = 0; i < lenB; i++) {
            pos[i] = '-';
        }
    }
}
void solve2(char str[], char c)
{
    int len = strlen(str);
    int j = 0;
    for(int i = 0; i < len;i++)
    {
        if(str[i] != c)
        {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

int main ()
{
    printf("Nhap xau a : ");
    fgets(a , sizeof(a), stdin);
    a[strcspn(a,"\n")] = '\0';
    printf("Nhap xau b : ");
    fgets(b,sizeof(b), stdin);
    b[strcspn(b,"\n")] = '\0';
    printf("Nhap xau s : ");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")] = '\0';
    char c;
    printf("Nhap ki tu c can xoa : ");
    scanf("%c", &c );
    solve(a,b);
    printf("Kep qua la : %s\n",a);
    solve2(str,c);
    printf("Xau sau khi xoa ki tu %c la : %s\n",c,str);
	return 0;
}




