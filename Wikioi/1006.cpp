#include <bits/stdc++.h>
#define maxn 105
using namespace std;
map <int, int> Map1, Map2;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int e;
        cin >> e;
        Map1[e]++;
    }
    int ans1 = 0, ans2 = 0;
    for(map <int, int> :: iterator i = Map1.begin(); i != Map1.end(); ++i)
        ans1 = max( i -> second, ans1);
    for(map <int, int> :: iterator i = Map1.begin(); i != Map1.end();)
    {
        for(map <int, int> :: iterator j = ++i; j != Map1.end(); ++j)
            Map2[(j -> first - i -> first)]++;
    }
    for(map <int, int> :: iterator i = Map2.begin(); i != Map2.end(); ++i)
        ans2 = max( (i -> first? i -> second: 0), ans2);
    cout << max(ans1, ans2) << endl;
    for(map <int, int> :: iterator i = Map1.begin(); i != Map1.end(); ++i)
        cout << i -> first << "   " << i -> second << endl;
    cout << "fdsfsd" << endl;
    for(map <int, int> :: iterator i = Map2.begin(); i != Map2.end(); ++i)
        cout << i -> first << "   " << i -> second << endl;
    return 0;
    
}
