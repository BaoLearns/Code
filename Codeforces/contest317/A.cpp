/*************************************************************************
    > File Name: A.cpp
    > Author: Royecode
    > Email: Royecode@163.com 
    > Created Time: 2015年09月08日 星期二 15时02分22秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n1, n2;
	cin >> n1 >> n2;
	int k, m;
	cin >> k >> m;
	int val1, val2;
	for(int i = 1; i <= n1; ++i)
	{
		int e;
		cin >> e;
		if(i == k) val1 = e;
	}
	for(int i = 1; i <= n2; ++i)
	{
		int e;
		cin >> e;
		if(i == n2 - m + 1) val2 = e;
	}
	puts(val1 < val2? "YES": "NO");
	return 0;
}

