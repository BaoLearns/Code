#include <bits/stdc++.h>
using namespace std;

bool Is_Leap(int year)
{
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    return false;
}

int Get_in_day_month(int year, int month)
{
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||month == 10 || month == 12)
        return 31;
    if(month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    if(Is_Leap(year))
        return 29;
    return 28;
}

int Get_in_day_year(int year, int month)
{
    int days = 0;
    for(int i = 1800; i < year; ++i) {
        if(Is_Leap(i))
            days += 366;
        else
            days += 365;
    }
    for(int m = 1; m < month; ++m)
        days += Get_in_day_month(year, m);
    return days;
}

int Get_in_day_start(int year, int month)
{
    int start = (3 + Get_in_day_year(year, month)) % 7;
    return start;
}

int main()
{
    int year, month;
    string st = "Sun Mon Tue Wed Thu Fri Sat";
    while(cin >> year >> month)
    {
        if(year < 1800 || month < 0 || month > 12)
        {
            cout << "ERORR" << endl;
            continue;
        }
        cout << endl << year << " Year," << month << " Month" << endl << endl;
        int start = Get_in_day_start(year, month) + 1;
        int days = Get_in_day_month(year, month);
        int blank = start - 1;
        cout << st << " ";
        int M = Get_in_day_month(year, (month == 1? 12:month - 1));
        cout << endl;
        while(blank--)
            printf("%2d  ", M - blank);
        for(int i = 1; i <= days; ++i)
        {
            printf("%2d  ", i);
            if(start++ % 7 == 0)
                cout << endl;
        }
        int cnt = 1;
        start--;
        while(start % 7 > 0)
        {
            start++;
            printf("%2d  ", cnt++);
        }
        cout << endl << endl;

    }
    return 0;
}
