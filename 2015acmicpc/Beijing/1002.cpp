//Author:Royecode
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#define pb push_back
#define mk make_pair
#define ll long long 
#define debug(x) cout << #x << " " << x << endl;
using namespace std;

const int MAXN = 1e5+7;
const int INF = 2e9+7;
const double EPS = 1e-9;

void update(string &st, bool f)
{
    if(f)
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string st;
        cin >> n >> st;
        int len = st.length(), p = 0;
        string ans;
        bool f = false;
        for(int i = 0; i < len; ++i)
        {
            if(st[i] == 'L') p--;
            else if(st[i] == 'R') p++;
            else if(st[i] == 'S') f = true;
            else if(st[i] == 'D') 
            {
                //if(!f) ans = ans.substr(0, p + 1) + ans.substr(p + 2);
                //p--;
            }
            else if(st[i] == 'B')
            {
                ans = ans.substr(0, p) + ans.substr(p + 1);
                p--;
            }
            p = max(0, p);
            p = min(p, ans.length());
        }
    }
    
    return 0;
}
