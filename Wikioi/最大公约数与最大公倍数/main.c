#include <stdio.h>
int num=1;
int ff(int n)
{
    int i;
    for(i=n/2;i>0;i--)
        ff(n/2);
    num++;
    return num;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",ff(n));
    return 0;
}
