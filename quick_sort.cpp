/*************************************************************************
    > File Name: quick_sort.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年07月20日 星期一 10时08分44秒
************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void quick_sort(int l, int r, int *arr)
{
	if(l < r)
	{
		int begin = l, end = r, val = arr[l];
		while(begin < end)
		{
			while(begin < end && arr[end] > val) end--;
			if(begin < end)
			{
				arr[begin] = arr[end];
				begin++;
			}
			while(begin < end && arr[begin] < val) begin++;
			if(l < r)
			{
				arr[end] = arr[begin];
				end--;
			}
		}
		arr[begin] = val;
		quick_sort(l, begin - 1, arr);
		quick_sort(begin + 1, r, arr);

	}
}
int main()
{
	srand(time(NULL));
	const int size = 10;
	int arr[size];
	for(int i = 0; i < size; ++i)
		arr[i] = rand() % size;
	for(int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
	quick_sort(0, size - 1, arr);
	for(int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
