
//ËØÊý»·
#include <iostream>
#define MAXN 50
using namespace std;
bool prim[MAXN];
bool vised[20];
void Is_prim()
{
    prim[0] = prim[1] = true;
    for(int i = 2; i * i < MAXN; ++i)
    {
        if(!prim[i])
        {
            for(int j = 2 * i; j < MAXN; j += i)
                prim[j] = true;
        }
    }
}
void dfs(int n, int num, int arr[])
{
    if(num == n)
    {
        if(!prim[arr[0] + arr[n - 1]])
        {
            for(int i = 0; i < n; ++i) cout << arr[i] << " ";
            cout << endl;
        }
        return;
    }
    for(int i = 2; i <= n; ++i)
    {
        /*if(num == 0)
        {
            if(!vised[i] && !prim[i])
            {
                vised[i] = true;
                arr[num] = i;
                dfs(n, num + 1, arr);
                vised[i] = false;
            }
        }*/
        if(!vised[i] && !prim[i + arr[num - 1]])
        {
            vised[i] = true;
            arr[num] = i;
            dfs(n, num + 1, arr);
            vised[i] = false;
        }
    }
}
int main()
{
    Is_prim();
    int n, arr[MAXN] = {1};
    cin >> n;
    dfs(n, 1, arr);
    return 0;
}
