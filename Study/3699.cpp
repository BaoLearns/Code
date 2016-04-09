#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#define maxn 50005
#define MAXN 405
#define INF 1000000005
#define LL long long
using namespace std;
typedef struct node
{
    int x, y, t;
    bool operator <(const node a)const
    {
        return t < a.t;
    }
}Node;
Node arr[maxn];
int M;
LL maze[MAXN][MAXN];  //步数
bool vised[MAXN][MAXN];  //是否可以走
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};  //方向
bool bfs()  //广搜
{
    queue <pair<int, int> > que;
    que.push(make_pair(0, 0));
    for(int i = 0; i < MAXN; ++i)
        for(int j = 0; j < MAXN; ++j)
            maze[i][j] = INF;
    maze[0][0] = 0;
    int start = 0;
    for(int i = 0; i < M; ++i)
    {
        int end = arr[i].t;
        int count = end - start;
        start = end;
        while(count--)  //陨石到达之前走count步
        {
            int size = que.size();
            while(size--){
            pair<int, int> e = que.front();
            que.pop();
            if(maze[e.first][e.second] == INF || vised[e.first][e.second])
                continue;
            for(int j = 0; j < 4; ++j)
            {
                int dx = e.first + dir[j][0], dy = e.second + dir[j][1];
                if(dx >= 0 && dy >= 0 && maze[dx][dy] == INF && !vised[dx][dy])
                {
                    que.push(make_pair(dx, dy));
                    maze[dx][dy] = maze[e.first][e.second] + 1;
                }
            }
            }
        }
        //陨石到达，哪些地方不能走
        vised[arr[i].x][arr[i].y] = true;
        maze[arr[i].x][arr[i].y] = INF;
        for(int j = 0; j < 4; ++j)
        {
            int dx = arr[i].x + dir[j][0], dy = arr[i].y + dir[j][1];
            vised[dx][dy] = true;
            maze[dx][dy] = INF;
        }
    }
    return true;
}
int main()
{
    cin >> M;
    for(int i = 0; i < M; ++i)
        scanf("%d%d%d", &arr[i].x, &arr[i].y, &arr[i].t);
    sort(arr, arr + M);
    bfs();
    LL ans = INF;
    for(int i = 0; i < MAXN; ++i)
        for(int j = 0; j < MAXN; ++j)
            if(maze[i][j] != INF)
                ans = min(ans, maze[i][j]);
    cout << (ans == INF? -1: ans) << endl;
    return 0;
}
/*
4
0 0 2
2 1 2
1 1 2
0 3 5
*/
