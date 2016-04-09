#include <iostream>
#include <string.h>
#include <queue>
#define maxn 10005
#define P pair <string, int>
#define MP make_pair
using namespace std;
bool prim[maxn];
bool has[maxn];
int ans = maxn * 5;
string L, R;
void Is_prim()
{
    for(int i = 2; i * i < maxn; ++i)
    {
        if(!prim[i])
        for(int j = 2 * i; j < maxn; j += i)
            prim[j] = true;
    }
}
/*void dfs(string st, int cnt)
{
    if(st == R)
    {
        ans = min(ans, cnt);
        return;
    }
    //has[e] = true;
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 10; ++j)
        {
            if((i == 0 && j == 0) || (st[i] - '0' == j))
                continue;
            int val = 0;
            for(int k = 0; k < 4; ++k)
            {
                if(k == i)
                    val = val * 10 + j;
                else
                    val = val * 10 + st[k] - '0';
            }
            string s = st;  // s = st
            s[i] = j + '0';     
            if(!prim[val] && !has[val])
            {
                cout << val << endl;
                has[val] = true;
                dfs(s, cnt + 1);
                has[val] = false;
            }
        }
    }
}*/
void bfs()
{
    queue <P> que;
    que.push(MP(L, 0));
    while(true)
    {
        P e = que.front();
        que.pop();
        if(e.first == R)
        {
            cout << e.second << endl;
            return;
        }
        for(int i = 0; i < 4; ++i)
        {
            for(int j = 0; j < 10; ++j)
            {
                if((i == 0 && j == 0) || e.first[i] - '0' == j)
                    continue;
                int val = 0;
                for(int k = 0; k < 4; ++k)
                {
                    if(k == i)
                        val = val * 10 + j;
                    else
                       val = val * 10 + e.first[k] - '0';
                }
                string s(e.first);
                s[i]= j + '0';
                if(!prim[val] && !has[val])
                {
                    has[val] = true;
                    que.push(MP(s, e.second + 1)); 
                }

            }
        }
    }
}
int main()
{
    Is_prim();
    int n;
    cin >> n;
    while(n--)
    {
        memset(has, false, sizeof(has));
        cin >> L >> R;
        bfs();
    }
    return 0;
}
