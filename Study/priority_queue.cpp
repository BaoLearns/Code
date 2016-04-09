/*#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int val;
    Node(){}
    Node(int Nval){val = Nval;}
    bool operator < (const Node a)
    {
        return a.val > val;
    }
};
int main()
{
    priority_queue <Node> que;
    que.push(1);
    que.push(-1);
    que.push(4);
    while(!que.empty())
    {
        cout << que.top().val << endl;
        que.pop();
    }
    return 0;
}*/
//²¢²é¼¯
/*
#include <iostream>
#define maxn 105
using namespace std;
int fa[maxn];
void Init(int n)
{
    for(int i = 1; i <= n; ++i)
        fa[i] = i;
}
int find(int x)
{
    return fa[x] = fa[x] == x? x: find(fa[x]);
}
void Union(int x, int y)
{
    int fx = find(x), fy = find(y);
    fa[fx] = fy;
}
int main()
{
    Init(100);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }
    int m;
    cin >> m;
    for(int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        int faa = find(a), fab = find(b);
        cout << (faa == fab? "YES": "NO") << endl;
    }
}
*/
#include <iostream>
#include <vector>
#define maxn 1005
using namespace std;
vector <int> G[maxn];
int Color[maxn];
bool solve(int num, int color)
{
    for(int i = num; i < maxn; ++i)
    {
        if(G[i].size())
        {
            if(Color[i] == -color) return false;
                Color[i] = color;  
            for(int j = 0; j < G[i].size(); ++j)
            {
                Color[G[i][j]] = -color;
                solve(G[i][j], -color);
            }
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    cout << (solve(0, 1)? "YES": "NO") << endl;
    return 0;
}
