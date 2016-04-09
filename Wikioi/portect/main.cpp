#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 10010
using namespace std;
int fa[maxn];
int f[maxn],g[maxn];
int main()
{
    int n,x,y;
    while(~scanf("%d", &n))
    {
        memset(fa,-1,sizeof(fa));
        for( int i = 1; i < n; ++i)
        {
            scanf("%d%d", &x, &y);
            fa[x]=y;
            fa[y]=x;
        }

        for(int i = 1; i <=n; ++i)
            if(fa[i] == -1)
                f[i]=g[i]=0;
        for( int i = 1; i <= n; ++i)
            for( int j = 1; j <= n; ++j)
            {
                if(i == j)
                    continue;
                if(fa[j] == i)
                {
                    f[i]+=min(f[j],g[j])+1;
                    g[i]+=f[j];
                }
            }
        printf("%d\n",f[n]);
    }
    return 0;
}
