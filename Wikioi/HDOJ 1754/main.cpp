/*#include <cstdio>
#include <algorithm>
using namespace std;
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 222222;
int MAX[maxn<<2];
void PushUP(int rt) {
	MAX[rt] = max(MAX[rt<<1] , MAX[rt<<1|1]);
}
void build(int l,int r,int rt) {
	if (l == r) {
		scanf("%d",&MAX[rt]);
		return ;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	PushUP(rt);
}
void update(int p,int sc,int l,int r,int rt) {
	if (l == r) {
		MAX[rt] = sc;
		return ;
	}
	int m = (l + r) >> 1;
	if (p <= m) update(p , sc , lson);
	else update(p , sc , rson);
	PushUP(rt);
}
int query(int L,int R,int l,int r,int rt) {
	if (L <= l && r <= R) {
		return MAX[rt];
	}
	int m = (l + r) >> 1;
	int ret = 0;
	if (L <= m) ret = max(ret , query(L , R , lson));
	if (R > m) ret = max(ret , query(L , R , rson));
	return ret;
}
int main() {
	int n , m;
	while (~scanf("%d%d",&n,&m)) {
		build(1 , n , 1);
		while (m --) {
			char op[2];
			int a , b;
			scanf("%s%d%d",op,&a,&b);
			if (op[0] == 'Q') printf("%d\n",query(a , b , 1 , n , 1));
			else update(a , b , 1 , n , 1);
		}
	}
	return 0;
}*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#define lson l, mid ,rt * 2
#define rson mid + 1, r, rt * 2 + 1
#define maxn 200010
using namespace std;
int Max[maxn * 4];
void bulid(int l, int r, int rt)
{
    if(l == r)
        scanf("%d", &Max[rt]);
    else
    {
        int mid = (l + r)/2;
        bulid(lson);
        bulid(rson);
        Max[rt]=max(Max[rt * 2] , Max[rt * 2 + 1]);
    }
}
int query(int L, int R,int l ,int r, int rt)
{
    if(L <=l && r <= R)
        return Max[rt];
    else
    {
        int mid=(l + r)>>1;
        int ans=0;
        if(L <= mid)
            ans=max(ans,query(L,R,lson));
        if (R > mid)
            ans=max(ans,query(L,R,rson));
        return ans;
    }
}
void updata(int pos,int val,int l, int r, int rt)
{
    if(l == r)
        Max[rt]=val;
    else
    {
        int mid=(l+r)>>1;
        if(pos <= mid)
            updata(pos, val,lson);
        else
            updata(pos, val, rson);
        Max[rt]=max(Max[rt * 2], Max[rt * 2 + 1]);
    }
}
int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        bulid(1 , n , 1);
        while( m--)
        {
            char op[2];
            int x,y;
            scanf("%s%d%d", op, &x, &y);
            if(op[0] == 'Q')
                printf("%d\n",query(x, y, 1, n, 1));
            else
                updata( x, y ,1 , n, 1);
        }
    }
    return 0;
}
