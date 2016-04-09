//�ҳ��Թ�S�㵽E����С��·���Ĳ���
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
//�洢��ͼ
char maze[50][50];
int n,m;
//����S�������꣬�յ�E������
int Sx,Sy,Ex,Ey;
//�����ĸ�����
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};

void DFS(int x,int y,int step)//�����������
{
    //��ǰ�㲻Ϊ#ʱ������
    if(x >= 0 && y >= 0 && x<m && y< n && maze[x][y]!='#')
    {
        //�����ѵ��ĵ�δ�յ�ʱ
        if(x==Ex && y==Ey)
        {
            //�Ƚ�step������min��ֵ
            min=min>step?step:min;
            return ;
        }
        //�˵�����֮��������ǣ���.
        maze[x][y]='#';
        int i;
        //��4����������
        for(i=0;i<4;++i)
        {
            //�ݹ��ĸ�����
            DFS(x+dir[i][0],y+dir[i][1],step+1);
        }
        //�ݹ�֮��ص�����֮ǰ���������#
        maze[x][y]='.';
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        min=1000000;
        int i,j;
        //�����ͼ
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
