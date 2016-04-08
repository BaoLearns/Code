/*************************************************************************
    > File Name: 3Sum.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: Wed Nov 18 00:17:19 2015
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;
class Solution{
public:
	vector <vector<int> > threeSum(vector <int> &nums){
		vector <vector<int> > vec;
		sort(nums.begin(), nums.end());
		for(auto it:nums) cout << it << " ";
		cout << endl;
		for(vector <int>::iterator it1 = nums.begin(); it1 != nums.end(); ++it1){
			for(vector <int>::iterator it2 = it1 + 1; it2 != nums.end(); ++it2){
				int sum = *it1 + *it2;
				vector <int>::iterator it3 = lower_bound(it2 + 1, nums.end(), -sum);
				vector <int>::iterator it4 = upper_bound(it2 + 1, nums.end(), -sum);
				cout << it1 - nums.begin() << " " << it2 - nums.begin() << " " << it3 - nums.begin();
					if(it4 - it3 > 0 && *it3 == -sum){
						cout << "!!";
					vector <int> t = {*it1, *it2, *it3};
					if(vec.size() == 0) vec.push_back(t);
					else if(vec[vec.size() - 1] != t) vec.push_back(t);
				}
				cout << endl;
			}
		}/*
		vector <vector<int> > vec;
		for(set<vector<int> >::iterator it = Set.begin(); it != Set.end(); ++it)
			vec.push_back(*it);*/
		return vec;
	}

};
int main(int argc, char **argv){
	Solution P;
	vector <int> t;
   //	= {-1, 0, 1, 2, -1, 4, -2, -2};
	int e;
	while(~scanf("%d,", &e)) t.push_back(e);
	vector <vector<int> > vec = P.threeSum(t);
	cout << vec.size() << endl;
	for(int i = 0; i < vec.size(); ++i){
		for(int j = 0; j < vec[0].size(); ++j)
			cout << vec[i][j] << " ";
		cout << endl;
	}
    return 0;
}
