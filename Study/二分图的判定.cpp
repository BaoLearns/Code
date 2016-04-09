
/*
 * 二分图的判定
 * 即任何两个相邻顶点所图颜色各不相同，且只有两种颜色可图1，-1
*/
#include <cstdio>
#include <cstring>
#define maxn 10000
//邻接矩阵存储无向图
int edge[maxn][maxn];
//存放颜色，取值{-1，0, 1}，当值为0时表示当前点没有涂色
int color[maxn];
//V是顶点数目（0 — V-1），M是边数
int V, M;
bool dfs(int a, int v)
{
    //将a节点涂色为v
    color[a] = v;
    for(int i = 0; i < V; ++i)
    {
        //如果a跟i相邻，并且涂色也相同，则涂色失败
        if(edge[a][i] && color[i] == v)
            return false;
        //如果a跟i相邻，并且i没有被涂色，并且将i的相邻节点涂色为-v失败，则所有涂色失败
        if(edge[a][i] && color[i] == 0 && !dfs(i, -v))
            return false;
            
    }
    //涂色成功
    return true;
}
int main()
{
    
    scanf("%d%d", &V, &M);
    for(int i = 0; i < M; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        edge[u][v] = 1;
        edge[v][u] = 1;
    }
    //初始化所有节点为0，表示所有节点当前没有被涂色
    memset(color, 0, sizeof(color));
    int i;
    for( i = 0; i < V; ++i)
    {
        if(color[i] == 0)
        {
            if(!dfs(i, 1))
                break;
        }
    }
    //如果涂色成功则Yes，否则No
    printf("%s\n", i >= V? "Yes": "No");
    if(i >= V)
    {
        for( int j = 0; j < V; ++j)
            printf("%d ",color[j]);
        putchar('\n');
    }
    return 0;
}
