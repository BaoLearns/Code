#include <stdio.h>
#include <stdlib.h>
long ff(long n)
{
    if(n==0) return 7;
    if(n==1) return 11;
    else return ff(n-1)+ff(n-2);
}
int main()
{
    long n;
    while (scanf("%ld",&n)!=EOF)
    {

        if(ff(n)%3==0) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
