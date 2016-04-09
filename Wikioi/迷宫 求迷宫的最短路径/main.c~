//找出迷宫S点到E点最小的路径的步数
/*
4 4
S..#
##..
E..#
####.
6
*/
#include <stdio.h>
#include <stdlib.h>
int min;
//存储地图
char maze[50][50];
int n,m;
//保存S起点的坐标，终点E的坐标
int Sx,Sy,Ex,Ey;
//定义四个方向
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};

void DFS(int x,int y,int step)//深度优先搜索
{
    //当前点不为#时就搜索
    if(x >= 0 && y >= 0 && x<m && y< n && maze[x][y]!='#')
    {
        //处理搜到的点未终点时
        if(x==Ex && y==Ey)
        {
            //比较step步数和min的值
            min=min>step?step:min;
            return ;
        }
        //此点搜索之后就特殊标记，即.
        maze[x][y]='#';
        int i;
        //沿4个方向搜索
        for(i=0;i<4;++i)
        {
            //递归四个方向
            DFS(x+dir[i][0],y+dir[i][1],step+1);
        }
        //递归之后回到处理之前的情况，即#
        maze[x][y]='.';
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        min=1000000;
        int i,j;
        //输入地图
        for(i=0;i<n;++i)
        {
            scanf("%s",maze[i]);
            for(j=0;j<m;++j)
            {
                if(maze[i][j]=='S')
                    Sx=i,Sy=j;
                if(maze[i][j]=='E')
                    Ex=i,Ey=j;
            }
        }
        DFS(Sx,Sy,0);

        printf("%d\n",min);
    }
    return 0;
}
