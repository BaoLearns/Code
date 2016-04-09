/*
 * 最短路
 * Bellman-ford单源最短路
*/
/*
#include <cstdio>
#define maxn 100000
#define INF 10000000
//from到to的的代价是cost
struct Edge
{
    int from, to, cost;
}edge[maxn];
//用来存放代价
int d[maxn];
//共E条边，V个顶点（1 - V）
int E,V;
void Bellman_Ford(int s)
{
    //初始化代价数组为INF
    for(int i = 1; i <= V; ++i)
        d[i] = INF;
    //将自己到自己的代价设置为0
    d[s] = 0;
    while(true)
    {
        //flag用来标记
        bool flag = true;
        for(int i = 0; i < E; ++i)
        {
            Edge e = edge[i];
            //如果s到e.from的代价已被更新过并且 s到e.to的代价大于是到e.from加上e.cost的代价，则更新s到e.to代价
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost)
            {
                flag = false;
                d[e.to] = d[e.from] + e.cost;
            }
        }
        if(flag == true)
            break;
    }
}

int main()
{
    scanf("%d%d", &E, &V);
    for(int i = 0; i < E; ++i)
        scanf("%d%d%d", &edge[i].from, &edge[i].to, &edge[i].cost);
    int s;
    scanf("%d", &s);
    //求s点到各个顶点的最小代价
    Bellman_Ford(s);
    for(int i = 1; i <= V; ++i)
        printf("%d ", d[i]);
    putchar('\n');
    return 0;
}
*/
/*
#include <iostream>
#define maxn 1005
#define INF 10000007
using namespace std;
typedef struct Edge
{
    int from, to, cost;
}Edge;
Edge edge[maxn];
int V, E;
int d[maxn];
void shortest_path(int s)
{
    fill(d, d + maxn, INF);
    d[s] = 0;
    while(true)
    {
        bool flag = false;
        for(int i = 0; i < E; ++i)
        {
            Edge e = edge[i];
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost)
            {
                d[e.to] = d[e.from] + e.cost;
                flag = true;
            }
        }
        if(!flag)
            break;
    }
}
int main()
{
    cin >> V >> E;
    for(int i = 0; i < E; ++i)
        cin >> edge[i].from >> edge[i].to >> edge[i].cost;
    int s;
    cin >> s;
    shortest_path(s);
    int e;
    while(cin >> e)
    {
        cout << d[e] << endl;
    }
    return 0;
}
*/
/*
#include <iostream>
#define maxn 1005
#define INF 10000007
using namespace std;
int cost[maxn][maxn],d[maxn];
int V, E;
bool vised[maxn];
void Init()
{
    for(int i = 0; i < maxn; ++i)
        for(int j = 0; j < maxn; ++j)
            cost[i][j] = INF;
}
void Dijstra(int s)
{
    fill(d, d + maxn, INF);
    d[s] = 0;
    while(true)
    {
        int v = -1;
        for(int i = 0; i < V; ++i)
        {
            if(!vised[i] && (v == -1 || d[i] < d[v])) v = i;
        }
        if(v == -1) break;
        vised[v] = true;
        for(int i = 0; i < V; ++i)
            d[i] = min(d[i], cost[v][i]);
    }
}
int main()
{
    Init();
    cin >> V >> E;
    for(int i = 0; i < E; ++i)
    {
        int from, to, val;
        cin >> from >> to >> val;
        cost[from][to] = val;
    }
    int s;
    cin >> s;
    Dijstra(s);
    int e;
    while(cin >> e)
        cout << d[e] << endl;
    return 0;
}

*/
#include <iostream>
#include <vector>
#include <queue>
#define maxn 1005
#define P pair <int, int>
#define INF 10000007
using namespace std;
vector <P> G[maxn];
bool inque[maxn];
int d[maxn], cnt[maxn];
int V, E;
bool SPFA(int s)
{
    fill(d, d + maxn, INF);
    fill(cnt, cnt + maxn, 0);
    fill(inque, inque + maxn, false);
    queue <int> que;
    que.push(s);
    inque[s] = true;
    cnt[s]++;
    d[s] = 0;
    while(!que.empty())
    {
        int e = que.front();
        que.pop();
        inque[e] = false;
        for(int i = 0; i < G[e].size(); ++i)
        {
            P E = G[e][i];
            if(d[e] != INF && d[E.first] > d[e] + E.second)
            {
                //d[e] = d[G[e][i].first] + G[e][i].second;
                d[E.first] = d[e] + E.second;
                cnt[E.first]++;
                if(cnt[E.first] == V)
                    return false;
                if(!inque[E.first])
                {
                    que.push(E.first);
                    inque[E.first] = true;
                }
            }
        }
    }
    return true;
}
int main()  
{
    cin >> V >> E;
    for(int i = 0; i < E; ++i)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        G[from].push_back(P(to, cost));
        //G[to].push_back(P(from, cost));
    }
    int s, e;
    cin >> s;
    if(!SPFA(s)) return 0;
    while(cin >> e)
        cout << d[e] << endl;
    return 0;
}
/*
4 5
1 2 2
1 3 5
1 4 10
3 4 3
2 4 1
*/
/*
#include <iostream>
#include <algorithm>
#define maxn 1005
using namespace std;
class Edge
{
public:
    int from, to, cost;
    bool operator < (const Edge a)
    {
        return cost < a.cost;
    }
};
Edge edge[maxn];
int fa[maxn], V, E;
void Init()
{
    for(int i = 0; i < maxn; ++i)
        fa[i] = i;
}
int find(int x)
{
    return fa[x] = fa[x] == x? x: find(fa[x]);
}
int Kulsker()
{
    sort(edge, edge + E);
    int res = 0;
    for(int i = 0; i < E; ++i)
    {
        Edge e = edge[i];
        int fx = find(e.from), fy = find(e.to);
        if(fx != fy)
        {
            fa[fx] = fy;
            res += e.cost;
        }
    }
    return res;
}
int main()
{
    Init();
    //int V, E;
    cin >> V >> E;
    for(int i = 0; i < E; ++i)
        cin >> edge[i].from >> edge[i].to >> edge[i].cost;
    cout << Kulsker() << endl;
    return 0;
}

*/
