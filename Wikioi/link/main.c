#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define len sizeof(struct node)
int ff(struct node *h,int n)
{
    while(n>1)
    {
        h=h->next;
        n--;
    }
    return h->num;
}
struct node
{
    int num;
    struct node *next;
};

int main()
{
    int n,i=0;
    scanf("%d",&n);
    struct node *p,*q,*head;
    p=q=(struct node*)malloc(len);
    head=NULL;
    while (n)
    {
        if(i==0) head=p;
        scanf("%d",&p->num);
        q->next=p;
        q=p;
        p=(struct node*)malloc(len);
        n--;
        i++;
    }
    q->next=NULL;
    p=head;
    while (p!=NULL)
    {
        printf("%d  ",p->num);
        p=p->next;
    }
    printf("\n");
    q->next=head;
    p=head;
    while(p!=NULL)
    {

        printf("%d  ",ff(p,n));
        p=p->next;
    }
    return 0;
}
