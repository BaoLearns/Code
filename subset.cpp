/*************************************************************************
    > File Name: subset.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月29日 星期四 16时51分49秒
 ************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv)
{
	srand(time(NULL));
	int n = 4;
	int arr[n];
	for(int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 10;
		cout << arr[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < (1 << n); ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(i >> j & 1) cout << arr[j] << " ";
		}
		cout << endl;
	}
    return 0;
}
