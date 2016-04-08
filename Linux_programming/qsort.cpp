/*************************************************************************
    > File Name: qsort.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: Mon Nov  2 22:17:17 2015
 ************************************************************************/
/*
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void qsort(int *arr, int L, int R)
{
	if(L >= R) return;
	int l = L, r = R;
	int val = arr[l];
	while(l < r)
	{
		while(l < r && arr[r] >= val) r--;
		arr[l] = arr[r];
		while(l < r && arr[l] < val) l++;
		arr[r] = arr[l];
	}
	arr[l] = val;
	int mid = l + (r - l) / 2;
	qsort(arr, L, mid - 1);
	qsort(arr, mid + 1, R);
}

int main(int argc, char **argv)
{
	srand(time(NULL));
	int n = 10;
	//cin >> n;
	int arr[n];
	for(int i = 0; i < n; ++i) arr[i] = rand() % 10;
	for(int i = 0; i < n; ++i)
		cout << arr[i] << (i < n - 1? " ": "\n");
	qsort(arr, 0, n - 1);
	for(int i = 0; i < n; ++i)
		cout << arr[i] << (i < n - 1? " ": "\n");
    return 0;
}

*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int cmp(const void *a, const void *b)
{
	char *c = (char *)a;
	char *d = (char *)b;
	for(int i = 0; i < 100; ++i)
	{
		if(c[i] > d[i]) return true;
		else if(c[i] < d[i]) return false;
	}
	//return *(char *)a - *(char *)b;
}
int main()
{
	int n;
	cin >> n;
	char ch[n][100];
	//string ch[n];
	for(int i = 0; i < n; ++i) cin >> ch[i];
	//sort(ch, ch + n);
	qsort(ch, n, sizeof ch[0], cmp);
	for(int i = 0; i < n; ++i) cout << ch[i] << endl;
	return 0;
}
