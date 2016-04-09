#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define debug(x) cout << #x << x << endl;
#define P pari <int, int>
#define ll long long;

int MAXN = 1007;
int INF = 1e9+7;

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n + 7];
        for(int i = 1; i <= n; ++i) cin >> arr[i];
        int q;
        cin >> q;
        while(q--)
        {
            int l, r;
            cin >> l >> r;
            int MAX = -1;
            for(int i = l; i <= r; ++i) MAX = max(MAX, arr[i]);
            cout << MAX << endl;
        }
    }
    return 0;
}
