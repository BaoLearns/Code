/*#include <iostream>
#include <algorithm>
#define maxn 1001
using namespace std;
int V[maxn],W[maxn];
int n, w;
int res(int i, int j)
{
    int ans;
    if(i >= n)
        ans = 0;
    else if(j < W[i])
        ans = res(i + 1, j);
    else
        ans = max(res(i + 1, j), res(i + 1, j - W[i]) + V[i]);
    return ans;
}
int main()
{
    cin >> n >> w;
    for(int i = 0; i < n; ++i)
        cin >> V[i] >> W[i];
    cout << res(0, w) << endl;
    return 0;
}
*/
/*
4 5
3 2
2 1
4 3
2 2
*/

#include <iostream>
#include <cstdio>
#define MAXN 1007
using namespace std;
int dp[MAXN][MAXN];
int main()
{
    int n, w;
    int V[MAXN], W[MAXN];
    cin >> n >> w;
    for(int i = 0; i < n; ++i)
       cin >> W[i] >> V[i];
    for(int i = n - 1; i >= 0; --i)
    {
        for(int j = 0; j <= w; ++j)
        {
            if(W[i] > j)
                dp[i][j] = dp[i + 1][j];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - W[i]] + V[i]);
        }
    } 
    cout << dp[0][w] << endl;
    return 0;
}
