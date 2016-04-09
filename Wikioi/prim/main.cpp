/*
    prim�㷨

*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 10010
#define INF 100000
using namespace std;
//cost[u][v]����u��v��Ȩֵ
int cost[maxn][maxn];
//mincost���������һ���㵽��һ�������С����
int mincost[maxn];
//used�������������Ƿ�ʹ��
bool used[maxn];
int n,m;
long long prim()
{
    //��ʼ��mincost��used
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
        //�ҵ���С�ıߵ�Ȩֵ
        for( int i = 1; i <= n; ++i)
            if( !used[i] && (v == -1 || mincost[i] < mincost[v]))
                v=i;
        if(v == -1) break;
        used[v] = true;
        ans+=mincost[v];
        //����mincost
        for(int i = 1; i <= n; ++i)
            mincost[i]= min(mincost[i],cost[v][i]);
    }
    return ans;
}
int main()
{

    scanf("%d%d", &n, &m);
    //n�Ƕ��������m�Ǳ���
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
