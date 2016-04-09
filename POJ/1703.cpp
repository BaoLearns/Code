#include <iostream>
#define MAXN 200002
using namespace std;
int fa[MAXN];
void Init()
{
    for(int i = 1; i <= 100000; ++i)
        fa[i] = i;
    for(int i = 100001; i < MAXN; ++i)
        fa[i] = i - 10000;
}
int find(int x)
{
    return fa[x] == x? x: fa[x] = find(fa[x]);
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(cin >> t)
    {
        int n, m;
        cin >> n >> m;
        Init();
        while(m--)
        {
            char op[2];
            int x, y;
            cin >> op >> x >> y;
            int fx = find(x),fy = find(y);
            if(op[0] == 'A')
            {
                if(fx == x && fy == y) cout << "Not sure yet." << endl;
                else if(fx == fy) cout << "In the same gang." << endl;
                else cout << "In different gangs." << endl;
            }
            else
            {
                fx
            }
        }
    }
    return 0;
}


