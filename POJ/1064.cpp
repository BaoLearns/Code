#include <iostream>
#include <vector>
#include <cmath>
#define MAX_SIZE 1000000000.0
using namespace std;
vector <double> vec;
bool solve(double x, int k)
{
    int num = 0;
    for(vector <double> :: iterator it = vec.begin(); it != vec.end(); it++)
        num += (int)(*it / x);
    return num >= k;
}
int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
    {
        double e;
        cin >> e;
        vec.push_back(e);
    }
    double L = 0, R = MAX_SIZE;
    //cout << R << endl;
    while(R - L > 0.0001)
    {
        double mid = L + (R - L) / 2;
        if(solve(mid, k))
            L = mid;
        else
            R = mid;
    }
    printf("%.2lf\n", floor(R * 100) / 100);
    return 0;
}
/*
4 11
1.2
1.5
1.1
1.5
*/
