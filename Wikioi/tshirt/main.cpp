#include <iostream>
#include <stdio.h>
#include <algorithm>
#define INF 1000001
using namespace std;
int dp[1001][1001];
int ed[1001][1001];
int main()
{
    freopen("tshirt.in","r",stdin);
    freopen("tshirt.out","w",stdout);
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i = 1; i <= n; ++i)
            for( int j = 1; j <= n; ++j)
                dp[i][j]=INF;
        for( int i = 1; i <= n; ++i)
        {
            //dp[i][i]=0;
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            dp[x][y]=z;
            dp[y][x]=z;
        }
        int ans=INF;
        for( int k = 1; k <= n; ++k)
            for( int i = 1; i <= n; ++i)
                for( int j = 1; j <= n; ++j)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k] + dp[k][j]);
                    ans=min(ans,dp[i][j]);
                }
        printf("%d\n",ans);
    }
    return 0;
}
