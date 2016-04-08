/*************************************************************************
    > File Name: I.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月22日 星期四 20时55分19秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main(int argc, char **argv)
{
	int n, k;
	cin >> n >> k;
	int cnt[k + 1];
	memset(cnt, 0, sizeof cnt);
	for(int i = 0; i < n; ++i)
	{
		int e;
		cin >> e;
		cnt[e]++;
	}
	int ans = 0;
	for(int i = 1; i <= k; ++i)
		ans += abs(n / k - cnt[i]);
	cout << ans / 2 << endl;
    return 0;
}
