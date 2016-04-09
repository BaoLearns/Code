#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    double n, p;
    while(cin >> n >> p)
    {
        int l = 1, r = 1e9 * 2;
        while(true)
        {
            int m = l + (r - l) / 2;
            double ans = pow(double(m), n);
            if(ans == p)
            {
                cout << m << endl;
                break;
            }
            else if(ans > p)
                r = m;
            else
                l = m;
        }
     }
    return 0;
}
