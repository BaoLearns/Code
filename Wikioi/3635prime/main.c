#include <stdio.h>
#include <string.h>
int s[1000010];
int main()
{
    int i,j;
    memset(s,1,sizeof(s));
    s[0]=s[1]=0;
    for(i=2;i<=1000000;i++)
    {
        if(!s[i]) continue;
        for(j=2*i;j<=1000000;j+=i)
            s[j]=0;
    }
    int m,x,min,k;
    while (~scanf("%d%d",&k,&m)&&(k||m))
    {
        x=1;
        for(i=2;i<=1000000 && x;i++)
        {
            for(j=2;j<=1000000 && x;j++)
            if(s[i] && s[j] && i*j==k) x=0;
        }
        if(i<j) min=i;
        else min=j;
        if(min-1>m) printf("GOOD\n");
        else printf("BAD %d\n",i-1);
    }
    return 0;
}
