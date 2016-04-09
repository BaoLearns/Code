#include <iostream>
#define mid (l + r) / 2
#define lson rx * 2, l, mid
#define rson rx * 2 + 1, mid + 1, r
#define maxn 200005
#define LL long long 
using namespace std;
LL tree[maxn * 4], add[maxn * 4];
void PushDown(int rx, int l, int r)
{
    if(add[rx])
    {
        //int mid = (l + r) / 2;
        tree[rx * 2] += (mid - l + 1) * add[rx];
        add[rx * 2] += add[rx];
        tree[rx * 2 + 1] += (r - mid) * add[rx];
        add[rx * 2 + 1] += add[rx];
        add[rx] = 0;
    }
}
void Bulid(int rx, int l, int r)
{
    add[rx] = 0;
    if(l == r)
    {
        cin >> tree[rx];
        return ;
    }
    //int mid = (l + r) / 2;
    Bulid(lson);
    Bulid(rson);
    tree[rx] = tree[rx * 2] + tree[rx * 2 + 1];
}
void Updata(int rx, int l, int r, int L, int R, int x)
{
    if(r < L || l > R)
        return ;
    if(L <= l && r <= R)
    {
        tree[rx] += (r - l + 1) * x;
        add[rx] += x;
        return ;
    }
    PushDown(rx, l, r);
    //int mid = (l + r) / 2;
    Updata(lson, L, R, x);
    Updata(rson, L, R, x);
    tree[rx] = tree[rx * 2] + tree[rx * 2 + 1];
}
LL Query(int rx, int l, int r, int L, int R)
{
    if(r < L || l > R)
        return 0;
    if(L <= l && r <= R)
        return tree[rx];
    PushDown(rx, l, r);
    //int mid = (l + r) / 2;
    return Query(lson, L, R) + Query(rson, L, R); 
}
int main()
{
    int n;
    cin >> n;
    Bulid(1, 1, n);
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i)
    {
        int op, l, r, x;
        cin >> op;
        if(op == 1)
        {
            cin >> l >> r >> x;
            Updata(1, 1, n, l, r, x);
        }
        else
        {
            cin >> l >> r;
            cout << Query(1, 1, n, l, r) << endl;
        }
    }
    return 0;
}
