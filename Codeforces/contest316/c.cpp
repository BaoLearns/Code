/*************************************************************************
    > File Name: a.cpp
    > Author: Royecode
    > Email: Royecode@163.com 
    > Created Time: 2015年08月14日 星期五 00时20分16秒
 ************************************************************************/

#include <bits/stdc++.h>
#define pb push_back
#define uint usigned int
#define ll long long
#define pii pair <int, int>
using namespace std;
const int MAXN = 1e5+7;
const int INF = 2e9+7;
int main()
{
	//freopen("test.in", "r", stdin);
	int n, m;
	cin >> n >> m;
	string st;
	cin >> st;
	//cout << st << endl;
	int cnt = 0;
	for(int i = 0; i < n; ++i)
	{
		int j = i;
		while(st[j] == '.')
			j++;
		if(st[i] == '.')
		{
			cnt += j - i - 1;
			i = j - 1;
		}
	}
	//cout << cnt << endl;
	while(m--)
	{
		int p;
		char ch[2];
		cin >> p >> ch;
		p--;
		if(ch[0] == '.' && st[p] >= 'a' && st[p] <= 'z')
		{
			if(p - 1 >= 0 && st[p - 1] == '.') cnt++;
			if(p + 1 < n && st[p + 1] == '.') cnt++;
		}
		else if(ch[0] >= 'a' && ch[0] <= 'z' && st[p] == '.')
		{
			if(p - 1 >= 0 && st[p - 1] == '.') cnt--;
			if(p + 1 < n && st[p + 1] == '.') cnt--;
		}
		cout << cnt << endl;
		st[p] = ch[0];
	}
	return 0;
}

