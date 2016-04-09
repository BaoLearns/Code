#include <cstdio>
#define mid l + (r - l) / 2
#define lson rx << 1, l, mid
#define rson rx << 1 | 1, mid + 1, r
#define maxn 100005 * 2
using namespace std;
int arr[maxn], tree[maxn];
void Bulid(int rx, int l, int r)
{
    if(l == r)
    {
        tree[rx] = arr[l];
        return ;
    }
    Bulid(lson);
    Bulid(rson);
    tree[rx] = 
}
int main()
{
    int n, q;
    while(scanf("%d", &n) != EOF && n)
    {
        scanf("%d", &q);
        int Old, New, pos = 1;
        arr[pos++] = 0;
        scanf("%d", &Old);
        for(int i = 1; i < n; ++i)
        {
            scanf("%d", &New);
            if(Old != New)
            {
                arr[pos++] = i;
                arr[pos++] = i;
                Old = New;
            }
        }
        arr[pos++] = n;
        arr[pos++] = n;
    }
    return 0;
}

