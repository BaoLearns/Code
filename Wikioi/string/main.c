#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 200010
char s[max];
char stack[max];
int front;
void ff(int n)
{
    if(n>=0 && stack[n]==stack[n-1])
        ff(--front);
}
int main()
{
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    int i;
    while(~scanf("%s",s))
    {
        front=-1;
        for(i=0;i<strlen(s);++i)
        {
            if(stack[front]==s[i])
                ff(--front);
            else
                stack[++front]=s[i];
        }
        for(i=0;i<=front;++i)
            printf("%c",stack[i]);
        putchar('\n');
    }
    return 0;
}
