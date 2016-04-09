#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
    int n,m;
    int arr[20];
    while(~scanf("%d%d", &n, &m))
    {
        for( int i = 0; i < n; ++i)
            scanf("%d", arr + i);
        sort( arr, arr + n - 1);
        int ans = 1;
        int v=0;
        for( int i = 0; i < n; ++i)
        {
            //v+=arr[i];
            if(v + arr[i] > m)
            {
                v=arr[i];
                ++ans;
            }
            else
                v+=arr[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
