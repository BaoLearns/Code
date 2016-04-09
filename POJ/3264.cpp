#include <iostream>
#include <algorithm>
#define maxn 50005
#define mid (l + r) / 2
#define lson rx << 1, l, mid
#define rson (rx << 1) |1, mid + 1, r
using namespace std;
typedef struct
{
    int Max, Min;
}Tree;
Tree tree[maxn * 4];
int Max, Min;
void bulid(int rx, int l, int r)
{
    if(l == r)
    {
        scanf("%d", &tree[rx].Max);
        tree[rx].Min = tree[rx].Max;
        return ;
    }
    bulid(lson);
    bulid(rson);
    tree[rx].Max = max(tree[rx << 1].Max, tree[rx << 1 | 1].Max);
    tree[rx].Min = min(tree[rx << 1 | 1].Min, tree[rx << 1].Min);
}
void query(int rx, int l, int r, int L, int R)
{
    if(r < L || l > R)
        return ;
    if(L <= l && r <= R)
    {
        Max = max (tree[rx].Max,Max);
        Min = min (tree[rx].Min, Min);
        return ;
    }
    query(lson, L, R);
    query(rson, L, R);
}
int main()
{
    int N, Q;
    cin >> N >> Q;
    bulid(1, 1, N);
    for(int i = 0; i < Q; ++i)
    {
        int L, R;
        scanf("%d%d", &L, &R);
        Max = 0, Min = 10000005;
        query(1, 1, N, L, R);
        query(1, 1, N, L, R);
        printf("%d\n", Max - Min);     
    }
    
    return 0;
}
