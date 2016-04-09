#include <iostream>
#include <cstdio>
#include <cmath>
#define PI 3.1415927
using namespace std;
int main()
{
    double vs, r, c;
    int  n;
    cin >> vs >> r >> c >> n;
    while(n--)
    {
        double w;
        cin >> w;
        printf("%.3lf\n", c * r * w * vs / sqrt(1 + c * r * w * c * r * w));
    }
    return 0;
}
