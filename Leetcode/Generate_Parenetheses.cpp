/*************************************************************************
    > File Name: Generate_Parenetheses.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年11月19日 星期四 14时59分44秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
	void set(int n){
		vec = generateParenthesis(n);
	}
	void dfs(vector <string> &vec, int n, int cnt1, int cnt2, string &st){
		if(cnt1 == n && cnt2 == n){
			vec.push_back(st);
			return ;
		}
		if(cnt1 < n){
			if(cnt1 == cnt2){
				st[cnt1 + cnt2] = '(';
				dfs(vec, n, cnt1 + 1, cnt2, st);
			}
			else if(cnt1 > cnt2){
				st[cnt1 + cnt2] = '(';
				dfs(vec, n, cnt1 + 1, cnt2, st);
				st[cnt1 + cnt2] = ')';
				dfs(vec, n, cnt1, cnt2 + 1, st);
			}
		}
		else if(cnt1 == n){
			st[cnt1 + cnt2] = ')';
			dfs(vec, n, cnt1, cnt2 + 1, st);
		}
	}
	vector <string> generateParenthesis(int n){
		vector <string> vec;
		if(n == 0) return vec;
		string st(2 * n, ' ');
		dfs(vec, n, 0, 0, st);	
	}
	void show(){
		for(int i = 0; i < vec.size(); ++i)
			cout << vec[i] << endl;
	}
private:
	vector <string> vec;
};

int main(int argc, char **argv){
	Solution P;
	int n;
	while(cin >> n){
		P.set(n);
		P.show();
	}
    return 0;
}
