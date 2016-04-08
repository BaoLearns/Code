/*************************************************************************
    > File Name: a.cpp
    > Author: Royecode
    > Email: Royecode@163.com 
    > Created Time: 2015年08月05日 星期三 23时47分43秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 100007;
const int INF = 1e9;
int arr[MAXN];
int main()
{
	int n, k;
	while(cin >> n >> k)
	{
		map <ll, int> Map;
		for(int i = 0; i < n; ++i)
		{
			ll e;
			cin >> e;
			Map[e]++;
		}
		ll ans = 0;
		for(map <ll, int>::iterator it = Map.begin(); it != Map.end(); ++it)
		{
			int e = it->first;
			ans += Map[e] * Map[k * e] * Map[k * k * e];
		}
		cout << ans << endl;
	}
	return 0;
}

