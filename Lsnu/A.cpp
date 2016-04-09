/*************************************************************************
    > File Name: A.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月11日 星期日 14时26分56秒
 ************************************************************************/

#include <iostream>
#define pair <int, int> P
using namespace std;
P arr[1007];
double distance(int i, int j)
{
	return (arr[i].first - arr[j].first) * (arr[i].first - arr[j].first) + (arr[i].second - arr[j].second) * (arr[i].second - arr[j].second);
}
int main(int argc, char **argv)
{
	int n;
	while(cin >> n, n != 0)
	{
		for(int i = 0; i < n; ++i)
			cin >> arr[i].first >> arr[i].second;
		sort(arr, arr + n);
		int cnt = 0;
		for(int i = 0; i < n; ++i)
		{
			for(int j = i + 1; j < n; ++j)
			{
				double dis = distance(i, j);
				P x1 = P(arr[i].first + arr[i].second - arr[j].second, arr[i].second - (arr[i].first - arr[j].first)), y1 = P(arr[j].first + arr[i].second - arr[j].second, arr[j].second - (arr[i].first - arr[j].first));
				if(lower_bound(arr, arr + n, x1) && lower_bound(arr, arr + n, y1))
			}
		}
	}
    return 0;
}
