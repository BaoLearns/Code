/*************************************************************************
    > File Name: shuffle.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年11月10日 星期二 20时58分50秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;
int num1 = 0, num2 = 0;
int cnt[123][11];
string cards = "ABCDEFGHIJ";
const int size = 10;
void foo1()
{
	string st = cards;
	for(int i = size - 1; i >= 0; --i)
	{
		int j = rand() % (i + 1);
		swap(st[i], st[j]);
	}
//	cout << st << endl;
	for(int i = 0; i < 10; ++i)
	{
		num1++;
		cnt[st[i]][i]++;
	}
}
void shuffle(string st1, string &st2, int len, int cnt)
{
	if(cnt > size || len <= 0) return;
	int pos = rand() % len;
	st2[cnt++] = st1[pos];
	if(len == 1) return;
	shuffle(st1.substr(0, pos), st2, pos, cnt);
	shuffle(st1.substr(pos + 1), st2, len - pos - 1, cnt);

}
void foo2()
{
	string st1, st2;
	for(int i = 0; i < 5; ++i)
	{
		st1 = cards;
		st2 = string(10, ' ');
		//st2 = string("");
		shuffle(st1, st2, 10, 0);
	}
	for(int i = 0; i < 10; ++i)
		cnt[st2[i]][i]++;
	cout << st2 << endl;
}
void show()
{
	cout << " ";
	for(int i = 1; i <= 10; ++i)
		cout << "    " << i;
	cout << endl;
	for(char ch = 'A'; ch < 'A' + 10; ++ch)
	{
		cout << ch << "|";
		for(int i = 0; i < 10; ++i)
		{
			num2 += cnt[ch][i];
			printf("%4d ", cnt[ch][i]);
		}
		cout << endl;
	}	
	cout << num1 << " " << num2 << endl;
}

int main(int argc, char **argv)
{
	for(int i = 0; i < 123; ++i)
		for(int j = 0; j < 11; ++j) cnt[i][j] = 0;
	srand(time(NULL));
	for(int i = 0; i < 100000; ++i)
		foo2();
	show();
    return 0;
}
