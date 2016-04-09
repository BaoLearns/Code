#include <iostream>
#define maxn 100
using namespace std;
int fa[maxn];
void Init(int n)
{
    for(int i = 1; i <= n; ++i)
        fa[i] = i;
}
int Find(int x)
{
    if(fa[x] != x)
        return fa[x] = Find(fa[x]);
    else
        return fa[x];
}
void Unio(int x, int y)
{
    int fx = Find(x), fy = Find(y);
    if(fx != fy)
        fa[fx] = fy;

}
int main()
{
    int n, num;
    cin>>n>>num;
    Init(n);
    for(int i = 0; i < num; ++i)
    {
        int a, b;
        cin>>a>>b;
        Unio(a, b);
    }
    int m;
    cin>>m;
    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin>>a>>b;
        cout<<(Find(a) == Find(b)? "YES\n": "NO");
    }
    return 0;
}
