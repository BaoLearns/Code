#include <iostream>
#include <algorithm>
#define MAXN 101
using namespace std;
int maze[MAXN][MAXN];
int d[MAXN][MAXN];
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int n, m;
int dfs(int x, int y)
{
    if(d[x][y] > 1) return d[x][y];
    for(int i = 0; i < 4; ++i)
    {
        int dx = x + dir[i][0], dy = y + dir[i][1];
        if(dx >= 0 && dx < n && dy >= 0 && dy < m && maze[x][y] > maze[dx][dy])
            d[x][y] = max(d[x][y], dfs(dx, dy) + 1);
    }
    return d[x][y];
}
int main()
{
    for(int i = 0; i < MAXN; ++i)
        fill(d[i], d[i] + MAXN, 1);
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> maze[i][j];
    int ans = 1;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            ans = max(ans, dfs(i, j));
    cout << ans << endl;
    return 0;
}
