#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <string>
#include <queue>
#include <stack>
#include <iterator>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <cassert>
#include <ctime>
#include <climits>
#include <limits>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mid l + (r - l) / 2
#define lson rx << 2, l, mid
#define rson rx << 2 | 1, mid + 1, r
#define pii pair <int, int>
#define PI 3.1415927
#define ll long long 
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define it iterator
#define eq equal_range
#define vi vector <int>
#define vll vector <ll>
#define mss map <string, string>
#define mmss multimap <string, string>
#define mii map <int , int>
#define mmii multimap <int , int>
#define msi map <string, int>
#define mis map <int, string>
#define fi(n,m,s) for(int i = n; i <= m; i += s)
#define fj(n,m,s) for(int j = n; j <= m; j += s)
#define rfi(n,m,s) for(int i = n; i >= m; i -= s)
#define rfj(n,m,s) for(int j = n; j >= m; j -= s)
#define fit(it) for (auto i : it) cout << *i << " ";
#define c(x) cout << "------->" <<  x << endl;
#define case(I) printf("Case #%d:\n", I);
#define debug(x) cout << #x << (x) << endl;
#define MAXN 100007
#define MOD 0xf3f3f3f3f3f3f
#define EPS 1e-10

using namespace std;

int arr[MAXN];

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
	double L, A, B, D;
	int Dir;
	while(cin >> L >> A >> B >> D >> Dir){
		double ans;
		ans = ((D / abs(A - B)) * B) / L;
		printf("%.6lf\n", ans);
	}
    return 0;
}
