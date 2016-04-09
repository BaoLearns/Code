//这是一个用数组模拟循坏链表
//作者 Roye
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int rear=0,front=0;//初始化数组下表的值
int num=0;//记录元素的个数
void En_queue(int *p)//入队一个元素
{
    printf("输入入队的值：");
    scanf("%d",p+rear);
    rear=(rear+1)%6;//当r的值大于5时r的值就转向0，就实现了循环
    num++;//入队，元素的总个数加一
}
void De_queue(int *p)//出队
{
    printf("出对的元素是：%d\n",p[front]);
    front=(front+1)%6;
    num--;//出队了元素，元素的个数就减一
}
int main()
{
    int s[6];
    int chi;
    while(scanf("%d",&chi))
    {
        if(chi==1)//选择出队还是入队，1表示入队，其他表示出队
        {
            if (num!=6)//判断是否为满
                En_queue(s);
            else
                printf("队列已经满了，不能插入！\n");
        }
        else
        {
            if(num!=0)
                De_queue(s);
            else
                printf("队列为空不能删除\n");

        }
    }
    return 0;
}
