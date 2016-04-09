#include <iostream>
#include <cstring>
#define LL long long
#define maxn 1000005
using namespace std;
bool is_prime[maxn];
bool is_prime_small[maxn];
int main()
{
    int a, b;
    while(cin >> a >> b){
    memset(is_prime, true, sizeof(is_prime));
    memset(is_prime_small, true, sizeof(is_prime_small));
    for(LL i = 2; i * i < b; ++i)
    {
        if(is_prime_small[i])
        {
            for(LL j = 2 * i; j < b; j += i) is_prime_small[j] = false;
            for(LL j = max(2LL, (a + i - 1) / i) * i; j < b; j += i) is_prime[j - a] = false;
        }
    }
    LL Max = -1, Min = 1000000005;
    LL L = 0, R = 0;
    LL l1, l2, r1, r2;
    l1 = l2 = r1 = r2 = 0;
    for(int i = 0; i <= b - a; ++i)
    {
        if(is_prime[i])
        {
            //cout << i + a << endl;
            if(L == 0)
                L = i + a;
            else if(R == 0)
                R = i + a;
            else
            {
                L = R;
                R = i + a;
            }
            if(L && R)
            {
                if(R - L > Max)
                {
                    Max = R - L;
                    l1 = L;
                    r1 = R;
                }
                if(R - L < Min)
                {
                    Min = R - L;
                    l2 = L;
                    r2 = R;
                }
            }
        }
    }
    if(l1)
    {
        cout << l2 << "," << r2 << " are closest," << l1 << "," << r1 <<" are most distant." <<endl;
    }
    else
        cout << "There are no adjacent primes." << endl;
    }
    return 0;
}
