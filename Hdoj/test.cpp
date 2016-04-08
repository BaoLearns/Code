/*************************************************************************
    > File Name: test.cpp
    > Author: Royecode
    > Email: Royecode@163.com 
    > Created Time: 2015年08月10日 星期一 23时17分34秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define pii pair <int, int>
#define x first
#define y second
#define pb push_back
using namespace std;
const int MAXN = 21;
pii point[MAXN];
int dis(int a, int b)
{
	return (point[a].x -point[b].x) * (point[a].x -point[b].x) + (point[a].y - point[b].y) * (point[a].y - point[b].y);
}
bool check(int i, int j, int k, int z)
{
	vector <int> vec;
	vec.pb(dis(i, j));
	vec.pb(dis(j, k));
	vec.pb(dis(k, z));
	vec.pb(dis(z, i));
	vec.pb(dis(i, k));
	vec.pb(dis(j, z));
	sort(vec.begin(), vec.end());
	if(vec[0] == vec[3] && vec[4] == vec[5]) return true;
	return false;
}
int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		for(int i = 0; i < n; ++i)
			scanf("%d%d", &point[i].x, & point[i].y);
		int ans = 0;
		for(int i = 0; i < n; ++i)
		{
			for(int j = i + 1; j < n; ++j)
			{
				for(int k = j + 1; k < n; ++k)
				{
					for(int z = k + 1; z < n; ++z)
				
						if(check(i, j, k, z)) ans++;
				}

			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

