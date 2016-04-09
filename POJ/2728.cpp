#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#define maxn 1005
using namespace std;
typedef struct
{
    int x, y, h, s;
}Edge;
Edge edge[maxn];
int fa[maxn];
void Init(int n)
{
    for(int i = 0; i < n; ++i)
        fa[i] = i;
}
int find(int x)
{
    if(fa[x] != x)
        return fa[x] = find(fa[x]);
    return x;
}
bool comp(Edge e1, Edge e2)
{
    return e1.s < e2.s;
}
double k(int n)
{
    Init(n);
    sort(edge, edge + n - 1,comp);
    long long  ans = 0;
    double st = 0;
    int num = 0;
    for(int i = 0; i < n - 1; ++i)
    {
        Edge e = edge[i];
        if(find(e.x) != find(e.y))
        {
            //cout<<e.s<<"sdfsdfds"<<endl;
            st += e.s;
            ans += e.h;
            fa[e.x] = e.y;
            if(++num >= n - 1)
                break;
        }
    }
    //cout<<ans<<"dsfs"<<st<<endl;
    return ans / st;
}
int main()
{
    int n;
    while(cin>>n && n)
    {
        int x, y, h;
        for(int i = 0; i < n; ++i)
        {
            cin>>edge[i].x>>edge[i].y>>edge[i].h;
            if(i > 0)
            {
                edge[i - 1].s = sqrt(double(edge[i].x - edge[i - 1].x) * (edge[i].x - edge[i - 1].x) + (edge[i].y - edge[i - 1].y) * (edge[i].y - edge[i - 1].y));
                edge[i - 1].x = i;
                edge[i - 1].y = i + 1;
                edge[i - 1].h = abs(edge[i].h - edge[i - 1].h);
                    
            //cout<<edge[i - 1].s<<"sdfsdfds"<<endl;
            }
        }
        double e = k(n);
        printf("%0.3lf\n", floor(e * 1000) / 1000);
    }
    return 0;
}
