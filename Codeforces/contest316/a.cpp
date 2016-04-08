/*************************************************************************
    > File Name: a.cpp
    > Author: Royecode
    > Email: Royecode@163.com 
    > Created Time: 2015年08月14日 星期五 00时20分16秒
 ************************************************************************/

#include <bits/stdc++.h>
#define pb push_back
#define uint usigned int
#define ll long long
#define pii pair <int, int>
using namespace std;
const int MAXN = 1e2+7;
const int INF = 2e9+7;
int main()
{
	//freopen("test.in", "r", stdin);
	int n, m, arr[MAXN][MAXN];
	cin >> n >> m;
	map <int, int> Map;
	for(int i = 1; i <= m; ++i)
	{
		int MAX = -1, p;
		for(int j = 1; j <= n; ++j)
		{
			int e;
			cin >> e;
			if(MAX < e)
			{
				MAX = e;
				p = j;
			}
		}
		Map[p]++;
	}
	int ans = -1, pos = 1;
	for(map <int, int> :: iterator it = Map.begin(); it != Map.end(); ++it)
	{
		if(ans <= it -> second)
		{
			if(ans == it -> second) pos = min(pos, it -> first);
			else pos = it -> first;
			ans = it -> second;
		}
	}
	cout << pos << endl;
	return 0;
}

