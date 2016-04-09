#include <bits/stdc++.h>
#define LL long long 
using namespace std;
LL Quickmi(LL x, LL n, LL Mod)
{
    LL res = 1;
    while(n)
    {
        if(n & 1)
        {
            res *= x;
            res %= Mod;
        }
        x *= x;
        x %= Mod;
        n >>= 1;
    }
    return res % Mod;
}
int main()
{
    LL x, n, Mod;
    while(cin >> x >> n >> Mod)
    {
        cout << Quickmi(x, n, Mod) << endl;
    }
    return 0;
}

