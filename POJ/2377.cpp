/*************************************************************************
    > File Name: 2377.cpp
    > Author: Royecode
    > Email: Royecode@163.com 
    > Created Time: 2015年07月14日 星期二 19时27分37秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAXN 1007
using namespace std;
struct s
{
	int from, to, cost;
	s(int _f, int _t, int _c):from(_f), to(_t), cost(_c)
	{}
	bool operator < (const s &a) const
	{
		return cost > a.cost;
	}
};
vector <s> side;
int fa[MAXN];
int find(int x)
{
	return fa[x] = fa[x] == x? x: find(fa[x]);
}
void kruskal(int n, int m)
{
	sort(side.begin(), side.end());
	for(int i = 1; i <=n; ++i)
		fa[i] = i;
	long long ans = 0;
	int cnt = 0;
	for(int i = 0; i < m; ++i)
	{
		int fx = find(side[i].from), fy = find(side[i].to);
		if(fx != fy)
		{
			cnt++;
			fa[fx] = fy;
			ans += side[i].cost;
		}
	}
	printf("%I64d\n", cnt == n - 1? ans: -1);
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		side.push_back(s(a, b, c));
	}
	kruskal(n, m);
	return 0;
}
