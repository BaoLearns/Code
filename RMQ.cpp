/*************************************************************************
    > File Name: RMQ.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年09月24日 星期四 19时41分31秒
 ************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int d[15][10001];
int n, arr[10001];
void make_RMQ(int n)
{
	int k = log(n) / log(2) + 1;
	for(int i = 1; i <= n; ++i) d[1][i] = arr[i];
	for(int i = 2; i <= k; ++i)
	{
		for(int j = 1; j + (1 << i) - 1 <= n; ++j)
			d[i][j] = min(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);		
	}
	for(int i = 1; i <= k; ++i)
	{
		for(int j = 1; j <= n; ++j)
			cout << d[i][j] << " ";
		cout << endl;
	}
}
int main(int argv, char **argc)
{
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> arr[i];
	make_RMQ(n);
    return 0;
}
