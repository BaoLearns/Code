#include <iostream>
#include <cstring>
using namespace std;
int hash[105];
int main()
{
    memset(hash, 0, sizeof(0));
    int n, start;
    cin >> n;
    cin >> start;
    for(int i = 1; i < n; ++i)
    {
        int e;
        cin >> e;
        if(e > 0)
            hash[e] = 1;
        else
            hash[-e] = -1;
    }
    int ans = 1;
    if(start < 0)
    {
        start = -start;
        for(int i = 1; i < start; ++i)
        {
            if(hash[i] > 0)
                ans++;
        }
        if(ans != 1)
        {
            for(int i = start + 1; i < 101; ++i)
                if(hash[i] < 0)
                    ans++;
        }
    }
    else
    {
        for(int i = start + 1; i < 101; ++i)
        {
            if(hash[i] < 0)
                ans++;
        }
        if(ans != 1)
        {
            for(int i = start - 1; i > 0; --i)
                if(hash[i] > 0)
                    ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
