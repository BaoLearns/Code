/*#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 50007
using namespace std;
bool prim[maxn];
int arr[maxn];
int Is_prim()
{
    int pos = 0;
    for(int i = 2; i * i < maxn; ++i)
    {
        if(!prim[i])
        {
            for(int j = i + i; j < maxn; j += i)
                prim[j] = true;
        }
    }
    for(int i = 2; i < maxn; ++i)
        if(!prim[i]) arr[pos++] = i;
    return pos;
}
int main()
{
    int pos = Is_prim();
    int m, a, b;
    while(~scanf("%d%d%d", &m, &a, &b) && m > 0 && a > 0 && b > 0)
    {
        int P = 2, Q = 2;
        for(int i = 0; i < pos; ++i)
        {
            int p = arr[i], q = m / p;
            if(p > q) break;
            int k = upper_bound(arr, arr + pos, q) - arr;
            for(int j = k - 1; arr[j] >= arr[i]; --j)
            {
                if(1.0 * a / b <= 1.0 * p / arr[j])
                {
                    if(P * Q < p * arr[j])
                    {
                        P = p;
                        Q = arr[j];
                    }
                }
            }
        }
        printf("%d %d\n", P, Q);
    }
    return 0;
}
*/
