#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct node//�����ڵ�
{
    struct node *next;
    int date;
}node,* pnode ;
typedef struct stack //�������ڵ㣬�׽ڵ�
{
    pnode top;
    pnode bottom;
}stack,*pstack;
void Init_stack(pstack p)
{
    p->top=(pnode)malloc(sizeof(node));
    if(p->top==NULL)
    {
        printf("����ʧ�ܣ�\n");
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
    pnode newpnode;//�½ڵ�
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
        printf("��ȡʧ�ܣ���ջδ��ջ��\n");
        exit(-1);
    }
    else
    {
        e=p->top->date;
        pnode q=p->top;
        p->top=p->top->next;
        free(q);//�ͷŽڵ�
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
    Init_stack(&S);//����һ����ջ
    Push_stack(&S,1);//ѹջԪ��
    Push_stack(&S,2);
    Push_stack(&S,3);
    Push_stack(&S,4);
    Push_stack(&S,5);
    Push_stack(&S,6);

    Traverse_stack(&S);//����ջ
    int e;
    e=Pop_stack(&S);//��սԪ�أ�����ֵ��e
    printf("%d\n",e);
    Traverse_stack(&S);
    Clear_stack(&S);//��ջԪ����գ���ջ����
    //Traverse_stack(&S);
    Push_stack(&S,1);//ѹջԪ��
    Push_stack(&S,2);
    Push_stack(&S,3);
    Push_stack(&S,4);
    Push_stack(&S,5);
    Push_stack(&S,6);
    Traverse_stack(&S);
    return 0;
}
