
#include <bits/stdc++.h>
using namespace std;
int main()
{
    set <int > Set;
    int num = 1 << 30;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int e;
        cin >> e;
        num |= 1 << e;
    }
    for(int x = num; x; x = (x - 1) & num)
    {
        int val = 0;
        for(int i = 0; i < 30; ++i)
        {
            if(x >> i & 1)
            {
                val = val * 10 + i;
            }
        }
        if(val)
            Set.insert(val);
    }
    for(auto i : Set)
        cout << i << endl;
    return 0;
}
