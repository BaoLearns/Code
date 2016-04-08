#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <vector>

#define pb push_back
#define mk make_pari
#define P pair <int, int>
#define debug(x) cout << #x << " " << x << endl;
#define ll long long
#define ull unsigned long long

using namespace std;

const int MAXN = 1e5 + 7;
const int INF = 2e9 + 7;
const double EPS = 1e-9;

int main(int argv, char **argc)
{
	//freopen("input", "r", stdin);
	int t;
	cin >> t;
	for(int I = 1; I <= t; ++I)
	{
		int n, a, b, L;
		cin >> n >> a >> b >> L;
		int cnt = 0;
		for(int i = 0; i < n; ++i)
		{
			int L, R;
			cin >> L >> R;
			cnt += abs(R - L);
		}
		int ans = (n - cnt) * b - cnt * a;
		printf("Case #%d: %d\n", I, max(ans, 0));
	}
   	return 0;
}
