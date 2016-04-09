#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 101
using namespace std;
class Edge
{
public:
    int from, to, cost;
    Edge(int f, int t, int c)
    {
        from = f;
        to = t;
        cost = c;
    }
    bool operator < (const Edge a) const
    {
        return a.cost > cost;
    }
};
vector <Edge> edge;
int fa[MAXN];
int find(int x)
{
    return fa[x] == x? x: fa[x] = find(fa[x]);
}
void solve()
{ 
    for(int i = 0; i < MAXN; ++i) fa[i] = i;
    sort(edge.begin(), edge.end());
    int ans = 0;
    for(int i = 0; i < edge.size(); ++i)
    {
        Edge e = edge[i];
        int fx = find(e.from), fy = find(e.to);
        if(fx != fy)
        {
            fa[fx] = fy;
            ans += e.cost;
        }  
    }
    printf("%d\n", ans);
}
int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        edge.clear();
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
            {
                int c;
                scanf("%d", &c);
                if(i != j) edge.push_back(Edge(i, j, c));
            }
        solve();
    }
    return 0;
}
