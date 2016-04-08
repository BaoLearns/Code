/*************************************************************************
    > File Name: findKthnumbers.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年11月19日 星期四 17时22分11秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution{
public:
	int findKthnumbers(vector <int> vec, int k){
		int len = vec.size();
		if(len < 44){
			sort(vec.begin(), vec.end());
			return vec[k];
		}
		for(int i = 0; i < len / 5; ++i){
			sort(vec.begin() + i * 5, vec.begin() + i * 5 + 5);
			swap(vec[i], vec[i * 5 + 3]);
		}
		int x = findKthnumbers(vector <int> (vec.begin(), vec.begin() + len / 5), k);
		vector <int> vec1, vec2, vec3;
		for(int i = 0; i < len; ++i){
			if(vec[i] < vec[x]) vec1.push_back(vec[i]);
			else if(vec[i] == vec[x]) vec2.push_back(vec[i]);
			else vec3.push_back(vec[i]);
		}
		if(vec1.size() >= k) return findKthnumbers(vec1, k);
		else if(vec1.size() + vec2.size() >= k) return x;
		else return findKthnumbers(vec3, k - vec1.size() - vec2.size());
	}
	void set(){
		vecint.clear();
		int n, k;
		cin >> n >> k;
		while(n--){
			int e;
			cin >> e;
			vecint.push_back(e);
		}
		cout << findKthnumbers(vecint, k) << endl;;
	}
private:
	vector <int> vecint;
};
int main(int argc, char **argv){
	Solution P;
	while(true){
		P.set();
	}
    return 0;
}
