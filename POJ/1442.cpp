#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define MAXN 30007
using namespace std;
int arr[MAXN], b[MAXN];
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    for(int i = 0; i < m; ++i)
        scanf("%d", &arr[i]);
    priority_queue <int, vector<int>, greater<int> > que1;
    int pos = 0;
    for(int i = 0; i < n; ++i)
    {
        int v;
        scanf("%d", &v);
        while(que1.size() != v && pos < m)
            que1.push(arr[pos++]);
        priority_queue <int, vector<int>, greater<int> > que2(que1);
        int k = i;
        while(k--)
            que2.pop();
        printf("%d\n", que2.top());
    }
    return 0;
}
