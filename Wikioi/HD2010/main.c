#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int s[1000]={0},i;
    for(i=100;i<=999;i++)
    {
        if(pow(i%10,3)+pow(i/10%10,3)+pow(i/100,3)==i)
            s[i]=1;
    }
    int n,m,ant,falg;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ant=0,falg=0;
        for(i=n;i<=m;i++)
        {
            if(s[i])
            {
                if(falg) printf(" ");
                printf("%d",i);
                ant++;
                falg=1;
            }
        }
        if(!ant) printf("no");
        putchar('\n');
    }
    return 0;
}
