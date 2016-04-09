#include <stdio.h>
//定义一个栈，用于存放路径
struct stack
{
    //x标记入栈的横坐标
    int x;
    //y标记入栈的纵坐标
    int y;
    char from;
}stack[ 100];
int main()
{
    //初始化迷宫，0表示墙不可通，1表示可通
    //起点是（1,1），终点是（6,6）
    int maze[8][8]={{0,0,0,0,0,0,0,0},
                    {0,1,1,1,1,1,1,0},
                    {0,0,0,1,0,1,1,0},
                    {0,0,0,1,0,1,1,0},
                    {0,0,0,1,1,0,0,0},
                    {0,0,0,1,0,0,1,0},
                    {0,0,0,1,1,1,1,0},
                    {0,0,0,0,0,0,0,0}
                    };
    //初始化栈顶的坐标
    int top = -1;
    //初始化起点
    int dx=1,dy=1;
    stack[ top].x = stack[ ++top].y = 1;
    while( maze[6][6] != 2)//当终点没有被遍历是就一直搜索
    {
        printf("(%d,%d)\n",stack[top].x,stack[top].y);
            if(maze[dx][dy+1] ==1) //遍历右方向
            {
                ++dy;
                maze[ dx][ dy] = 2;//遍历之后就将此点赋值为2
                stack[ ++top].x = dx;//入栈
                stack[ top].y = dy;
                stack[top].from='W';
                continue;
            }
            //如果右方向不通则遍历下方向
            if(maze[dx+1][dy] ==1)
            {
                ++dx;
                maze[ dx][ dy] = 2;//遍历之后就将此点赋值为2
                stack[ ++top].x = dx;
                stack[ top].y = dy;
                stack[ top].from='N';
                continue;
            }
            //如果下方向不通则遍历左方向
            if(maze[dx][dy-1] ==1)
            {
                --dy;
                maze[ dx][ dy] = 2;//遍历之后就将此点赋值为2
                stack[ ++top].x = dx;
                stack[ top].y = dy;
                stack[ top].from='E';
                continue;
            }
            //如果左方向不通则遍历上方向
            if(maze[dx-1][dy] ==1)
            {
                --dx;
                maze[ dx][ dy] = 2;//遍历之后就将此点赋值为2
                stack[ ++top].x = dx;
                stack[ top].y = dy;
                stack[ top].from='S';
                continue;
            }
        //若四个方向抖不能走通则往回倒退一个，也就是出栈
        if(stack[top].from=='W')
            --dy;
        else if(stack[ top].from=='N')
            --dx;
        else if(stack[ top].from=='E')
            ++dy;
        else
            ++dx;
        --top;
    }
    int i;
    printf("---------------\n");
    for(i = 0; i <= top; ++i)
        printf("(%d,%d)\n",stack[i].x,stack[i].y);
    return 0;
}
