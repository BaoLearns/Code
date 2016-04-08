/*************************************************************************
    > File Name: Letter_Combinations_of_a_Phone_Number.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年11月18日 星期三 23时29分52秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
	const char ch[10][5] = {" "," ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	void dfs(string &digits, int i, int len, vector <string> &vec, string &st){
		int n;
		if(digits[i] == '7' || digits[i] == '9') n = 4;
		else if(digits[i] == '1' || digits[i] == '0') n = 1;
		else n = 3;
		for(int j = 0; j < n; ++j){
			st[i] = ch[digits[i] - '0'][j];
			if(i + 1 == len) vec.push_back(st);
			else dfs(digits, i + 1, len, vec, st);
		}
	}
	vector <string> letterCombinations(string digits){
		int len = digits.length();
		vector <string> vec;
		if(len == 0) return vec;
		string st(len, '0');
		dfs(digits, 0, len, vec, st);
		return vec;
	}
};
int main(int argc, char **argv)
{
	Solution p;
	string n;
	while(cin >> n){
		vector <string> vec = p.letterCombinations(n);
	   	for(auto it:vec) cout << it << endl;
	}
    return 0;
}
