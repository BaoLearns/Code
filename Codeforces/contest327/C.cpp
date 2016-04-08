/*************************************************************************
    > File Name: C.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月25日 星期日 21时54分51秒
 ************************************************************************/

#include <iostream>

using namespace std;

struct node
{
	node *num[2];
	int val;
};
int n, a[500007], b[500007];
bool insert(node *root, int *arr, int d)
{
	if(d == n) 
	{
		if(root -> val) return true;
		root -> val = 1;
		return false;
	}
	if(root -> num[arr[d]] == NULL)
	{
		root -> num[arr[d]] = new node;
		root -> num[arr[d]] -> val = 0;
	}
	return insert(root -> num[arr[d]], arr, d + 1);
}
int mid(int a, int b, int c)
{
	if(a >= b && a <= c || a >= c && a <= b) return a;
	if(b >= a && b <= c || b >= c && b <= a) return b;
	if(c >= b && c <= a || c >= a && c <= b) return c;
	return c;
}
int main(int argc, char **argv)
{
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	node *root = new node;
	insert(root, a, 0);
	int cnt = 0;
	while(true)
	{
		b[0] = a[0];
		b[n - 1] = a[n - 1];
		for(int i = 1; i < n - 1; ++i)
			b[i] = mid(a[i - 1], a[i], a[i + 1]);
		bool f = true;
		for(int i = 0; i < n; ++i)
			if(a[i] != b[i]) f = false;
		if(f) break;
		/*if(insert(root, b, 0))
		{
			cout << -1 << endl;
			return 0;
		}*/
		insert(root, b, 0);
		for(int i = 0; i < n; ++i)
			a[i] = b[i];
		cnt++;
	}
	cout << cnt << endl;
	for(int i = 0; i < n; ++i)
		cout << a[i] << ' ';
	cout << endl;
    return 0;
}
