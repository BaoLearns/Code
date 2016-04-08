/*************************************************************************
    > File Name: 1671.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年07月17日 星期五 09时58分04秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#define MAXN 10007
using namespace std;
struct node
{
	int cnt;
	node *next[10];
	node()
	{
		cnt = 0;
		for(int i = 0; i < 10; ++i)
			next[i] = NULL;
	}
};
char word[MAXN][11];
void insert(node *root, char word[], int pos)
{
	char ch = word[pos];
	if(ch == '\0') 
	{
		root -> cnt = 1;
		return;
	}
	if(!root -> next[ch - '0'])
	{
		node *temp = new node;
		root -> next[ch - '0'] = temp;
	}
	//root -> next[ch - '0'] -> cnt++;
	insert(root -> next[ch - '0'], word, pos + 1);
	
}
bool query(node *root, char word[], int pos)
{
	char ch = word[pos];
	if(ch == '\0')
	{
		for(int i = 0; i < 10; ++i)
			if(root -> next[i]) return true;
		return false;
	}
	return query(root -> next[ch - '0'], word, pos + 1);
}
void _delete(node *root)
{
	if(!root) return;
	for(int i = 0; i < 10; ++i)
		 _delete(root -> next[i]);
	delete root;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		node *root = new node;
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
		{
			scanf("%s", word[i]);
			insert(root, word[i], 0);
		}
		bool flag = false;
		for(int i = 0; i < n; ++i)
		{
			if(query(root, word[i], 0))
			{
				flag = true;
				break;
			}
		}
		_delete(root);
		puts(!flag? "YES": "NO");
	}
	return 0;
}
