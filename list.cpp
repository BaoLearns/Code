/*************************************************************************
    > File Name: list.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月25日 星期日 13时30分42秒
 ************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct node
{
	int val;
	struct node *next;
};
void show(node *head)
{
	for(node *p = head -> next; p != head; p = p -> next)
		cout << p -> val << " ";
	cout << endl;
}
int main(int argc, char **argv)
{
	node *head, *p;
	head = p = new node;
	srand(time(NULL));
	int n = 10;
	for(int i = 0; i < n; ++i)
	{
		node *q = new node;
		q -> val = rand() % 100;
		q -> next = NULL;
		//if(p == NULL)
		//	p =	q;
		//else
		//{
			p -> next =	q;
			p = p -> next;
		//}
		//cout << q -> val << " ";
	}
	//cout << endl;
	p -> next = head;
	show(head);
	for(p = head -> next; head -> next != NULL; p = p -> next)
	{
		if(p == head) 
		{
			if(p -> next == head) head -> next = NULL;
			continue;
		}
		p -> val -= 10;
		//cout << p -> val << endl;
		show(head);
		if(p -> val < 0)
		{
			node *q;
			for(q = p -> next; q -> next != p; q = q -> next)
			{
				;//cout << "+++";//if(q = head) 
			}
			//cout << "!!" << endl;
			node *temp = p;
			q -> next = p -> next;
			p = q -> next;
			delete temp;
			
		}
	}
	return 0;
}
