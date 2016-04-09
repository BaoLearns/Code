#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int dp[5010][5010];
int main()
{
    freopen("beckham.in","r",stdin);
    freopen("beckham.out","w",stdout);
    int n,v;
    int w[100],p[100];
    while(~scanf("%d%d",&n,&v))
    {
        memset(dp,0,sizeof(dp));
        for( int i = 1; i <= n; ++i)
            scanf("%d%d",w+i,p+i);
        int val=0;
        for(int i=1;i<=n;i++)
        {
            for(int j = v; j >= 0; j--)
            {
                if(j>=w[i])
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+p[i]);
                else
                    dp[i][j]=dp[i-1][j];
                val=max(val,dp[i][j]);
            }
        }
        printf("%d\n",val);
    }
    return 0;
}
