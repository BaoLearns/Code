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

int main(){
	int T;
	cin >> T;
	while(T--){
		int n, m;
		cin >> n >> m;
		int ans = 0;
		while(true){
			if(n == 1){
				ans += m;
				break;
			}
			if(m == 1){
				ans += n;
				break;
			}
			if(n > m){
				n -= m;
				ans++;
			}	
			else if(n < m){
				m -= n;
				ans++;
			}
			else{
				ans++;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
