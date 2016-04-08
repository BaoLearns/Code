/*************************************************************************
    > File Name: test02.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年11月01日 星期日 21时04分41秒
 ************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void split(int *arr, int L, int R, int val)
{
	if(L >= R) return;
	int l = L, r = R;
	while(l < r)
	{
		while(l < r && arr[r] >= val) r--;
		while(l < r && arr[l] < val) l++;
		swap(arr[l], arr[r]);
	}
	split(arr, l, R, val);
}
void show(int *arr, int n)
{
	for(int i = 0; i < n; ++i)
		cout << arr[i] << (i < n - 1? " ": "\n");
}
int main(int argc, char **argv)
{
	srand(time(NULL));
	int n = 10;
	int arr[n];
	for(int i = 0; i < n; ++i)
		arr[i] = rand() % 20;
	show(arr, n);
	int val;
	cin >> val;
	split(arr, 0, n - 1, val);
	show(arr, n);
    return 0;
}
