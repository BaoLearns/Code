//¹¹ÔìÊý¶À
#include <iostream>
#include <cstring>
#define MAXN 10
using namespace std;
int maze[MAXN][MAXN];
bool row[MAXN][MAXN], col[MAXN][MAXN], G[MAXN][MAXN];
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
bool check(int cnt)
{
    if(cnt == 81)
    {
        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
                printf("%d%c", maze[i][j], j < 8? ' ': '\n');
        }
        puts("------------------------------------------");
        return true;
    }
}
bool dfs(int x, int y, int cnt)
{
    //cout << x << " " << y << endl;
    //cout << cnt << " ";
    for(int i = 1; i <= 9; ++i)
    {
        int k = x / 3 * 3 + y / 3;
        if(!row[x][i] && !col[y][i] && !G[k][i])
        {
            maze[x][y] = i;
            row[x][i] = col[y][i] = G[k][i] = true;
            check(cnt + 1);
            for(int j = 0; j < 4; ++j)
            {
                int dx = x + dir[j][0], dy = y + dir[j][1];
                if(dx >= 0 && dx < 9 && dy >= 0 && dy < 9 && maze[dx][dy] == 0)
                    dfs(dx, dy, cnt + 1);
            }
            row[x][i] = col[y][i] = G[k][i] = false;
            maze[x][y] = 0;
        }
    }
    return false;
}
int main()
{
    memset(row, false, sizeof row);
    memset(col, false, sizeof col);
    memset(G, false, sizeof G);
    dfs(0, 0, 0);
    return 0;
}
