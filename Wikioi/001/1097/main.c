#include <stdio.h>
#include <stdlib.h>
struct name
{
    int x;
    int y;
}s[10020];
int main()
{

    int n,m,i,j;
    int max=0,min=0;
    scanf("%d%d",&n,&m);
    while (m--)
    {
        scanf("%d%d",&s[m].x,&s[m].y);
    }
    for(i=1;i<=m;i++)
    {
        for(j=i+1;j<=m;j++)
            if((s[j].x<=s[i].y &&s[i].y>=s[j].y)||(s[i].x<=s[j].y &&s[j].y>=s[i].y))
        {
            if (s[i].x<s[j].x) min=i;
            else min =j;
            if (s[i].y<s[j].y) max=j;
            else max=i;
            m--;
            s[m].x=min,s[m].y=max;
        }
    }
    int sum=0;
    for(i=1;i<=m;i++)
        sum=sum+s[i].y-s[i].x+1;
    printf("%d",n-sum-1);
    return 0;
}
