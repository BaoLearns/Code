/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define maxn 1000005
int hash[maxn];
using namespace std;
int main()
{
    
    int n;
    while(cin >> n){
bool flag = true;
memset(hash, 0, sizeof(hash));
    for(int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        hash[a] = b;
    }
    int S, Y;
    cin >> S >> Y;
    int ans = 0;
    int L = 0, R = Y + 1;
    priority_queue<int > que;
    while(R < S && flag)
    {
        //cout << "dsfdsgdsgds" << L << ' ' << R << endl;
        for(int i = L + 1; i <= R; ++i)
            if(hash[i])
                que.push(hash[i]);
        if(que.empty())
        {
flag = false;
break;
        }
        //cout << "dsg " << que.top() << endl;
        L = R;
        R += que.top();
        que.pop();
        ans++; 
    }
    cout << (flag? ans: -1) << endl;
}
    return 0;
}

1
1 2
10 9


3
2 3
5 5
9 100
10 1
*/

#include <iostream>
#include <algorithm>
#include <queue>
#define maxn 1000005
using namespace std;
pair<int , int> arr[maxn];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i].first >> arr[i].second;
    int L, P;
    cin >> L >> P;
    arr[n].first = L;
    arr[n].second = 0;
    n++;
    sort(arr, arr + n);
    for(int i = 0; i < n; ++i)
        cout << arr[i].first << "dfsds" << arr[i].second << endl;
    priority_queue <int> que;
    int pos = 0, tank = P;
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        int d = arr[i].first - pos;
        while(tank - d < 0)
        {
            if(que.empty())
            {
                cout << -1 << endl;
                return 0;
            }
            
            cout << "dsfdsfsfdfdsfsdfdddddd" << i << ' ' << que.top() << endl;
            tank += que.top();
            que.pop();
            ans++; 
        }
        tank -= d;
        que.push(arr[i].second);
        pos = arr[i].first;
    }
    cout << ans << endl;
    return 0;
}
