/*#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define N 210
#define INF 99999999

using namespace std;

struct Edge
{
    int to, cost;
    Edge(int tt = 0, int cc = 0) : to(tt), cost(cc) {}
};

vector<Edge> G[N];
queue<int> que;
int V, E, dis[N], cnt[N];
bool inque[N]; //检测该点是否在队列中

bool SPFA(int s, int end)
{ 
    fill(inque, inque + V + 1, false);
    fill(dis, dis + V + 1, INF);
    fill(cnt, cnt + V + 1, 0);
    dis[s] = 0;//单源最短路起点
    inque[s] = true;
    que.push(s);
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        inque[v] = false;//出队标记
        for (int i = 0; i < G[v].size(); ++i)
        {
            Edge e = G[v][i];
            if (dis[v] != INF && dis[e.to] > dis[v] + e.cost)
            {   //松弛操作（三角不等式）
                cnt[e.to]++;
                if (cnt[e.to] > V)
                {
                    printf("-1\n"); return false;
                }
                dis[e.to] = dis[v] + e.cost;
                if (!dis[e.to])
                {
                    que.push(e.to);
                    inque[e.to] = true;//入队标记
                }                
            }
        }
    }
    printf("%d\n", dis[end]);
    return true;
}

int main()
{
    int s, e, f, t, c;
    while (scanf("%d%d", &V, &E))
    {
        for(int i = 0; i < V; ++i)
		G.clear();
        for (int i = 0; i < E; ++i)
        {
            scanf("%d%d%d", &f, &t, &c);
            G[f].push_back(Edge(t, c));
            G[t].push_back(Edge(f, c));
        }
        scanf("%d%d", &s, &e);
        SPFA(s, e);
    }
    return 0;
}
*/
/*#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include<utility>
using namespace std;
#define INF 99999999
class Edge
{ 
    public:
    int to, cost;
    Edge(int t = 0, int c = 0):to(t),cost(c){}//构造函数
};
vector <Edge> G[100];
int d[100],cnt[100];
bool vis[100];
//bitset<100> vis;-
int V, E;
bool SPFA(int s, int e)
{
    queue <int > que;
    fill(d, d + V + 1, INF);
    //vis.reset();
    fill(vis, vis + V + 1, false);
    fill(cnt, cnt + V + 1, 0);
    que.push(s);
    vis[s] = true;
    d[s] = 0;
    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        vis[v] = false;
        for(int i = 0; i < G[v].size(); ++i)
        {
            Edge e = G[v][i];
            if(d[v] != INF && d[e.to] > d[v] + e.cost)
            {
                cnt[e.to]++;
                d[e.to] = d[v] + e.cost;
                if(cnt[e.to] >= V)
                    return false;
                if(!vis[e.to])
                {
                    que.push(e.to);
                    vis[e.to] = true;
                }
            }   
        }
    }
    return true;
}
int main()
{
    
    scanf("%d%d", &V, &E);
    for(int i = 0; i < E; ++i)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back( Edge(v, w));
        G[v].push_back( Edge(u, w));
    }
    int s, e;
    scanf("%d%d", &s, &e);
    bool c = SPFA(s, e);
    if(c)
        printf("%d\n",d[e]);
    else
        printf("No!\n");
    return 0;
}
*/
//u,v,w;
//G[u].push_back(make_pair(v,w));

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define maxn 105
#define INF 10000007
using namespace std;
class Edge
{
public:
    int to, cost;
    Edge(int t, int c)
    {
        to = t;
        cost = c;
    }
};
vector <Edge> G[maxn];
bool Inque[maxn];
int cnt[maxn], d[maxn];
bool SPFA(int V, int E, int s, int e)
{
    fill(Inque, Inque + maxn, false);
    fill(cnt, cnt + maxn, 0);
    fill(d, d + maxn, INF);
    queue <int> que;
    que.push(s);
    Inque[s] = true;
    cnt[s] = 1;
    d[s] = 0;
    while(!que.empty())
    {
        int val = que.front();
        que.pop();
        Inque[val] = false;
        for(int i = 0; i < G[val].size(); ++i)
        {
            Edge e = G[val][i];
            if(d[val] != INF && d[e.to] > d[val] + e.cost)
            {
                d[e.to] = d[val] + e.cost;
                cnt[e.to]++;
                if(cnt[e.to] == V)
                    return false;
                if(!Inque[e.to])
                {
                    que.push(e.to);
                    Inque[e.to] = true;
                }
            }
        }
    }
    return true;
}
int main()
{
    //freopen("text.txt", "r", stdin);
    int V, E;
    int to, from, cost;
    while(~scanf("%d%d", &V, &E))
    {
        for(int i = 0; i < E; ++i)
        {
            scanf("%d%d%d", &from, &to, &cost);
            G[from].push_back(Edge(to, cost));
            G[to].push_back(Edge(from, cost));
        }
        int s, e;
        scanf("%d%d", &s, &e);
        if(SPFA(V, E, s, e))
            printf("%d\n", d[e]);
        else
            printf("-1\n");
    }
    return 0;
}
