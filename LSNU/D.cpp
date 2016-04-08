/*************************************************************************
    > File Name: D.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月11日 星期日 15时43分06秒
 ************************************************************************/

#include <iostream>
#define P pair <int, int>
using namespace std;

int main(int argc, char **argv)
{
	int n;
	while(cin >> n)
	{
		P arr[n];
		for(int i = 0; i < n; ++i)
			cin >> arr[i].first >> arr[i].second;
		int ans = 0;
		vector <P> vec;
		for(int i = 1; ; ++i)
		{
			for(int j = 0; j < n; ++j)
				arr[i].first += arr[i].second;
			for(int j = 1; j < n; ++j)
			{
				while(j < n && arr[j].first > arr[j - 1].first)
					vec.push_back(P(j, ))
			}
		}
	}	
    return 0;
}
