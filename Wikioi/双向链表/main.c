#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct node//�������ṹ��
{
    int date;//�洢����
    struct node *prev;//ָ��ָ����һ��Ԫ��
    struct node *next;//ָ��ָ����һ��Ԫ��
}node, *pnode;//������δnode��pnode��pnode �൱��node *
int main()
{
    pnode head;//ͷ��㣬��Զָ������ĵ�һ��Ԫ��
    pnode p=(pnode)malloc(sizeof(node));//p�ڵ㣬���������ĵ�һ��Ԫ��
    pnode fina=(pnode)malloc(sizeof(node));//����һ���ڵ㣬��Զָ�����һ��Ԫ��
    head=p;
    p->prev=NULL;
    int n;
    printf("�������봴���Ľڵ����:");
    scanf("%d",&n);
    while(n--)
    {
        pnode q=(pnode)malloc(sizeof(node));//�����½ڵ�
        fina=q;
        q->date=n;
        p->next=q;
        q->prev=p;
        //q->next=p;
        q->next=NULL;
        p=q;

    }
    pnode r=head->next;
    printf("˳�������\n");
    while(r!=NULL)//˳���������headָ��
    {
        printf("%d ",r->date);
        r=r->next;
    }
    putchar('\n');
    r=fina;//ָ��r����ֵfina��Ҳ�������һ���ڵ�
    printf("���������\n");
    while(r->prev!=NULL)//�������ʱ����finaָ��
    {
        printf("%d ",r->date);
        r=r->prev;
    }
    putchar('\n');

    return 0;
}
