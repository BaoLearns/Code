#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct st
{
    int x;
    int y;
    char val;
}stack[100];

int main()
{
    int n,i,j;
    scanf("%d",&n);
    int m;
    scanf("%d",&m);
    char maz[n+2][n+2];
    for(i=0;i<n+2;++i)
        for(j=0;j<n+2;++j)
            maz[i][j]='#';


    for(i=0;i<=n;++i)
        gets(maz[i]+1);
    for(i=0;i<n+2;++i)
    {
        for(j=0;j<n+2;++j)
            printf("%c",maz[i][j]);
        putchar('\n');
    }
    while(m--)
    {
        int cnt=1;
        int top=0;
        int dx,dy;
        char maze[n+2][n+2];
        for(i=0;i<=n+2;++i)
            strcpy(maze[i],maz[i]);
        scanf("%d%d",&dx,&dy);

        stack[top].x=dx;
        stack[top].y=dy;
        stack[top].val=maze[dx][dy];
        while(1)
        {

            printf("(%d,%d)\n",stack[top].x,stack[top].y);
            if(top<0)
                break;
            if(abs(maze[dx][dy+1] -stack[top].val)==1) //�����ҷ���
            {
                ++dy;
                maze[ dx][ dy] = '2';//����֮��ͽ��˵㸳ֵΪ2
                stack[ ++top].x = dx;//��ջ
                stack[ top].y = dy;
                stack[top].val=maze[dx][dy];
                ++cnt;
                continue;
            }
            //����ҷ���ͨ������·���
            if(abs(maze[dx][dy+1] -stack[top].val)==1)
            {
                ++dx;
                maze[ dx][ dy] = '2';//����֮��ͽ��˵㸳ֵΪ2
                stack[ ++top].x = dx;
                stack[ top].y = dy;
                stack[top].val=maze[dx][dy];
                ++cnt;
                continue;
            }
            //����·���ͨ���������
            if(abs(maze[dx][dy+1] -stack[top].val)==1)
            {
                --dy;
                maze[ dx][ dy] = '2';//����֮��ͽ��˵㸳ֵΪ2
                stack[ ++top].x = dx;
                stack[ top].y = dy;
                stack[top].val=maze[dx][dy];
                ++cnt;
                continue;
            }
            //�������ͨ������Ϸ���
            if(abs(maze[dx][dy+1] -stack[top].val)==1)
            {
                --dx;
                maze[ dx][ dy] = '2';//����֮��ͽ��˵㸳ֵΪ2
                stack[ ++top].x = dx;
                stack[ top].y = dy;
                stack[top].val=maze[dx][dy];
                ++cnt;
                continue;
            }
        //���ĸ����򶶲�����ͨ�����ص���һ����Ҳ���ǳ�ջ
        --top;
        //--cnt;
        dx=stack[top].x;
        dy=stack[top].y;
        }
        for(i=0;i<n+2;++i)
        {
            for(j=0;j<n+2;++j)
                printf("%c",maz[i][j]);
            putchar('\n');
        }
        printf("%d\n",cnt);
    }

    return 0;
}
