/*************************************************************************
    > File Name: me.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年11月17日 星期二 22时05分18秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution{
	public:
	int solve(vector <int> &nums1, vector <int> &nums2){
		int n = nums1.size(), m = nums2.size();
		int L = 0, R = n;
		while(L < R){
			int M = L + (R - L) / 2;
			cout << M << endl;
			int cnt1 = lower_bound(nums1.begin(), nums1.end(), nums1[M]) - nums1.begin();
			int cnt2 = nums1.end() - upper_bound(nums1.begin(), nums1.end(), nums1[M]);

			int cnt3 = lower_bound(nums2.begin(), nums2.end(), nums1[M]) - nums2.begin();
			int cnt4 = nums2.end() - upper_bound(nums2.begin(), nums2.end(), nums1[M]);
			if(cnt1 + cnt3 + n - (cnt1 + cnt2) + m - (cnt3 + cnt4) >= cnt2 + cnt4 && cnt2 + cnt4 + n - (cnt1 + cnt2) + m - (cnt3 + cnt4) >= cnt1 + cnt3) return nums1[M];
			else if(cnt1 + cnt3 + n - (cnt1 + cnt2) + m - (cnt3 + cnt4) >= cnt2 + cnt4) R = M - 1;
			else L = M + 1;
		}
		cout << "!!!" << endl;
		L = 0, R = m;
		while(L < R){
			int M = L + (R - L) / 2;
			cout << M << endl;
			int cnt1 = lower_bound(nums1.begin(), nums1.end(), nums2[M]) - nums1.begin();
			int cnt2 = nums1.end() - upper_bound(nums1.begin(), nums1.end(), nums2[M]);

			int cnt3 = lower_bound(nums2.begin(), nums2.end(), nums2[M]) - nums2.begin();
			int cnt4 = nums2.end() - upper_bound(nums2.begin(), nums2.end(), nums2[M]);
			if(cnt1 + cnt3 + n - (cnt1 + cnt2) + m - (cnt3 + cnt4) >= cnt2 + cnt4 && cnt2 + cnt4 + n - (cnt1 + cnt2) + m - (cnt3 + cnt4) >= cnt1 + cnt3) return nums2[M];
			else if(cnt1 + cnt3 + n - (cnt1 + cnt2) + m - (cnt3 + cnt4) >= cnt2 + cnt4) R = M - 1;
			else L = M + 1;
		}
	}
};

int main(int argc, char **argv){
	vector <int> nums1, nums2;
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
	{
		int e;
		cin >> e;
		nums1.push_back(e);
	}
	for(int i = 0; i < m; ++i)
	{
		int e;
		cin >> e;
		nums2.push_back(e);
	}
	Solution P;
	cout << P.solve(nums1, nums2) << endl;
    return 0;
}
