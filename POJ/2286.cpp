/*#include <iostream>
using namespace std;
int N, M;
string st[101];
int ans = 0;
//int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};
int dir[8][2]={{0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
void solve(int n, int m)
{
    for(int i = 0; i < 8; ++i)
    {
        int dx = n + dir[i][0], dy = m + dir[i][1];
        if(st[dx][dy] == 'W' && dx >= 0 && dx < N && dy >= 0 && dy < M)
        {
            st[dx][dy] = '.';
            solve(dx, dy);
        }
    }
}
int main()
{
    cin>> N>> M;
    for(int i = 0; i < N; ++i)
       cin>> st[i];
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            if(st[i][j] == 'W')
            {
                st[i][j] == '.';
                ans++;
                solve( i, j);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}*/

#include <iostream>
#include <cstring>
#define maxn 10002
using namespace std;
bool hash[maxn];
int main()
{
    memset(hash, true, sizeof(hash));
    for(int i = 1; i < 10000; ++i)
    {
        int m = i, sum = 0;
        while(m)
        {
            sum += m % 10;
            m /= 10;
        }
        hash[i + sum] = false;
        if(hash[i])
            cout<<i<<endl;
    }
    return 0;
}
