#include <stdio.h>
#include <malloc.h>
typedef struct node
{
	int date;//�������
	struct node *next;//ָ����һ����Ԫ��ָ��
}node,* pnode;//������
int main()
{
	int n;
	while(scanf("%d",&n))
    {
	pnode head;
	pnode p=(pnode)malloc(sizeof(node));//����P�ڵ�
	head=p;//ͷָ�룬ָ��P

	int m=0;
	while(m++<n)//��������
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
		if(cnt==3)//�ڳ��ֵ������ڵ�֮ǰ�����������ڵ��ͷ�
		{
			if(n==1) printf("%d\n",h->next->date);//���ֻʣ���һ���ڵ�ʹ�Ӣ������һ���ڵ��ֵ
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
