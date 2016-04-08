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
int main()
{
	int t, s, q;
	while(cin >> t >> s >> q)
	{
		cout << max(1, q / (q - 1)) << endl;
	}
	return 0;
}

