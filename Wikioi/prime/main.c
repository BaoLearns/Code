#include <stdio.h>
#include <string.h>
#define N 1000000
int s[N];
int main()
{
    memset(s,1,sizeof(s));
    int i,j;
    s[0]=s[1]=0;
    for(i=2;i<=N;i++)
    {
        if(!s[i]) continue;
        for(j=2*i;j<=N;j+=i)
            s[j]=0;
    }
    for(i=2;i<=N;i++)
        if(s[i]) printf("%d  ",i);
    return 0;
}
