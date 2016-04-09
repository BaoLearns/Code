#include <stdio.h>
//定义一个栈，用于存放路径
struct stack
{
    //x标记入栈的横坐标
    int x;
    //y标记入栈的纵坐标
    int y;
}stack[ 100];
int main()
{
    //初始化迷宫，0表示墙不可通，1表示可通
    //起点是（1,1），终点是（6,6）
    int maze[8][8]={{0,0,0,0,0,0,0,0},
                    {0,1,1,1,1,1,0,0},
                    {0,0,0,1,0,1,1,0},
                    {0,0,0,1,0,1,1,0},
                    {0,0,0,1,1,0,1,0},
                    {0,0,0,1,0,0,0,0},
                    {0,0,0,1,1,1,1,0},
                    {0,0,0,0,0,0,0,0}
                    };
    //定义四个方向，先向右搜索，若右不通则向下搜索，若向下也不通则向左搜索，若向下搜索不通则向上搜索
    int dir[ 4][ 2] = {{ 0 , 1} , { 1 , 0} , { 0 , -1} , { -1, 0}};
    //top指针用于指向栈顶
    int top = -1;
    int i;
    //初始化起点
    int dx=1,dy=1;
    stack[ top].x = stack[ ++top].y = 1;
    while( maze[6][6] != 2)//当终点没有被遍历是就一直搜索
    {
        printf("(%d,%d)\n",stack[top].x,stack[top].y);
        for( i = 0;i < 4; ++i)
        {
            int n1 = dx, n2 = dy;

            dx += dir[ i][ 0],dy += dir[ i][ 1];
            if( maze[ dx][ dy] == 1)//如果未1则入栈
            {
                maze[ dx][ dy] = 2;//遍历之后就将此点赋值为2
                stack[ ++top].x = dx;
                stack[ top].y = dy;
                break;
            }
            dx = n1;
            dy = n2;
        }
        if(i >= 4)//当i大于等于4时就说明四个方向都遍历过了，即四个方向都不通
        {
            --top;
            dx = stack[ top].x;
            dy = stack[ top].y;
        }
    }
    for(i = 0; i <= top; ++i)
        printf("(%d,%d)\n",stack[i].x,stack[i].y);
    return 0;
}
