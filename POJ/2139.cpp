/*************************************************************************
    > File Name: 2139.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年07月17日 星期五 11时28分07秒
 ************************************************************************/
#include <cstdio>
#include <algorithm>
#define MAXN 307
#define INF 1e7
using std::min;
int arr[MAXN], d[MAXN][MAXN];
int main()
{
	for(int i = 1; i < MAXN; ++i)
	{
		for(int j = 1; j < MAXN; ++j)
			d[i][j] = INF;
		d[i][i] = 0;
	}
	int n, m;
	scanf("%d%d", &n, &m);
	while(m--)
	{
		int num;
		scanf("%d", &num);
		for(int j = 0; j < num; ++j)
			scanf("%d", &arr[j]);
		for(int j = 0; j < num; ++j)
			for(int k = j + 1; k < num; ++k)
				d[arr[j]][arr[k]] = d[arr[k]][arr[j]] = 1;
	}
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	int ans = INF;
	for(int i = 1; i <= n; ++i)
	{
		int sum = 0;
		for(int j = 1; j <= n; ++j)
			sum += d[i][j];
		ans = min(ans, sum);
	}
	printf("%d\n",int(1.0 * ans /( n - 1) * 100));
	return 0;
}
