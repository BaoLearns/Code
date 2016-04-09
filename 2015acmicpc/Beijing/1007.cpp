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

int arr[10];

int solve()
{
    
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        solve();
    }
    
    return 0;
}
