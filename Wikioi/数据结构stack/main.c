#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct node//创建节点
{
    struct node *next;
    int date;
}node,* pnode ;
typedef struct stack //创建顶节点，底节点
{
    pnode top;
    pnode bottom;
}stack,*pstack;
void Init_stack(pstack p)
{
    p->top=(pnode)malloc(sizeof(node));
    if(p->top==NULL)
    {
        printf("分配失败；\n");
        exit(-1);
    }
    else
    {
        p->bottom=p->top;
        p->top->next=NULL;//
    }
    return ;
}
void Push_stack(pstack p,int val)
{
    pnode newpnode;//新节点
    newpnode=(pnode)malloc(sizeof(node));
    newpnode->date=val;
    newpnode->next=p->top;
    p->top=newpnode;
}
void Traverse_stack(pstack s)
{
    pnode p=s->top;
    while(p!=s->bottom)
    {
        printf("%d ",p->date);
        p=p->next;
    }
    putchar('\n');
    return ;
}
int IsEmpty(pstack p)
{
    if (p->top==p->bottom)
        return 1;
    return 0;
}
int Pop_stack(pstack p)
{
    int e;
    if(IsEmpty(p))
    {
        printf("提取失败，该栈未空栈；\n");
        exit(-1);
    }
    else
    {
        e=p->top->date;
        pnode q=p->top;
        p->top=p->top->next;
        free(q);//释放节点
    }
    return e;
}
void Clear_stack(pstack p)
{
    while(p->top!=p->bottom)
    {
        pnode q=p->top;
        p->top=p->top->next;
        free(q);
        //p->top=p->top->next;
    }
}
int main()
{
    stack S;
    Init_stack(&S);//构造一个空栈
    Push_stack(&S,1);//压栈元素
    Push_stack(&S,2);
    Push_stack(&S,3);
    Push_stack(&S,4);
    Push_stack(&S,5);
    Push_stack(&S,6);

    Traverse_stack(&S);//遍历栈
    int e;
    e=Pop_stack(&S);//出战元素，返回值给e
    printf("%d\n",e);
    Traverse_stack(&S);
    Clear_stack(&S);//将栈元素清空，但栈还在
    //Traverse_stack(&S);
    Push_stack(&S,1);//压栈元素
    Push_stack(&S,2);
    Push_stack(&S,3);
    Push_stack(&S,4);
    Push_stack(&S,5);
    Push_stack(&S,6);
    Traverse_stack(&S);
    return 0;
}
