#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct edge
{
    int u,v,w;
}ed[1010];
int fa[1010];
int cmp(const void *a, const void *b)
{
	if ((*(edge *)a).w == (*(edge *)b).w)
	{
		return (*(edge *)a).u - (*(edge *)b).u;
	}
	return (*(edge *)a).w - (*(edge *)b).w;
}
int find( int x)
{
    return fa[x]= fa[ x] == x? x:find(fa[x]);
}
int main()
{
    freopen("earthquake.in","r",stdin);
    freopen("earthquake.out","w",stdout);
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for( int i = 1; i <= m; ++i)
        {
            scanf("%d%d%d",&ed[i].u,&ed[i].v,&ed[i].w);
        }
        for( int i = 1; i <= n; ++i)
            fa[i]=i;
        qsort(ed+1,n,sizeof(edge),cmp);
        int ans=0;
        for( int i = 1; i <= m; ++i)
        {
            int x=find(ed[i].u);
            int y=find(ed[i].v);
            if(x != y)
            {
                ans+=ed[i].w;
                fa[x]=y;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
