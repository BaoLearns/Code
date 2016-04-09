#include <stdio.h>
#define N 1000
int s[N]={1};
int main()
{
    int i,j;
    s[0]=s[1]=0;
    for(i=4;i<=N;i++)
    {
        if(s[i]) continue;
        for(j=2;j<i;j++)
        {
            if(i%j==0)
                for(j=i;j<=N;j=+i)
                s[j]=0;
        }
    }
    for(i=2;i<=N;i++)
        if(s[i]) printf("%d  ",i);
    return 0;
}
