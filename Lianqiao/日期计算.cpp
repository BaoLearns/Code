#include <iostream>
using namespace std;
int Month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool Is_rui(int year)
{
    if((year % 4 == 0 && year % 100) || year % 400 == 0)
        return true;
    return false;
}
int main()
{
    int Sum = 0;
    for(int i = 1599; i < 2011; ++i)
    {
        if(Is_rui(i)) Sum += 366;
        else Sum += 365;
    }
    Month[2] = 28;
    for(int i = 1; i < 11; ++i)
        Sum += Month[i];
    Sum += 11;
    Sum = Sum % 7;
    if(Sum <= 5) Sum = 5 - Sum;

    int year, month, day;
    cin >> year >> month >> day;
    int sum = 0;
    for(int i = 1599; i < year; ++i)
    {
        if(Is_rui(i))
            sum += 366;
        else sum += 365;
    }
    if(Is_rui(year)) Month[2] = 29;
    for(int i = 1; i < month; ++i)
        sum += Month[i];
    sum += day;
    cout << (sum + Sum - 1) % 7 + 1 << endl;
    return 0;
}
