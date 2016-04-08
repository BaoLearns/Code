/*************************************************************************
    > File Name: 324d.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月07日 星期三 15时10分50秒
 ************************************************************************/

#include <iostream>
#define ll long long
using namespace std;

bool is_prime(int n)
{
	for(ll i = 2; i * i <= n; ++i)
		if(n % i == 0) return false;
	return n > 1? true: false;
}
int main(int argc, char **argv)
{
	int n;
	cin >> n;
	if(is_prime(n))
		cout << 1 << endl << n << endl;
	else if(is_prime(n - 2))
		cout << 2 << endl << 2 << " " << n - 2 << endl;
	else
	{
		int p;
		for(p = n - 3; ; --p)
			if(is_prime(p)) break;
		n -= p;
		for(int i = 2; ;++i)
		{
			if(is_prime(i) && is_prime(n - i))
			{
				cout << 3 << endl << p << " " << i << " " << n - i << endl;
				break;		
			}
		}
	}
    return 0;
}
