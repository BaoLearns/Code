#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 1000000
int dp[30][maxn];
int wi[30][maxn];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for( int i = 0; i < m; ++i)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        wi[x][y]=z;
    }
    int ans=0;
    for( int i = 1; i <= n; ++i)
    {
        if(wi[i-1][i])
        for( int j = 0; j <= 100; ++j)
        {
            dp[i][j]=dp[i-1][j] + wi[i-1][i];
            ans=max(ans,dp[i][j]);
        }
    }
    /*for(int i = 1; i <= n; ++i)
        for(int j = 0; j < 100; ++i)
            printf("%d\t",dp[n][k]);*/
            printf("%d\n",ans);
    return 0;
}
