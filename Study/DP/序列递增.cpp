#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector <int> vec;
    int dp[1007];
    for(int i = 0; i < n; ++i)
    {
        int e;
        cin >> e;
        vec.push_back(e);
    }
    dp[0] = 1;
    for(int i = 1; i < n; ++i)
    {
        dp[i] = 1;
        for(int j = i - 1; j >= 0; --j)
        {
            if(vec[i] > vec[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    for(int i = 0; i < n; ++i)
        cout << dp[i] << " ";
    cout << endl;
    return 0;
}
