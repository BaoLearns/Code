/*************************************************************************
    > File Name: test03.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年11月02日 星期一 14时08分51秒
 ************************************************************************/

#include <iostream>

using namespace std;

void show(unsigned int a)
{
	for(int i = 31; i >= 0; --i)
	{
		cout << (a >> i & 1);
		if(i % 4 == 0) cout << " ";
	}
	cout << endl;
}
int main(int argc, char **argv)
{
	unsigned int a = 1 << 32 - 1;
	show(a);
	cout << a << endl;
	cout << ++a << endl;
	show(a);
	int b = (1 << 31) - 1;
	show(b);
	cout << b << endl;
	b++;
	show(b);
	cout << b << endl;
    return 0;
}
