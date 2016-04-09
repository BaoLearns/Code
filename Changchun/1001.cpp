#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#define debug(x) cout << #x << " " << x << endl;
#define P pari <int, int>
#define ll long long

const int MAXN = 150007;
const int INF = 1e9+7;

using namespace std;

class node
{
public:
    char *name;
    int id, val;
    node(char* _name, int _id, int _val)
    {
        name = new char;
        strcpy(name, _name);
        id = _id;
        val = _val;
    }
    bool operator <(const node &a) const
    {
        if(val != a.val) return val < a.val;
        return id > a.id;
    }
};

char name[MAXN][201];
int val[MAXN], num1[MAXN], num2[MAXN];
vector <char *> ans;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ans.clear();
        int k, m, q;
        cin >> k >> m >> q;
        for(int i = 1; i <= k; ++i) scanf("%s%d", name[i], &val[i]);
        for(int i = 1; i <= m; ++i) scanf("%d%d", &num1[i], &num2[i]);
        int num[q + 1];
        for(int i = 1; i <= q; ++i) scanf("%d", &num[i]); 
        int p = 1;
        priority_queue <node> que;
        for(int i = 1; i <= k; ++i)
        {
            que.push(node(name[i], i, val[i]));
            //debug(que.top().name);
            if(p <= m && i == num1[p])
            {
                while(que.size() && num2[p] > 0)
                {
                    num2[p]--;
                    ans.push_back(que.top().name);
                    que.pop();
                }
                p++;
            }
        }
        while(que.size()) 
        {
            ans.push_back(que.top().name);
            que.pop();
        }
        for(int i = 1; i <= q; ++i) printf("%s%c", ans[num[i] - 1], i == q? '\n': ' ');
    }
    return 0;
}
