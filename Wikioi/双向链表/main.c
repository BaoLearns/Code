#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct node//重命名结构体
{
    int date;//存储数据
    struct node *prev;//指针指向上一个元素
    struct node *next;//指针指向下一个元素
}node, *pnode;//重命名未node，pnode，pnode 相当于node *
int main()
{
    pnode head;//头结点，永远指向链表的第一个元素
    pnode p=(pnode)malloc(sizeof(node));//p节点，是整个链的第一个元素
    pnode fina=(pnode)malloc(sizeof(node));//开辟一个节点，永远指向最后一个元素
    head=p;
    p->prev=NULL;
    int n;
    printf("输入你想创建的节点个数:");
    scanf("%d",&n);
    while(n--)
    {
        pnode q=(pnode)malloc(sizeof(node));//开辟新节点
        fina=q;
        q->date=n;
        p->next=q;
        q->prev=p;
        //q->next=p;
        q->next=NULL;
        p=q;

    }
    pnode r=head->next;
    printf("顺序遍历：\n");
    while(r!=NULL)//顺序输出利用head指针
    {
        printf("%d ",r->date);
        r=r->next;
    }
    putchar('\n');
    r=fina;//指针r被赋值fina，也就是最后一个节点
    printf("逆序输出：\n");
    while(r->prev!=NULL)//逆序输出时利用fina指针
    {
        printf("%d ",r->date);
        r=r->prev;
    }
    putchar('\n');

    return 0;
}
