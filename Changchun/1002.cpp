#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

#define debug(x) cout << #x << x << endl
#define P pari <int, int>
#define ll long long

const int MAXN = 1e4+7;
const int INF = 2e9+7;

using namespace std;

int p[MAXN];
vector <int> arr[MAXN * 10];
int cnt[MAXN];
int fa[MAXN];

void init()
{
    for(int i = 1; i < MAXN; ++i) fa[i] = i;
}

int find(int x)
{
    return fa[x] = fa[x] == x? x : find(fa[x]);
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        memset(cnt, 0, sizeof cnt);
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i) scanf("%d", &p[i + 1]);
        for(int i = 0; i < m; ++i)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            cnt[u]++;
            cnt[v]++;
            arr[u].push_back(v);
            arr[v].push_back(u);
        }
        for(int i = 1; i <= n; ++i)
        {
            if(cnt[i] == 1) 
            {
                cnt[i] == 0;
                cnt[arr[i][0]]--;
            }
        }
        for(int i = 1; i <= n; ++i)
        {
            if(cnt[i] > 1)
            {
                for(int j = 0; j < arr[j].size(); ++j)
                {
                    int fx = find(i), fy = find(arr[i][j]);
                    fa[fx] = fy;
                }
            }
        }
        int Hash[n + 1];
        memset(Hash, 0, sizeof Hash);
        for(int i = 1; i <= n; ++i)
        {
            if()
        }
        ll ans = 0;
        
        printf("%I64d\n", ans);
    }
    return 0;
}
