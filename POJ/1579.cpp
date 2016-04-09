#include <iostream>
#include <cstdio>
#define MAXN 21
using namespace std;
int w[MAXN][MAXN][MAXN];
int dfs(int a, int b, int c)
{
    if(a >= 0 && a < MAXN && b >= 0 && b < MAXN && c >= 0 && c < MAXN && w[a][b][c] != 0) return w[a][b][c];
    int temp;
    if(a <= 0 || b <= 0 || c <= 0) temp = 1;
    else if(a > 20 || b > 20 || c > 20) temp = dfs(20, 20, 20);
    else if(a < b && b < c) temp = dfs(a, b, c - 1) + dfs(a, b - 1, c - 1) - dfs(a, b - 1, c);
    else temp = dfs(a - 1, b, c) + dfs(a - 1, b - 1, c) + dfs(a - 1, b, c - 1) - dfs(a - 1, b - 1, c - 1);
    if(a >= 0 && a < MAXN && b >= 0 && b < MAXN && c >= 0 && c < MAXN) w[a][b][c] = temp;
    return temp;
    
}
int main()
{
    int a, b, c;
    while(cin >> a >> b >> c)
    {
        if(a == -1 && b == -1 && c == -1) break;
        for(int i = 0; i < MAXN; ++i)
            for(int j = 0; j < MAXN; ++j)
                for(int k = 0; k < MAXN; ++k)
                    w[i][j][k] = 0;
        printf("w(%d, %d, %d) = %d\n", a, b, c, dfs(a, b, c));
    }
    return 0;
}
