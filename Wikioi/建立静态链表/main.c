#include <stdio.h>
struct student
{
    int num;
    float score;
    struct student *next;
};

int main()
{
    struct student a,b,c,*head,*p;
    a.num=10101;a.score=89.5;
    b.num=10103;b.score=90.5;
    c.num=10107;c.score=85.0;
    head=&a;
    a.next=&b;
    b.next=&c;
    c.next=NULL;
    p=head;
    do
    {
        printf("%ld %5.1f\n",p->num,p->score);
        p=p->next;
    }
    while (p!=NULL);
    return 0;
}
