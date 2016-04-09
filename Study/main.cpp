#include <iostream>
#define ll long long
using namespace std;
ll quick(int x, int i)
{
    if(i > 1)
    {
        ll t = quick(x, i / 2);
        if(i & 1) return t * t * x;
        return t * t;
    }
    return x;
}
int main()
{
    int c, k1, b1, k2, Case = 1;
    while(cin >> c >> k1 >> b1 >> k2)
    {
        for(int a = 1; a <= c; ++a)
        {
            for(int n = 1; ; ++n)
            {
                int t = quick(a, k1 * n + b1);
                int s = C;
                while(s <= t) s += C;
            }
        }
    }
    return 0;
}
