#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 1e7
#define MAXN 507
using namespace std;
int d[MAXN][MAXN];
int Prim(int v)
{
    int mincost[MAXN];
    fill(mincost, mincost + MAXN, INF);
    mincost[0] = 0;
    bool used[MAXN];
    memset(used, false, sizeof used);
    int ans = 0;
    while(true)
    {
        int u = -1;
        for(int i = 0; i < v; ++i)
        {
            if(!used[i] && (u == -1 || mincost[u] > mincost[i]))
                u = i;
        }
        if(u == -1) break;
        used[u] = true;
        ans = max(ans, mincost[u]);
        for(int i = 0; i < v; ++i)
            mincost[i] = min(mincost[i], d[i][u]);
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%d", &d[i][j]);
        printf("%d\n", Prim(n));
    }
    return 0;
}
