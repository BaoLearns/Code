//线段树，单点更新，区间更新，区间查询
#include <bits/stdc++.h>
#define mid (l + r) / 2
#define lson rx * 2, l, mid  
#define rson rx * 2 + 1, mid + 1, r   
#define maxn 10001
#define LL long long
using namespace std;

int tree[maxn];    // 存放区间的和
int add[maxn];     // 区间的累加值（懒操作）

//下放累加值
void PushDown(int rx, int l, int r)  
{
    if(add[rx])
    { 
        tree[rx * 2] += (mid - l + 1) * add[rx];
        add[rx * 2] += add[rx];
        tree[rx * 2 + 1] += (r - mid) * add[rx];
        add[rx * 2 + 1] += add[rx];
        add[rx] = 0;
    }
}

//建树
void Bulid(int rx, int l, int r)
{
    add[rx] = 0;
    if(l == r)
    {
        cin >> tree[rx];
        return ;
    }
    Bulid(lson);
    Bulid(rson);
    tree[rx] = tree[rx * 2] + tree[rx * 2 + 1];
}

//单点更新
void UpdataPoint(int rx, int l, int r, int pos, int val)
{
    if(l == r)
    {
        tree[rx] = val;
        return ;
    }
    if(mid >= pos) UpdataPoint(lson, pos, val);
    else UpdataPoint(rson, pos, val);
    tree[rx] = tree[rx * 2] + tree[rx * 2 + 1];
}

//区间更新
void UpdataSection(int rx, int l, int r, int L, int R, int val)
{
    if(l > R || r < L)
        return ;
    if(L <= l && r <= R)
    {
        tree[rx] += (r - l + 1) * val;
        add[rx] += val;
        return ;
    }
    PushDown(rx, l, r);
    UpdataSection(lson, L, R, val);
    UpdataSection(rson, L, R, val);
}

//区间查询
LL Query(int rx, int l, int r, int L, int R)
{
    if(l > R || r < L)
        return 0;
    PushDown(rx, l, r);
    if(L <= l && r <= R)
        return tree[rx];
    return Query(lson, L, R) + Query(rson, L, R);
}
int main()
{
    int n, m;
    cin >> n;
    Bulid(1, 1, n);
    cin >> m;
    for(int i = 0; i < m; ++i)
    {
        int op;
        cin >> op;
        int l, r, pos, x;
        if(op == 1)
        {
            cin >> l >> r;
            cout << Query(1, 1, n, l, r) << endl;
        }
        else if(op == 2)
        {
            cin >> pos >> x;
            UpdataPoint(1, 1, n, pos, x);
        }
        else
        {
            cin >> l >> r >> x;
            UpdataSection(1, 1, n, l, r, x);
        }
    }
    return 0;
}
