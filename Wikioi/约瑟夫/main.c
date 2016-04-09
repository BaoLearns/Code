#include <stdio.h>
#include <malloc.h>
typedef struct node
{
	int date;//存放数据
	struct node *next;//指向下一个单元的指针
}node,* pnode;//重命名
int main()
{
	int n;
	while(scanf("%d",&n))
    {
	pnode head;
	pnode p=(pnode)malloc(sizeof(node));//构造P节点
	head=p;//头指针，指向P

	int m=0;
	while(m++<n)//输入数据
	{
		pnode q=(pnode)malloc(sizeof(node));
		q->date=m;
		p->next=q;
		q->next=head->next;
		p=q;
	}
	int cnt=1;
	pnode h=head;
	while(n>0)
	{
		cnt++;
		h=h->next;
		if(cnt==3)//在出现底三个节点之前，将第三个节点释放
		{
			if(n==1) printf("%d\n",h->next->date);//如果只剩最后一个节点就大英输出最后一个节点的值
			pnode r=(pnode)malloc(sizeof(node));
			r=h->next;
			h->next=h->next->next;
			free(r);
			cnt=1;
			n--;
		}
	}
    }
	return 0;

}
