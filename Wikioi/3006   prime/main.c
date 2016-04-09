#include <stdio.h>
#include <string.h>
bool s[1000010];
int main()
{
    memset(s,true,sizeof(s));
    int i,j;
    s[0]=s[1]=false;
    for(i=2;i<=1000000;i++)
    {
        if(s[i])
        for(j=i*2;j<=1000000;j=j+i)
            s[j]=false;
    }
    int a,d,n,num;
    while(~scanf("%d%d%d",&a,&d,&n)&&(a||d||n))
    {
        num=0;
         for(i=a;i<=1000000;i+=d)
        {
           if(s[i])
                if(++num==n)
                {
                printf("%d\n",i);
                break;
                }
        }
    }
    return 0;
}
