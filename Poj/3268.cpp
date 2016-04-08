/*************************************************************************
    > File Name: 3268.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年07月17日 星期五 12时06分17秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 1001
#define INF 1e7
using namespace std;
int d[MAXN][MAXN], cost[MAXN][MAXN];
bool used[MAXN];
int dijkstra(int v, int num)
{
	fill(d[num],d[num] + MAXN, INF);
	memset(used, false, sizeof used);
	d[num][num] = 0;
	while(true)
	{
		int u = -1;
		for(int i = 1; i <= v; ++i)
			if(!used[i] && (u == -1 || d[num][u] > d[num][i])) u = i;
		if(u == -1) break;
		used[u] = true;
		for(int i = 1; i <= v; ++i)
			d[num][i] = min(d[num][i], d[num][i] + cost[i][u]);
	}
}
int main()
{
	int n, m, s;
	scanf("%d%d%d", &n, &m, &s);
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			cost[i][j] = INF;
		cost[i][i] = 0;
	}
	while(m--)
	{
		int a, b, t;
		scanf("%d%d%d", &a, &b, &t);
		cost[a][b] = t;
	}
	for(int i = 1; i <= n; ++i)
		dijkstra(n, i);
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			cout << d[i][j] << " ";
		cout << endl;
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		ans = max(ans, d[i][s] + d[s][i]);
	printf("%d\n", ans);
	return 0;
}
