#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 10^5+7;
const unsigned int INF = 1 << 31;
const int MOD = 1000000007;

bool connect[10][10] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 1, 0, 1, 1, 1, 0, 1, 0,
	0, 1, 0, 1, 1, 1, 1, 1, 0, 1,
	0, 0, 1, 0, 1, 1, 1, 0, 1, 0,
	0, 1, 1, 1, 0, 1, 0, 1, 1, 1,
	0, 1, 1, 1, 1, 0, 1, 1, 1, 1,
	0, 1, 1, 1, 0, 1, 0, 1, 1, 1,
	0, 0, 1, 0, 1, 1, 1, 0, 1, 0,
	0, 1, 0, 1, 1, 1, 1, 1, 0, 1,
	0, 0, 1, 0, 1, 1, 1, 0, 1, 0
};

int t[10][10] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	13, 31, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	17, 71, 0, 0, 0, 0, 0, 0, 0, 0,
	19, 91, 28, 82, 37, 73, 46, 64, 0, 0,
	39, 93, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	79, 97, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

int main(){
	int T;
	cin >> T;
	while(T--){
		int k;
		cin >> k;
		int arr[10];
		int count[10];
		bool used[10];
		memset(count, 0, sizeof(count));
		memset(used, false, sizeof(used));
		for(int i = 0; i < k; ++i){
			cin >> arr[i];
			count[arr[i]]++;
		}
		bool ans = true;
		if(k < 4) ans = false;
		for(int i = 0; i < 10; ++i){
			if(count[i] > 1)
				ans = false;
		}
		for(int i = 1; i < k; ++i){
			bool f = false;
			if(connect[arr[i - 1]][arr[i]])
				f = true;
			for(int j = 1; j < 10; ++j){
				if(used[j]){
					for(int k = 0; k < 10; ++k){
						if(t[j][k] == arr[i - 1] * 10 + arr[i])
							f = true;
					}
				}
			}
			if(!f) ans = false;
			used[arr[i - 1]] = used[arr[i]] = true;
		}
		if(ans) cout << "valid" << endl;
		else cout << "invalid" << endl;
	}
	return 0;
}
