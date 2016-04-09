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
string str[3] = {"f", "ff", "cff"};

void solve(string &st, int len)
{
    for(int i = 0; i < len; ++i)
    {
        if(st[i] == 'c')
        {
            st = st.substr(i);
            return;
        }
    }

}

int main()
{
    //freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--)
    {
        string st;
        cin >> st;
        int len = st.length();
        int cnt = 0;
        bool f = true;
        if(st[0] == st[len - 1] && st[0] == 'f') solve(st);
        len = st.length();
        if(st == str[0] || st == str[1])
        {
            puts("1");
            continue;
        }
        for(int i = 0; i < len; ++i)
        {
            if(st[i] == 'c')
            {
                int j = i + 1;
                while(st[j] )
            }
        }
        cout << (f? cnt: -1) << endl;
    }
    return 0;
}
