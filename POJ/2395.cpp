/*************************************************************************
    > File Name: 2395.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年07月14日 星期二 20时14分57秒
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 1e9 + 8
#define MAXN 2007
using namespace std;
int d[MAXN][MAXN];
int Prim(int v)
{
    int mincost[MAXN];
    fill(mincost, mincost + MAXN, INF);
    mincost[1] = 0;
    bool used[MAXN];
    memset(used, false, sizeof used);
    int ans = 0;
    while(true)
    {
        int u = -1;
        for(int i = 1; i <= v; ++i)
            if(!used[i] && (u == -1 || mincost[u] > mincost[i])) u = i;
        if(u == -1) break;
        used[u] = true;
        ans = max(ans, mincost[u]);
        for(int i = 1; i <= v; ++i)
            mincost[i] = min(mincost[i], d[i][u]);
    }
    return ans;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j<= n; ++j)
			d[i][j] = INF;
    for(int i = 0; i < m; ++i)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		d[a][b] = c;
		d[b][a] = c;
	}
    printf("%d\n", Prim(n));
    return 0;
}
