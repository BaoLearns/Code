#include <iostream>
#include <queue>
#include <vector>
#define MAXN 3410
#define P pair<double, int> 
using namespace std;
int w[MAXN], v[MAXN];
int main()
{
    priority_queue<P> que;
    int n, W;
    cin >> n >> W;
    for(int i = 0; i < n; ++i)
    {
        cin >> w[i] >> v[i];
        que.push(P(v[i] * 1.0 / w[i], i)); 
    }
    int ans = 0;
    while(n >= 0 && w > 0)
    {
        if(W - w[que.top().second] >= 0)
        {
            ans += v[que.top().second];
            W -= w[que.top().second];
        }
        n--;
        que.pop();
    }
    cout << ans << endl;
    return 0;
}
