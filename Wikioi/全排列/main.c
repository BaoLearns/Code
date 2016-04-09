#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
void find(int *hash,int ans,int m)
{
    int i;
    if(n==m)
        printf("%d\n",ans);

    for( i=0;i<10;++i)
    {
        if(hash[i])
        {
            hash[i]--;
            find(hash,ans*10+i,m+1);
            hash[i]++;
        }
    }
}
int main()
{
    int hash[100],i;
    while(scanf("%d",&n))
    {
        memset(hash,0,sizeof(hash));
        for(i=1;i<=n;++i)
        {
            hash[i]++;
        }

        find(hash,0,0);
    }
    return 0;
}
