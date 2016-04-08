/*************************************************************************
    > File Name: Divide_Two_Integers.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年11月24日 星期二 16时50分02秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
	int divide(int dividend, int divisor){
		int MAX_INT = (1 << 31) - 1;
		int MIN_INT = -MAX_INT - 1;
		//cout << MAX_INT << " " << MIN_INT << endl;
		int op = 1;
		if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) op = -1;
		unsigned n = dividend, m = divisor;
		n = abs(dividend);
		m = abs(divisor);
		unsigned cnt = 0, val = m;
		unsigned ans = 0;
		while(n >= m){
			if(val <= n){
				n -= val;
				val += val;
				if(cnt == 0) cnt++;
				else cnt += cnt;
				ans += cnt;
			}
			else{
				val = m;
				//ans += cnt;
				cnt = 0;
			}
		}
		//cout << ans << endl;
		//if(ans > MAX_INT) return MAX_INT;
		if(op == -1) 
			return -ans;
		if(ans > MAX_INT)return MAX_INT;
		return ans;
	}
};

int main(int argc, char **argv)
{
	Solution P;
	int n, m;
	while(cin >> n >> m) cout << P.divide(n, m) << endl;
    return 0;
}
