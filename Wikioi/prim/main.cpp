/*
    prim算法

*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 10010
#define INF 100000
using namespace std;
//cost[u][v]便是u到v的权值
int cost[maxn][maxn];
//mincost，用来存放一个点到另一个点的最小话费
int mincost[maxn];
//used用来标记这个点是否被使用
bool used[maxn];
int n,m;
long long prim()
{
    //初始化mincost，used
    for( int i = 1; i <= n; ++i)
    {
        mincost[i]= INF;
        used[i]=false;
    }
    mincost[1]=0;
    long long  ans=0;
    while(true)
    {
        int v=-1;
        //找到最小的边的权值
        for( int i = 1; i <= n; ++i)
            if( !used[i] && (v == -1 || mincost[i] < mincost[v]))
                v=i;
        if(v == -1) break;
        used[v] = true;
        ans+=mincost[v];
        //更新mincost
        for(int i = 1; i <= n; ++i)
            mincost[i]= min(mincost[i],cost[v][i]);
    }
    return ans;
}
int main()
{

    scanf("%d%d", &n, &m);
    //n是顶点个数，m是边数
    for(int i = 1; i <= m; ++i)
    {
        int x,y,z;
        scanf("%d%d%d", &x, &y, &z);
        cost[x][y]=z;
        cost[y][x]=z;
    }
    printf("%lld\n",prim());
    return 0;

}
