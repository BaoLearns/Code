#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 501
using namespace std;
struct Edge
{
    int u, v, c;
    bool operator <(const Edge a) const
    {
        return c < a.c;
    }
};
Edge edge[MAXN];
int fa[MAXN];
int read()
{
    char ch;
    while(ch = getchar(), ch == ' ' || ch == '\t' || ch == EOF || ch == '\n');
    int v = ch - '0';
    while(ch = getchar(), ch != ' ' && ch != '\t' && ch != EOF && ch != '\n')
        v = v * 10 + ch - '0';
    return v;
}
int find(int x)
{
    return fa[x] = fa[x] == x? x: find(fa[x]);
}
void solve(int n)
{
    for(int i = 0; i < MAXN; ++i)
        fa[i] = i;
    sort(edge, edge + n);
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        Edge e = edge[i];
        int fx = find(e.u), fy = find(e.v);
        if(fx != fy)
        {
            fa[fx] = fy;
            ans = max(ans, e.c);
        }
    }
    cout << ans << endl;
}
int main()
{
    int t = read();
    while(t--)
    {
        int n = read(), pos = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
            {
                int e = read();
                if(i < j)
                {
                    edge[pos].u = i;
                    edge[pos].v = j;
                    edge[pos++].c = e;
                }
            }
        solve(pos);
    }
    return 0;
}
