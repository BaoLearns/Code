#include <iostream>
#include <algorithm>
#define MAXN 55
#define MOD 1000000007
#define LL long long
using namespace std;
int n, m, k, maze[MAXN][MAXN];
int dir[2][2] = {0, 1, 1, 0};
LL ans = 0;
LL C(int n, int m)
{
    LL sum = 1, num = 1;
    while(num++ <= m) sum *= n--;
    while(m) sum /= m--;
    return sum;
}
void dfs(int x, int y, int arr[], int num)
{
    if(x == n - 1 && y == m - 1)
    {
        for(int i = 0; i < num; ++i) cout << arr[i] << " ";
        cout << endl;
        int dp[MAXN * MAXN];
        for(int i = 0; i < num; ++i)
        {
            dp[i] = 1;
            for(int j = i - 1; j >= 0; --j)
            {
                if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            cout << dp[i] << endl;
            if(dp[i] >= k)
            {
                ans %= MOD;
                ans += dp[i] == k? 1: C(dp[i] - 1, k - 1);
            }
        }
        cout << ans << endl;
        return;
    }
    arr[num] = maze[x][y];
    ffor(int i = 0; i < 2; ++i)
    {
        int dx = x + dir[i][0], dy = y + dir[i][1];
        if(dx >= 0 && dx < n && dy >= 0 && dy < m)
        {
            arr[num] = maze[dx][dy];
            dfs(dx, dy, arr, num + 1);
        }
    }
}
int main()
{
    cout << C(6, 2) << endl;
    int arr[MAXN * MAXN];
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> maze[i][j];
    arr[0] = maze[0][0];
    dfs(0, 0, arr,  1);
    cout << ans % MOD << endl; 
    return 0;
}
