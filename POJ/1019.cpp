#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string st;
int MAX(int a, int b)
{
    return a > b? a: b;
}
void f()
{
    cout << "sdgd" << endl;
}
double sqrt(double c)
{
    double err = 1e-15;
    double t = c;
    while(fabs(t - c / t) > err * t)
        t = (c / t + t) / 2.0;
    return t;
}
int main()
{
    cout << sqrt(19.0) << endl;
    int (*p)(int, int);
    p = MAX;
    cout << (*p)(1, 2) << endl;
    void (*p1)(void) = f;
    (*p1)();
    cout << "gsdg" << endl;
    return 0;
}
