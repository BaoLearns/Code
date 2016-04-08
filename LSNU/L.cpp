/*************************************************************************
    > File Name: L.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月11日 星期日 14时43分20秒
 ************************************************************************/

#include <iostream>
#define P pair<int, int>
using namespace std;

int main(int argc, char **argv)
{
	int n;
	while(cin >> n, n != -1)
	{
		P arr[n + 1];
		int sum = 0;
		for(int i = 1; i <= n; ++i)
			cin >> arr[i].first >> arr[i].second;
		for(int i = 1; i <= n; ++i)
			sum += (arr[i].second - arr[i - 1].second) * arr[i].first;
		cout << sum << " miles" << endl;
	}
    return 0;
}
