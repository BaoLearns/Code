#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 50001
#define Pii pair <int, int>
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
vector <Pii> vec;
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
    vec.clear();
    for(int i = 0; i < n; ++i)
    {
        Edge e = edge[i];
        int fx = find(e.u), fy = find(e.v);
        if(fx != fy)
        {
            fa[fx] = fy;
            vec.push_back(Pii(e.u, e.v));
            ans = max(ans, e.c);
        }
    }
    cout << ans << endl;
    cout << vec.size() << endl;
    for(int i = 0; i < vec.size(); ++i)
        cout << vec[i].first << " " << vec[i].second << endl;
}
int main()
{
    int n = read(), m = read();
    for(int i = 0; i < m; ++i)
    {
        edge[i].u = read();
        edge[i].v = read();
        edge[i].c = read();
    }
    solve(m);
    return 0;
}

