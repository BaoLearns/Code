#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
#define INF 100000000
typedef pair <int ,int > p;
char maze[22][22];
int d[22][22];
int n,m,t,sx,sy,ex,ey,lockx,locky,keyx,keyy;
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int bfs(int s1,int s2,int e1,int e2)
{

    queue <p> que;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            d[i][j]=INF;
    que.push(p(s1,s2));
    d[s1][s2]=0;
    while(que.size())
    {
        p e=que.front();
        que.pop();
        if(e.first==e1 && e.second==e2)
            break;
        for(int i=0;i<4;++i)
        {
            int dx=e.first + dir[i][0],dy=e.second + dir[i][1];
            if(0<=dx && dx < n && 0<=dy && dy < m && maze[dx][dy]!='*' && d[dx][dy]==INF && maze[dx][dy]!='A')
            {
                que.push(p(dx,dy));
                d[dx][dy]=d[e.first][e.second] + 1;
            }
        }

    }
    return d[e1][e2];
}
int main()
{
    freopen("escape.in","r",stdin);
    freopen("escape.out","w",stdout);
    while(scanf("%d%d%d",&n,&m,&t))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%s",maze[i]);
            for(int j=0;j<m;++j)
            {
                if(maze[i][j]=='@')
                    sx=i,sy=j;

                if(maze[i][j]=='^')
                    ex=i,ey=j;

                if(maze[i][j]=='A')
                    lockx=i,locky=j;

                if(maze[i][j]=='a')
                    keyx=i,keyy=j;
            }
        }
        maze[sx][sy]='.';
        int st3=bfs(sx,sy,ex,ey);
        int st1=bfs(sx,sy,keyx,keyy);
        maze[lockx][locky]='.';
        int st2=bfs(keyx,keyy,ex,ey);
        if(st1+st2<t || st3<t)
        {
            if(st1+st2>st3)
                printf("%d\n",st3);
            else
                printf("%d\n",st1+st2);
        }
        else
            printf("-1\n");
    }
    return 0;
}
