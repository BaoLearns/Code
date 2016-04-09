#include <iostream>
using namespace std;
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int Is_(int year)
{
    if((year % 4 == 0 && year / 100) || year % 400 == 0)
        return 366;
    return 365;
}
int main()
{
    int days = 8113;
    int sum = 1;
    for(int i = 5; i < 13; ++i) sum += month[i];
    days -= sum;
    int year = 1778;
    while(days >= 365)
    {
        days -= Is_(year);
        year++;
    }
    if(Is_(year) == 366) month[2] = 29;
    for(int i = 1; i < 13; ++i)
    {
        if(days > month[i])
            days -= month[i];
        else
        {
            cout << year << "-" << i << "-" << days << endl;
            break;
        }
    }
    return 0;
}
