#include <stdio.h>
//����һ��ջ�����ڴ��·��
struct stack
{
    //x�����ջ�ĺ�����
    int x;
    //y�����ջ��������
    int y;
    char from;
}stack[ 100];
int main()
{
    //��ʼ���Թ���0��ʾǽ����ͨ��1��ʾ��ͨ
    //����ǣ�1,1�����յ��ǣ�6,6��
    int maze[8][8]={{0,0,0,0,0,0,0,0},
                    {0,1,1,1,1,1,1,0},
                    {0,0,0,1,0,1,1,0},
                    {0,0,0,1,0,1,1,0},
                    {0,0,0,1,1,0,0,0},
                    {0,0,0,1,0,0,1,0},
                    {0,0,0,1,1,1,1,0},
                    {0,0,0,0,0,0,0,0}
                    };
    //��ʼ��ջ��������
    int top = -1;
    //��ʼ�����
    int dx=1,dy=1;
    stack[ top].x = stack[ ++top].y = 1;
    while( maze[6][6] != 2)//���յ�û�б������Ǿ�һֱ����
    {
        printf("(%d,%d)\n",stack[top].x,stack[top].y);
            if(maze[dx][dy+1] ==1) //�����ҷ���
            {
                ++dy;
                maze[ dx][ dy] = 2;//����֮��ͽ��˵㸳ֵΪ2
                stack[ ++top].x = dx;//��ջ
                stack[ top].y = dy;
                stack[top].from='W';
                continue;
            }
            //����ҷ���ͨ������·���
            if(maze[dx+1][dy] ==1)
            {
                ++dx;
                maze[ dx][ dy] = 2;//����֮��ͽ��˵㸳ֵΪ2
                stack[ ++top].x = dx;
                stack[ top].y = dy;
                stack[ top].from='N';
                continue;
            }
            //����·���ͨ���������
            if(maze[dx][dy-1] ==1)
            {
                --dy;
                maze[ dx][ dy] = 2;//����֮��ͽ��˵㸳ֵΪ2
                stack[ ++top].x = dx;
                stack[ top].y = dy;
                stack[ top].from='E';
                continue;
            }
            //�������ͨ������Ϸ���
            if(maze[dx-1][dy] ==1)
            {
                --dx;
                maze[ dx][ dy] = 2;//����֮��ͽ��˵㸳ֵΪ2
                stack[ ++top].x = dx;
                stack[ top].y = dy;
                stack[ top].from='S';
                continue;
            }
        //���ĸ����򶶲�����ͨ�����ص���һ����Ҳ���ǳ�ջ
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
