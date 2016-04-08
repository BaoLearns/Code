/*************************************************************************
    > File Name: B.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月25日 星期日 21时06分28秒
 ************************************************************************/

#include <iostream>
#define P pair <char, char>

using namespace std;

int main(int argc, char **argv)
{
	int n, m;
	cin >> n >> m;
	string st;
	cin >> st;
	char Map[26];
	for(int i = 0; i < 26; ++i)
		Map[i] = 'a' + i;
	P arr[m];
	for(int i = 0; i < m; ++i)
		cin >> arr[i].first >> arr[i].second;
    for(char ch = 'a'; ch <= 'z'; ++ch)
	{
		for(int i = 0; i < m; ++i)
		{
			if(Map[ch - 'a'] == arr[i].first) Map[ch - 'a'] = arr[i].second;
			else if(Map[ch - 'a'] == arr[i].second) Map[ch - 'a'] = arr[i].first;
		}
	}
	//for(int i = 0; i < 26; ++i)
	//	cout << char(i + 'a') << " " << Map[i] << endl;
	for(int i = 0; i < n; ++i)
		cout << Map[st[i] - 'a'];
	cout << endl;
	return 0;
}
