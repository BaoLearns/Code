#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#define P pair <int, string>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int ans = 0;
        string ST;
        int s, m, d;
        cin >> s >> m >> d;
        P arr[101];
        for(int i = 0; i < s; ++i)
        {
            string st;
            int n;
            cin >> st >> n;
            arr[i] = P(n, st);
        }
        sort(arr, arr + s);
        ans += arr[s / 2].first;
        ST += arr[s / 2].second;
        
        for(int i = 0; i < m; ++i)
        {
            string st;
            int n;
            cin >> st >> n;
            arr[i] = P(n, st);
        }
        sort(arr, arr + m);
        ans += arr[m / 2].first;
        ST += ' ';
        ST += arr[m / 2].second;
        
        for(int i = 0; i < d; ++i)
        {
            string st;
            int n;
            cin >> st >> n;
            arr[i] = P(n, st);
        }
        sort(arr, arr + d);
        ans += arr[d / 2].first;
        ST += ' ';
        ST += arr[d / 2].second;
        cout << ans << " " << ST << endl;
    }
    return 0;
}
