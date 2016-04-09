#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
#define INF 100000000
#define max 100
typedef pair <int ,int > p;
char maze[max][max];
int d[max][max];
int n,m;
int sx=0,sy=0;
int ex,ey;
queue <p> que;
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int bfs()
{
    while(que.size())
    {
        p e=que.front();
        que.pop();
        printf("%d,%d\n",e.first,e.second);
        if(e.first == ex && e.second == ey)
            break;
        for(int i=0;i<4;++i)
        {
            int dx=e.first + dir[i][0],dy=e.second + dir[i][1];
            if(0<=dx && dx < n && 0<=dy && dy < m && maze[dx][dy]!='#' && d[dx][dy]==INF)
            {
                que.push(p(dx,dy));
                d[dx][dy]=d[e.first][e.second] + 1;
            }
        }

    }
    return d[ex][ey];
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>maze[i];
    ex=n-1,ey=m-1;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            d[i][j]=INF;
    que.push(p(0,0));
    d[sx][sy]=0;
    cout<<bfs()<<endl;
    return 0;
}
