//优先队列实现 priority_queue
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair <int ,int > P;
int main()
{
    priority_queue <P> que;
    int n, arr[3005];
    cin>>n;
    for(int i = 0; i < n; ++i)
    {
        P e;
        cin>>arr[i];
        e.first = -arr[i];
        e.second = i;
        que.push(e);
    }
    for(int i = 0; i < n; ++i)
    {
        P e;
        e = que.top();
        que.pop();
        cout<<-e.first<<' '<<e.second<<endl;
    }
        /*
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        P e = que.top();
        que.pop();
        if(e.second != i)
        {
            ans++;
            P q;
            q.first = arr[i];
            q.second = i;
            swap(e, q);
        }
    }
    cout<<ans<<endl;*/
    return 0;
}
