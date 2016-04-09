#include <cstdio>
#include <iostream>
#include <algorithm>
#define LL long long
#define MAXN 100001
using namespace std;
int arr[MAXN];
int main()
{
    int n, q;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    std::sort(arr, arr + n);
    scanf("%d", &q);
    while(q--)
    {
        int k;
        scanf("%d", &k);
        LL n1 = lower_bound(arr, arr + n, k) - arr + 1;
        //cout << n1 << endl;
        printf("%I64d\n", (n1 + n) * (n - n1 + 1) / 2);
    }
    return 0;
}
