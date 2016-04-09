#include <iostream>
#include <algorithm>
#include <cstring>
#define maxn 105
using namespace std;
int a[maxn][maxn];
int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        memset(a, 0, sizeof(a));
        for(int i = 0; i < m; ++i)
        {
            int x, y;
            cin >> x >> y;
            a[x][y] = 1;  
        }
        bool flag = true;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(i != j)
                {
                    for(int k = 1; k <= n; ++k)
                        if(a[i][j] && a[j][k])
                            a[i][k] = 1;
                }
            }
            if(a[i][i] == 1) {flag = false;break;}
        }
        cout << (flag? "YES": "NO") << endl;
    }
    return 0;
}
