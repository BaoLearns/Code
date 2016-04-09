#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define MAXN 507
#define INF 1e7
using namespace std;
struct node
{
    int u, v, cost;
    node(int _u, int _v, int _cost)
    {
        u = _u, v = _v, cost = _cost;
    }
};
vector <node> side;
bool find(int n, int m)
{
    int d[n], cnt = 0;
    fill(d, d + n, INF);
    d[1] = 0;
    while(true)
    {
        bool flag = false;
        for(int i = 0; i < m; ++i)
        {
            node e = side[i];
            if(d[e.v] > d[e.u] + e.cost)
            {
                d[e.v] = d[e.u] + e.cost;
                flag = true;
            }
        }
        if(!flag) break;
        if(++cnt >= n) return true;
    }
    return false;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        side.clear();
        int n, m, w;
        scanf("%d%d%d", &n, &m, &w);
        for(int i = 0; i < m; ++i)
        {
            int u, v, cost;
            scanf("%d%d%d", &u, &v, &cost);
            side.push_back(node(u, v, cost));
            side.push_back(node(v, u, cost));
        }
        for(int i = 0; i < w; ++i)
        {
            int u, v, cost;
            scanf("%d%d%d", &u, &v, &cost);
            side.push_back(node(u, v, -cost));
        }
        puts(find(n, 2 * m + w)? "YES": "NO");
    }
    return 0;
}
