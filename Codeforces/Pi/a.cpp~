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
const int INF = 1e9+7;
int arr[MAXN];
int main()
{
	//freopen("Judge.in", "r", stdin);
	int n;
	while(cin >> n)
	{
		for(int i = 0; i < n; ++i)
			cin >> arr[i];
		for(int i = 0; i < n; ++i)
		{
			int MIN = INF, MAX = -INF;
			if(i - 1 >= 0) MIN = min(MIN, arr[i] - arr[i - 1]), MAX = max(MAX, arr[i] - arr[0]);
			if(i + 1 < n) MIN = min(MIN, arr[i + 1] - arr[i]), MAX = max(MAX, arr[n - 1] - arr[i]);
			cout << MIN << " " << MAX << endl;
		}
	}
	return 0;

}

