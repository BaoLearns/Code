/*************************************************************************
    > File Name: E.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月11日 星期日 14时57分38秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cmath>
#define P pair <int, int>
using namespace std;

int main(int argc, char **argv)
{
	int n;
	cin >> n;
	P arr[n];
	int sum1 = 0, sum2 = 0;
	P d[n];
	for(int i = 0; i < n; ++i)
	{
		cin >> arr[i].first >> arr[i].second;
		sum1 += arr[i].first;
		sum2 += arr[i].second;
		d[i].first = abs(arr[i].first - arr[i].second);
		d[i].second = i;
	}
	int ans = 0, MIN = abs(sum1 - sum2);
	sort(d, d + n);
	for(int i = n - 1; i >= 0; --i)
	{
		int t1 = abs(sum1 - arr[d[i].second].first + arr[d[i].second].second), t2 = abs(sum2 - arr[d[i].second].second + arr[d[i].second].first);
		if(MIN > abs(t1 - t2))
		{
			ans++;
			sum1 = t1;
			sum2 = t2;
			MIN = abs(sum1 - sum2);
		}
	}
	cout << ans << endl;
    return 0;
}
