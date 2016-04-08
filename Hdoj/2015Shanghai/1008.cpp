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
ll num[MAXN];
int main(int argv, char **argc)
{
    //freopen("input", "r", stdin);
    int t;
    scanf("%d", &t);
    for(int I = 1; I <= t; ++I)
    {
        printf("Case #%d:", I);
        ll q, M;
		ull	x = 1;
        scanf("%lld%lld", &q, &M);
        for(int i = 1; i <= q; ++i)
        {
            ll op;
            scanf("%lld%lld", &op, &num[i]);
            if(op == 1) x = x * num[i] % M;
            else x = (x / num[num[i]]) % M;
            printf("%lld\n", x);
        }

    }
    return 0;
}
