#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
int max=0;
typedef struct node
{
    char date[60];
    struct node *next;
}node,* pnode;
typedef struct stack
{
    pnode top;
    pnode bottom;
}stack,* pstack;
void Init_stack(pstack s)
{
    pnode p;
    p=(pnode)malloc(sizeof(node));
    s->top=s->bottom=p;
    s->top->next=NULL;
    return ;
}
void Push_stack(pstack p,char val[])
{
    pnode q=(pnode )malloc(sizeof(node));
    strcpy(q->date,val);
    q->next=p->top;
    p->top=q;
    return ;
}
/*void Pop_stack(pstack p)
{
    pnode r=p->top;
    p->top=p->top->next;
    free(r);
    return ;
}
int Get_stack(pstack p)
{
    return p->top->date;
}
int IsEmpty_stack(pstack p)
{
    if (p->top==p->bottom)
        return 1;
    return 0;
}*/
void Find_stack(pstack p)
{
    pnode q=p->top;
    pnode r,d;
    for(;q->next!=NULL;q=q->next)
    {
        int num=0;
        d=q;
        for(r=q->next;r->next!=NULL;r=r->next)
        {

            if(strstr(d->date,r->date)==d->date)
            {
                num++;
                d=r;
            }
        }
        if(num>max) max=num;
    }

    return ;
}
void Traverse_stack(pstack s)
{
    pnode p=s->top;
    while(p!=s->bottom)
    {
        printf("%s ",p->date);
        p=p->next;
    }
    putchar('\n');
    return ;
}
int main()
{
    stack S;
    Init_stack(&S);
    int n;
    scanf("%d",&n);
    while(n--)
    {
        char s[60];
        scanf("%s",s);
        Push_stack(&S,s);
    }
    Traverse_stack(&S);
    Find_stack(&S);
    printf("%d\n",max);
    return 0;
}
