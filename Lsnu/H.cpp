/*************************************************************************
    > File Name: H.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月11日 星期日 14时35分27秒
 ************************************************************************/

#include <iostream>

using namespace std;

int arr[104][104];
int main(int argc, char **argv)
{
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i)
	{
		string st;
		int x, y, L;
		cin >> st >> x >> y >> L;
		if(st == "WHITE")
		{
			for(int i = x; i <= x + L - 1; ++i)
			{
				for(int j = y; j <= y + L - 1; ++j)
					arr[i][j] = 0;
			}
		}
		else if(st == "BLACK")
		{
			
			for(int i = x; i <= x + L - 1; ++i)
			{
				for(int j = y; j <= y + L - 1; ++j)
					arr[i][j] = 1;
			}
		}
		else
		{
			int cnt = 0;
			for(int i = x; i <= x + L - 1; ++i)
			{
				for(int j = y; j <= y + L - 1; ++j)
					if(arr[i][j] == 1) cnt++;
			}
			cout << cnt << endl;
		}
	}
    return 0;
}
