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
            if(abs(maze[dx][dy+1] -stack[top].val)==1) //遍历右方向
            {
                ++dy;
                maze[ dx][ dy] = '2';//遍历之后就将此点赋值为2
                stack[ ++top].x = dx;//入栈
                stack[ top].y = dy;
                stack[top].val=maze[dx][dy];
                ++cnt;
                continue;
            }
            //如果右方向不通则遍历下方向
            if(abs(maze[dx][dy+1] -stack[top].val)==1)
            {
                ++dx;
                maze[ dx][ dy] = '2';//遍历之后就将此点赋值为2
                stack[ ++top].x = dx;
                stack[ top].y = dy;
                stack[top].val=maze[dx][dy];
                ++cnt;
                continue;
            }
            //如果下方向不通则遍历左方向
            if(abs(maze[dx][dy+1] -stack[top].val)==1)
            {
                --dy;
                maze[ dx][ dy] = '2';//遍历之后就将此点赋值为2
                stack[ ++top].x = dx;
                stack[ top].y = dy;
                stack[top].val=maze[dx][dy];
                ++cnt;
                continue;
            }
            //如果左方向不通则遍历上方向
            if(abs(maze[dx][dy+1] -stack[top].val)==1)
            {
                --dx;
                maze[ dx][ dy] = '2';//遍历之后就将此点赋值为2
                stack[ ++top].x = dx;
                stack[ top].y = dy;
                stack[top].val=maze[dx][dy];
                ++cnt;
                continue;
            }
        //若四个方向抖不能走通则往回倒退一个，也就是出栈
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
