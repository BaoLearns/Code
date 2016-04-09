#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;
class Node
{
public:
    int x, y;
    Node(int a, int b):x(a), y(b){}
};
class cmp
{
public:
    bool operator()(Node a, Node b)
    {
        if(a.y != b.y) return b.y < a.y;
        return b.x < a.x;
    }
};
int main()
{
    priority_queue<Node, vector<Node>, cmp> que;
    map <int, int> Map;
    string st;
    while(cin >> st, st[0] != '#')
    {
        int x, y;
        cin >> x >> y;
        que.push(Node(x, y));
        Map[x] = y;
    }
    int k;
    cin >> k;
    while(k--)
    {
        Node e = que.top();
        que.pop();
        cout << e.x << endl;
        que.push(Node(e.x, e.y + Map[e.x]));
    }
    return 0;
}
