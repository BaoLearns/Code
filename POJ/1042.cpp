#include <iostream>
#include <cstdio>
#define MAXN 30
using namespace std;
int h, n, f[MAXN], d[MAXN], t[MAXN], arr[MAXN], ans[MAXN];
void dfs(int dep, int H, int num)
{
    for(int i = 0; i < H / 5; ++i)
    {
        dep(dep + 1, H - i * 5, num + arr[dep]);
    }
}
int main()
{
    while(scaf("%d", &h, 0)
    {
        scanf("%d", &n)
        for(int i = 0; i < n; ++i)
            scanf("%d", &f[i]);
        for(int i = 0; i < n; ++i)
            scanf("%d", &d[i]);
        for(int i = 0; i < n - 1; ++i)
            scanf("%d", &t[i]);
        dfs();        
    }
    return 0;
}
