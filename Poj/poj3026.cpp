#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXN 51
#define INF 10000007
#define Pii pair <int, int>
using namespace std;
char maze[MAXN][MAXN];
vector <Pii> vec;
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int fa[MAXN * MAXN];
int n, m;
class node
{
public:
    int u, v, cost;
    node(int x, int y, int k)
    {
        u = x;
        v = y;
        cost = k;
    }
};
vector <node> side;
void bfs(int x, int y)
{
    queue <Pii> que;
    que.push(Pii(x, y));
    int d[MAXN][MAXN];
    for(int i = 0; i < MAXN; ++i)
        for(int j = 0; j < MAXN; ++j)
            d[i][j] = INF;
    d[x][y] = 0;
    while(!que.empty())
    {
        Pii e = que.front();
        que.pop();
        for(int i = 0; i < 4; ++i)
        {
            int dx = e.first + d[i][0], dy = e.second + d[i][1];
            if(dx >= 0 && dx < n && dy >= 0 && dy < m && maze[dx][dy] != '#' && d[dx][dy] == INF)
            {
                que.push(Pii(dx, dy));
                d[dx][dy] = d[x][y] + 1;
                if(maze[dx][dy] == 'S' || maze[dx][dy] == 'A')
                   side.push_back(node(x * n + y, dx * n + dy, d[dx][dy])); 
            }
        }
    }
}
int find(int x)
{
    return fa[x] = fa[x] == x? x: find(fa[x]);
}
bool cmp(const node &a, const node &b)
{
    return a.cost < b.cost;
}
void kruskal()
{
    sort(side.begin(), side.end(), cmp);
    for(int i = 0; i < MAXN * MAXN; ++i) fa[i] = i;
    long long ans = 0;
    for(int i = 0; i < side.size(); ++i)
    {
        node e = side[i];
        int fx = find(e.u), fy = find(e.v);
        if(fx != fy)
        {
            ans += e.cost;
            fa[fx] = fy;
        }
    }
    printf("%I64d\n", ans);
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        side.clear();
        vec.clear();
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                scanf("%c", &maze[i][j]);
                if(maze[i][j] == 'S' || maze[i][j] == 'A')
                    vec.push_back(Pii(i, j));
            }
        }
        for(int i = 0; i < vec.size(); ++i)
            bfs(vec[i].first, vec[i].second);
        kruskal();
    }
    return 0;
}
