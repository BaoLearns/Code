#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a, b, c;
    while(cin >> a >> b >> c)
    {
        int d = a * b / __gcd(a, b);
        int e = d * c / __gcd(d, c);
        cout << e << endl;
    }
    return 0;
}
