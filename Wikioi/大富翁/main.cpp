#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[10000];
int hash[10000];
int dp[10000];
int main()
{
    int m,n;
    while(~scanf("%d%d",&n,&m))
    {
        int x,y;
        for( int i = 0; i < m; ++i)
        {
            scanf("%d%d",&x,&y);
            hash[x]=y;
        }
        dp[1]=0;
        for( int i = 2; i <= n; ++i)
        {
            dp[i]=-100000;
            for( int j = 1 ; j <= 6 && i - j >= 0; ++j)
            {
                dp[i]=max(dp[i],dp[i-j]+1);
            }
        }
        printf("%d\n",dp[n]);
    }

    return 0;
}
