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
#define P pair <double, double>
using namespace std;

const int MAXN = 1e5+7;
const int INF = 2e9+7;
const double EPS = 1e-9;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int m, n;
        cin >> m >> n;
        P arr[107];
        for(int i = 0; i < m; ++i)
            cin >> arr[i].first >> arr[i].second;
        int ans = INF;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 1; j <= 2007; ++j)
            {
                int cnt1 = 0, cnt2 = 0;
                for(int k = 0; k < m; ++k)
                {
                    double v = (arr[i].first - arr[k].first) * (arr[i].first - arr[k].first) + (arr[i].second - arr[k].second) * (arr[i].second - arr[k].second);
                    if(double(j * j) > v) cnt1++;
                    if(double(j * j) >= v) cnt2++;
                }
                if(cnt1 == n && cnt2 == cnt1) 
                {
                    ans = min(ans, j);
                    break;
                }
            }
        }
        cout << (ans == INF? -1: ans) << endl;
    }
    return 0;
}
