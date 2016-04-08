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

int ans[207];

void init(){
	ans[1] = 26;
	ans[2] = 26 * 26;
	ans[3] = 26 * 26 * 26;
	ans[4] = 456950;
	for(int i = 4; i <= 200; ++i){
		ans[i] = (1LL * ans[i - 3] * 25 % MOD + 1LL * ans[i - 2] * 25 + 1LL * ans[i - 1] * 25) % MOD;
	}
}

int main(){
	init();
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		cout << ans[n] << endl;
	}
	return 0;
}
