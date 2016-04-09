/*
 * 最短路
 * dijkstra单源最短路
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 2010
#define INF 1000000000
//cost[i][j]i到j的距离
int cost[maxn][maxn];
int n, m;
//存放最终的距离
int d[maxn];
//标记是否使用过
bool used[maxn];
void dijkstra(int s)
{

    //初始化代价数组d，所有点标记为没有使用
    for( int i = 1; i <= n; ++i)
        d[i] = INF, used[i] = false;
    //自己到自己的距离设置为0
    d[s] = 0;
    while(true)
    {
        int v = -1;
        for(int i = 1; i <= n; ++i)
        {
            //找到代价最小的点
            if(!used[i] && (v == -1 || d[i] < d[v]))
                v = i;
        }
        if(v == -1)
            break;
        used[v] = true;
        //更新代价，取小值
        for(int i = 1; i <= n; ++i) 
            d[i]= min( d[i], d[v] + cost[v][i]);
    }
} 
int main()
{
    //顶点数为n，有m条边
    scanf("%d%d", &n, &m);
    //初始化cost
    for( int i = 0; i <= n; ++i)
        for(int j = 0; j <= n; ++j)
            cost[i][j] = INF;
    for( int i = 0; i < m; ++i)
    {
        int v, u, w;
        scanf("%d%d%d", &v, &u, &w);
        cost[v][u] = w;
    }
    int s;
    scanf("%d", &s);
    //求解s到各个顶点的最短距离
    dijkstra(s);
    for(int i = 1; i <= n; ++i)
        printf("%d ", d[i]);
    putchar('\n');
    return 0;
}
