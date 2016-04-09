#include <stdio.h>
#include <string.h>
bool s[1000010];
int main()
{
    int i,j;
    memset(s,true,sizeof(s));
    s[0]=s[1]=false;
    for(i=2;i<=1000000;i++)
    {
        if(!s[i]) continue;
        for(j=2*i;j<=1000000;j+=i)
            s[j]=false;
    }
    int m,x,k;
    while (~scanf("%d%d",&k,&m)&&(k||m))
    {
        x=1;
        for(i=2;i<=1000000 && x;i++)
        {
            for(j=2;j<=1000000 && x;j++)
            if(s[i] && s[j] && i*j==k) x=0;
        }
        if(i-1>m) printf("GOOD\n");
        else printf("BAD %d\n",i-1);
    }
    return 0;
}
