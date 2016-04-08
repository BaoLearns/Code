/*************************************************************************
    > File Name: Swap_Nodes_in_Pairs.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年11月19日 星期四 15时31分12秒
 ************************************************************************/

#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

class Solution{
public:
	ListNode *swapPairs(ListNode *head){
		if(head == NULL || head -> next == NULL) return head;
		ListNode *p = head, *q = head -> next;
		int cnt;
		while(p && q){
			p -> val += q -> val;
			q -> val = p -> val - q -> val;
			p -> val = p -> val - q -> val;
			cnt = 2;
			while(cnt && q && p){
				p = p -> next;
				q = q -> next;
				cnt--;
			}
		}
		/*
		for(ListNode *p = head, *q = head -> next;p != NULL && q != NULL; p = p -> next -> next, q = q -> next -> next){
			p -> val += q -> val;
			q -> val = p -> val - q -> val;
			p -> val = p -> val - q -> val;
			if(p -> next == NULL || q -> next == NULL) break;
		}*/
		return head;
	}
	void show(){
		head = swapPairs(head);
		for(ListNode *p = head; p != NULL; p = p -> next)
			cout << p -> val << " ";
		cout << endl;
	}
	void set(){
		this -> head = NULL;
		int n;
		cin >> n;
		ListNode *p, *q;
		for(int i = 0; i < n; ++i){
			int e;
			cin >> e;
			if(i == 0){
				p = new ListNode(e);
				head = p;
			}else{
				q = new ListNode(e);
				p -> next = q;
				p = p -> next;
			}
		}
		show();
	}
private:
	ListNode *head;
};
int main(int argc, char **argv)
{
	Solution P;
	while(true){
		P.set();
//		P.show();
	}
    return 0;
}
