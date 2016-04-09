#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
vector <int > v;
int arr[1010];
int dp[1010];
int main()
{
    v.push_back(5);
    printf("%d\n",v.front());

    //freopen("sequence.in","r",stdin);
    //freopen("sequence.out","w",stdout);
    int n;
    while(~scanf("%d",&n))
    {
        for( int i = 0; i < n; ++i)
            scanf("%d", arr + i);
        int val=1;
        for( int i = 0; i < n; ++i)
        {
            dp[i]=1;
            for( int j = 0; j < i; ++j)
            {
                if(arr[j] < arr[i])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
                val=max(val,dp[i]);
            }
        }
        printf("%d\n",val);
    }
    return 0;
}
