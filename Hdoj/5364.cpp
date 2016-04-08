/*************************************************************************
    > File Name: 5364.cpp
    > Author: Royecode
    > Email: Royecode@163.com 
    > Created Time: 2015年08月11日 星期二 00时19分37秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 1e5+7;
int cnt[MAXN];
int main()
{
	int n;
	while(cin >> n)
	{
		memset(cnt, 0, sizeof cnt);
		for(int i = 0; i < n; ++i)
		{
			int e;
			cin >> e;
			cnt[e]++;
		}
		int flag = -1;
		for(int i = 0; i < 100000; ++i)
			if(cnt[i] >= n / 2) 
			{
				flag = i;
				break;
			}
		cout << flag << endl;
	}	
	return 0;
}

