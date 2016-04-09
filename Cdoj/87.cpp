#include <iostream>
#include <cstdio>
#define mid l + (r - l) / 2
#define lson rx * 2, l, mid
#define rson rx * 2 + 1, mid + 1, r
#define LL long long
#define MAXN 400004
using namespace std;
int n, m;
LL tree[MAXN], M[MAXN], D[MAXN];
inline void read(LL &x)
{
    scanf("%I64d", &x);
}
inline void write(LL x)
{
    printf("%I64d\n", x);
}
void Init()
{
    for(int i = 0; i < MAXN; ++i)
        tree[i] = M[i] = D[MAXN] = 1;
}
LL Pow(int k, int q)
{
    LL res = 1;
    while(q)
    {
        if(q & 1) res = res * k % m;
        k = k * k % m;
        q >>= 1;
    }
    return res;
}
void Pushdown(int rx, int l, int r)
{
    LL k = M[rx];
    if(k > 1)
    {
        cout << "1 "<< rx << " " << k << endl;
        M[rx * 2] = M[rx * 2] * k % m;
        M[rx * 2 + 1] = M[rx * 2 + 1] * k % m;
        tree[rx * 2] = tree[rx * 2] * Pow(k, mid - l + 1) % m;
        tree[rx * 2 + 1] = tree[rx * 2 + 1] * Pow(k, r - mid) % m;
        M[rx] = 1;
    }
    k = D[rx];
    if(k > 1)
    {
        cout << "2 " << rx << " " << k << endl;
        D[rx * 2] = D[rx * 2] * k % m;
        D[rx * 2 + 1] = D[rx * 2 + 1] * k % m;
        tree[rx * 2] = tree[rx * 2] / Pow(k, mid - l + 1) % m;
        tree[rx * 2 + 1] = tree[rx * 2 + 1] / Pow(k, r - mid) % m;
        D[rx] = 1;
    }
}
void Bulid(int rx, int l, int r)
{
    if(l == r)
    {
        read(tree[rx]);
        return;
    }
    Bulid(lson);
    Bulid(rson);
    tree[rx] = tree[rx * 2] * tree[rx * 2 + 1] % m;
}
LL Query(int rx, int l, int r, int L, int R)
{
    if(r < L || R < l) return 1;
    Pushdown(rx, l, r);
    if(L <= l && r <= R) return tree[rx] % m;
    return Query(lson, L, R) * Query(rson, L, R) % m;
}
void UpdataM(int rx, int l, int r, int L, int R, int val)
{
    if(r < L || R < l) return;
    Pushdown(rx, l, r);
    if(L <= l && r <= R)
    {
        tree[rx] = tree[rx] * Pow(val, r - l + 1) % m;
        M[rx] = M[rx] * val % m;
        return;
    }
    UpdataM(lson, L, R, val);
    UpdataM(rson, L ,R, val);
}
void UpdataD(int rx, int l, int r, int L, int R, int val)
{
    if(r < L || R < l) return;
    Pushdown(rx, l, r);
    if(L <= l && r <= R)
    {
        tree[rx] = tree[rx] / Pow(val, r - l + 1) % m;
        D[rx] = D[rx] * val % m;
        return;
    }
    UpdataD(lson, L, R, val);
    UpdataD(rson, L ,R, val);
}
int main()
{
    int T;
    scanf("%d", &T);
    for(int I = 1; I <= T; ++I)
    {
        Init();
        scanf("%d%d", &n, &m);
        Bulid(1, 1, n);
        printf("Case #%d:\n", I);
        int Q;
        scanf("%d", &Q);
        while(Q--)
        {
            char op[2];
            scanf("%s", op);
            if(op[0] == 'Q') 
            {
                int L, R;
                scanf("%d%d", &L, &R);
                write(Query(1, 1, n, L, R));
            }
            else
            {
                int L, R, val;
                scanf("%d%d%d", &L, &R, &val);
                if(op[0] == 'D') UpdataD(1, 1, n, L, R, val);
                else UpdataM(1, 1, n, L, R, val);
            }
        }
    }
    return 0;
}
