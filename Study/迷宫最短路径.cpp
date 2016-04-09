#include <iostream>
#include <queue>
#define maxn 100
#define INF 100000000
using namespace std;
typedef pair<int , int> P;
int d[maxn][maxn];
char maze[maxn][maxn];
int dir[4][2] = {1,0,0,-1,-1,0,0,1};
int n, m;
int bfs(int sx, int sy, int ex, int ey)
{
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            d[i][j] = INF;
    queue <P> que;
    que.push(P(sx, sy));
    maze[sx][sy] = '#';
    d[sx][sy] = 0;
    while(que.size())
    {
        P p = que.front();
        que.pop();
        if(p.first == ex && p.second == ey)
            return d[ex][ey];
        for(int i = 0; i < 4; ++i)
        {
            int dx = p.first + dir[i][0], dy = p.second + dir[i][1];
            if(maze[dx][dy] != '#' && dx >= 0 && dx < n && dy >= 0 && dy < m && d[dx][dy] == INF)
            {
                que.push(P(dx, dy));
                d[dx][dy] = d[p.first][p.second] + 1;
            }
        }
    }
    return INF + 1;
}
int main()
{
    cin>>n>>m;
    int sx, sy, ex, ey;
    for(int i = 0; i < n; ++i)
    {
        cin>>maze[i];
        for(int j = 0; j < m; ++j)
        {
            if(maze[i][j] == 'S')
                sx = i, sy = j;
            if(maze[i][j] == 'G')
                ex = i, ey = j;
        }
    }
    int num = bfs(sx, sy, ex, ey);
    cout<<(num != INF? num: -1)<<endl;
    return 0;
}
