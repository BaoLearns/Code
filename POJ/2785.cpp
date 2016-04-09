#include <iostream>
#include <vector>
#include <algorithm>
#define maxn 4005
using namespace std;
long long  arr[maxn][4], sum[maxn * maxn];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < 4; ++j)
            scanf("%d", &arr[i][j]);
    }
    int pos = 0;
    for(int i  = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
            sum[pos++] = arr[i][0] + arr[j][1];
    }
    sort(sum, sum + n * n);
    long long cnt = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            long long temp = -(arr[i][2] + arr[j][3]);
            cnt += upper_bound(sum, sum + n * n, temp) - lower_bound(sum, sum + n * n, temp);
        }
    }
    cout << cnt << endl;
    return 0;
}
/*
6
-45 -41 -36 -36 26 -32
22 -27 53 30 -38 -54
42 56 -37 -75 -10 -6
-16 30 77 -46 62 45
*/
