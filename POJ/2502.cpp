#include <iostream>
#include <algorithm>
#include <cmath>
#define maxn 1000
using namespace std;
pair <int, int> arr[maxn];
double const walk = 500.0 / 3, subway = 2000.0 / 3;
double Distance(int x1, int y1, int x2, int y2)
{
    double k = sqrt((y1 - y2) * (y1 - y2) + (x1 - x2) * (x1 - x2));
    return k;
}
int main()
{
    cout << ceil(20.1) << endl;
    int startx, starty, endx, endy;
    int x(0), y;
    while(cin >> x >> y)
    {
        
    }
    return 0;
}
