#include <stdio.h>
#include <stdlib.h>
char maze[50][50];
int n,m;
int Sx,Sy,Ex,Ey;
int count=0;
int dir[8][2]={{0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
bool find()
{
    int i,j;
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        {
            if(maze[i][j])
             {
                ++count;
                Sx=i,Sy=j;
                return true;
             }
        }
    }
    return false;
}
void DFS(int x,int y,int step)
{
    if(x >= 0 && y >= 0 && x<m && y< n && maze[x][y]=='W')
    {
        maze[x][y]='.';
        int i;
        for(i=0;i<8;++i)
            DFS(x+dir[i][0],y+dir[i][1],step+1);
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        count=0;
        int i,j;
        for(i=0;i<n;++i)
        {
            scanf("%s",maze[i]);

        }
        while(find())
            DFS(Sx,Sy,0);
        printf("%d\n",count);
    }
    return 0;
}
