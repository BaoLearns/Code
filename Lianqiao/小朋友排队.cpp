#include <bits/stdc++.h>
#define mid (l + r) / 2
#define lson rx * 2, l, mid
#define rson rx * 2 + 1, mid + 1, r
#define maxn 100005
#define LL long long
using namespace std;
LL tree[maxn * 4];
void Updata(int rx, int l, int r, int x)
{
    tree[rx]++;
    if(l == r)
        return;
    if(x > mid)
        Updata(rson, x);
    else
        Updata(lson, x);
}
LL Query(int rx, int l, int r, int L, int R)
{
    if(r < L || l > R)
        return 0;
    if(L <= l && r <= R)
        return tree[rx];
    return Query(lson, L, R) + Query(rson, L, R);    
}
int main()
{
    memset(tree, 0, sizeof(tree));
    int n;
    cin >> n;
    LL sum = 0;
    for(int i = 0; i < n; ++i)
    {
        int e;
        cin >> e;
        LL S = Query(1, 1, maxn, e + 1, maxn);
        sum += S * (S + 1) / 2;
        Updata(1, 1, maxn, e);
    }
    cout << sum << endl;
    return 0;
}


