#include <iostream>
#include <cstdio>
#include <queue>
#define p pair <int, int>
#define maxn 20007
using namespace std;
p arr[maxn];
int main()
{
    freopen("2431.txt", "r", stdin);
    int n, L, P;
    while(~scanf("%d", &n)){
    for(int i = 0; i < n; ++i)
        scanf("%d%d", &arr[i].first, &arr[i].second);
    scanf("%d%d", &L, &P);
    priority_queue <int> que;
    int pos = 1, gas = P, cnt = 0;
    n++;
    for(int i = 0; i < n; ++i)
    {
        int d = arr[i].first - pos;
        while(gas - d <= 0)
        {
            if(que.empty())
            {
                puts("-1");
                //return 0;
            }
            gas += que.top();
            que.pop();
            cnt++;
        }
        que.push(arr[i].second);
        pos = arr[i].first;
        gas -= d;
        printf("%d %d %d\n", pos, gas, cnt);
    }
    printf("%d\n", cnt);
    }
    return 0;
}
