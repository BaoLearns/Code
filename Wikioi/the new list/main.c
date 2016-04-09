#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int len;
typedef struct node
{
    int date;
    struct node *next;
}node,*pnode;
pnode Init_list()//创建链表
{
    int i,val;
    printf("请输入创建链表节点的个数：");
    scanf("%d",&len);
    pnode head,pfinal;
    head=(pnode)malloc(sizeof(node));
    pfinal=head;
    pfinal->next=NULL;
    if(head==NULL)
    {
        printf("分配失败，系统错误\n");
        exit(-1);
    }
    else
    {
        for(i=0;i<len;i++)
        {
            pnode q;
            q=(pnode)malloc(sizeof(node));
            printf("请输入地%d个数:",i+1);
            scanf("%d",&val);
            q->date=val;
            pfinal->next=q;
            q->next=NULL;
            pfinal=q;

        }

    }

    return head;
}
void Show_list(pnode head)
{
    pnode p;
    p=head->next;
    while(p!=NULL)
    {
        printf("%d\n",p->date);
        p=p->next;
    }
    return ;
}
void Insert_list(pnode head)
{
    int i,pos,val;
    printf("请输入你插入数据的位置和数据：");
    scanf("%d%d",&pos,&val);
    if(pos<1||pos>len)
        printf("位置错误！");
    else
    {
        pnode p;
        p=head->next;
        for (i = 0; i < pos -1; i++)
            p = p -> next ;
        pnode newpoint;  //新节点
        newpoint=(pnode)malloc(sizeof(node));
        newpoint->date=val;
        newpoint->next=p->next;
        p->next=newpoint;
    }
    len++;
    return ;

}
void Delete_list(pnode head)
{
    int pos,i;
    printf("输入删除的位置：");
    scanf("%d",&pos);
    pnode p;
    p=head->next;
    for(i=0;i<pos-1;i++)
        p=p->next;
    pnode newpoint;
    newpoint=p->next;
    p->next=p->next->next;
    free(newpoint);
    return ;

}
void IsEmpty_list(pnode head)
{
    if(head->next==NULL)
    {
        printf("链表为空。\n");
        exit(-1);
    }
    else
        printf("链表不为空。\n");
}
void Length_list(pnode head)
{
    int len;
    pnode p=head;
    while(p->next!=NULL)
    {
        len++;
        p=p->next;
    }
    printf("链表节点的个数:%d\n",len);
}
void Sort_list(pnode head)
{
    pnode i,j;
    int t;
    //pnode p=head;
    for(i=head->next;i->next!=NULL;i=i->next)
    {
        for(j=head->next;j->next!=NULL;j=j->next)
        if(i->date<j->date) t=i->date,i->date=j->date,j->date=t;
    }
    return ;
}
int main()
{
    pnode head;
    head=Init_list();
    IsEmpty_list(head);
    Show_list(head);
    //Insert_list(head);
    //Show_list(head);
    //Delete_list(head);
    //Show_list(head);
    Length_list(head);
    Sort_list(head);
    printf("排序的结果是：\n");
    Show_list(head);
    return 0;
}
