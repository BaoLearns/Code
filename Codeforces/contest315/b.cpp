/*************************************************************************
    > File Name: a.cpp
    > Author: Royecode
    > Email: Royecode@163.com 
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 1e5+7;
const int INF = 2e9+7;
int hasht[MAXN];
int arr[MAXN];
int main()
{
	memset(hasht, 0, sizeof hasht);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		hasht[arr[i]]++;
	}
	vector <int> vec;
	for(int i = 1; i <= n; ++i)
		if(hasht[i] == 0) vec.push_back(i);
	int pos = 0;
	for(int i = 0; i < n; ++i)
	{
		if(hasht[arr[i]] > 1 || arr[i] > n)
		{
			cout << arr[i] << " " << " " << hasht[arr[i]] << " " << pos << endl;
			hasht[arr[i]]--;
			arr[i] = vec[pos++];
		}
	}
	for(int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}

