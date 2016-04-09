#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>

#define debug(x) cout << #x << " " << x << endl;
#define P pari <int, int>
#define ll long long

const int MAXN = 1e5+7;
const int INF = 1e9+7;

using namespace std;

class node
{
public:
    int f, t, c;
    node(int _f, int _t, int _c)
    {
        f = _f;
        t = _t;
        c = _c;
    }
    node(){}
    bool operator < (const node &a) const
    {
        return c < a.c;
    }
};

struct query
{
    int id, val;
    ll ans;
};

bool cmp1(query a, query b)
{
    return a.val < b.val;
}
bool cmp2(query a, query b)
{
    return a.id < b.id;
}
node arr[MAXN];
query que[5007];

int fa[20007];
void init()
{
    for(int i = 1; i < 20007; ++i) fa[i] = i;
}
int find(int x)
{
    return fa[x] = fa[x] == x? x: find(fa[x]);
}
ll C(int n, int m)
{
    ll val = 1;
    for(int i = 1; i <= m; ++i, n--) val *= n;
    for(int i = 1; i <= m; ++i) val /= i;
    return val; 
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, q;
        scanf("%d%d%d", &n, &m, &q);
        for(int i = 0; i < m; ++i) 
            scanf("%d%d%d", &arr[i].f, &arr[i].t, &arr[i].c);
        sort(arr, arr + m);
        for(int i = 0; i < q; ++i) 
        {
            que[i].id = i;
            scanf("%d", &que[i].val);
        }
        sort(que, que + q, cmp1);
        int p = 0;
        init();
        int cnt[n + 1];
        memset(cnt, 0, sizeof cnt);
        ll t = 0;
        for(int i = 0; i < q; ++i)
        {
            while(p < m && arr[p].c <= que[i].val)
            {
                int fx = find(arr[p].f), fy = find(arr[p].t);
                fa[fx] = fy;
                cnt[fy]++;
                p++;
            }
            que[i].ans = t;
        }
        //debug(C(4, 2));
        sort(que, que + q, cmp2);
        for(int i = 0; i < q; ++i) printf("%I64d\n", que[i].ans * 2);
    }
    return 0;
}
