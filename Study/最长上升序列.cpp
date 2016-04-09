/*#include <iostream>
#include <algorithm>
#define maxn 1000
using namespace std;
int arr[maxn];
int dp[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; ++i)
        cin>>arr[i];
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        dp[i] = 1;
        for(int j = 0; j < i; ++j)
        {
            if(arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);

    }
    cout<<ans<<endl;
    return 0;
}
*/



