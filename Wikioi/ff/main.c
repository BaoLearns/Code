#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *avgc[])
{
    char s[100];
    char *p=s;
    int n;
    gets(s);
    scanf("%d",&n);
    n--;
    while(s[n]!='\0')
    {
    printf("%c",*(p+n));
    n++;
    }
    printf("\n");
    return 0;
}
