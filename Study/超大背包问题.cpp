#include <bits/stdc++.h>
#define LL long long
#define INF 10000000000000005
using namespace std;
int main()
{
    int n, W;
    cin >> n >> W;
    vector <pair<LL, LL> > vec, L, R;
    for(int i = 0; i < n; ++i)
    {
        LL wi, vi;
        cin >> wi >> vi;
        vec.push_back(make_pair(wi, vi));
    }
    //枚举前一半
    int K = n / 2;
    for(int i = 0; i < (1 << K); ++i)
    {
        LL Wsum = 0, Vsum = 0;
        for(int j = 0; j < K; ++j)
        {
            if(i >> j & 1)
            {
                Wsum += vec[j].first;
                Vsum += vec[j].second;
            }
        }
        L.push_back(make_pair(Wsum, Vsum));
    }
    sort(L.begin(), L.end());
    LL ans = 0;
    //枚举后一半
    for(int i = 0; i < (1 << (n - K)); ++i)
    {
        LL Wsum = 0, Vsum = 0;
        for(int j = 0; j < (n - K); ++j)
        {
            if(i >> j & 1)
            {
                Wsum += vec[j + K].first;
                Vsum += vec[j + K].second;
            }
        }
        if(W - Wsum >= 0)
        {
            LL s = (lower_bound(L.begin(), L.end(), make_pair(W - Wsum, INF)) - 1) -> second;
            ans = max(ans, s + Vsum);
        }
    }
    cout << ans << endl;
    return 0;
}
/*
test:
4 5
2 3
1 2
3 4
2 2
ans:
7
*/
