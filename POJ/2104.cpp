#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#define MAXN 100007
#define mid l + (r - l) / 2
#define lson rx * 2, l, mid
#define rson rx * 2 + 1, mid + 1, r
using namespace std;
vector <int> arr;
vector <int> tree[1 << 18];
void Bulid(int rx, int l, int r)
{
    if(l == r)
    {
        int val;
        scanf("%d", &val);
        tree[rx].push_back(val);
        arr.push_back(val);
        return ;
    }
    Bulid(lson);
    Bulid(rson);
    tree[rx].resize(1 + r - l);
    merge(tree[rx * 2].begin(), tree[rx * 2].end(), tree[rx * 2 + 1].begin(), tree[rx * 2 + 1].end(), tree[rx].begin());
    for(auto it:tree[rx])
        cout << it << " ";
    cout << endl;
}
int Query(int rx, int l, int r, int L, int R, int val)
{
    if(R <= l || r <= L) return 0;
    if(l >= L && r <= R)
        return upper_bound(tree[rx].begin(), tree[rx].end(), val) - tree[rx].begin();
    return Query(lson, L, R, val) + Query(rson, L, R, val);
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    Bulid(1, 1, n);
    sort(arr.begin(), arr.end());
    while(m--)
    {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        int start = -1, end = n - 1;
        while(end - start > 1)
        {
            int Mid = start + (end - start) / 2;
            int cnt = Query(1, 1, n, l, r, arr[Mid]);
            if(cnt >= k) end = Mid;
            else start = Mid;
        }
        printf("%d\n", arr[end]);
    }
    return 0;
}
