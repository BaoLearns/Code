#include <iostream>
using namespace std;
bool Isleap(int year)
{
    if((year % 4 == 0 && year % 100) || year % 400 == 0)
        return true;
    return false;
}
int main()
{
    //推算出1928年5月1日是星期2
    int T;
    cin >> T;
    while(T--)
    {
        int year, sum = 0;
        cin >> year;
        for(int i = 1928; i < year; ++i)
            sum += Isleap(i + 1)? 366: 365;
        int m = (sum % 7 + 2) % 7;
        int ans;
        if(m == 1) ans = 9;
        else if(m == 2 || m == 0) ans = 6;
        else ans = 5;
        cout << ans << endl;  
    }
    return 0;
}
