#include <iostream>
#include <cstring>
#define MAXN 16
using namespace std;
int m, n;
int tile[MAXN][MAXN];
int flip[MAXN][MAXN], ans[MAXN][MAXN];
int dir[5][2] = {0, 0, -1, 0, 0, 1, 1, 0, 0, -1};
int get(int x, int y)
{
    int c = tile[x][y];
    for(int i = 0; i < 5; ++i)
    {
        int dx = x + dir[i][0], dy = y + dir[i][1];
        if(dx >= 0 && dx < m && dy >= 0 && dy < n)
            c += flip[dx][dy];
    }
    return c % 2;
}
int calc()
{
    for(int i = 1; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(get(i - 1, j))
                flip[i][j] = 1;
        }
    }
    for(int i = 0; i < n; ++i)
        if(get(m - 1, i))
            return -1;
    int c = 0;
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
            c += flip[i][j];
    }
    return c;
}
int main()
{
    while(cin >> m >> n)
    {
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                cin >> tile[i][j];
        int res = 1000007;
        for(int i = 0; i < (1 << n); ++i)
        {
            memset(flip, 0, sizeof(flip));
            for(int j = 0; j < n; ++j)
                flip[0][n - j - 1] = (i >> j) & 1;
            int cnt = calc();
            //cout << cnt << endl;
            if(cnt != -1 && cnt < res)
            {
                res = cnt;
                for(int i = 0; i < m; ++i)
                    for(int j = 0; j < n; ++j)
                        ans[i][j] = flip[i][j];
            }
            cout << "!!!!!" << endl;
            if(cnt != -1)
            for(int i = 0; i < m; ++i)
            {
                for(int j = 0; j < n; ++j)
                    cout << flip[i][j] << " ";
                cout << endl;
            }
        }
        if(res != 1000007)
        {
            for(int i = 0; i < m; ++i)
            {
                for(int j = 0; j < n; ++j)
                    cout << ans[i][j] << " ";
                cout << endl;
            }
        }
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
