def Is_leap_year(year):
    if(year % 4 == 0 and year % 100 != 0 or year % 400 == 0):
        return True
    else:
        return False
def Get_num_of_days_in_month(year, month):
    if month in(1, 3, 5, 7, 8, 10, 12):
        return 31
    elif month in(4, 6, 9, 11):
        return 30
    elif Is_leap_year(year):
        return 29
    else:
        return 28
def Get_total_num_of_days(year, month):
    days = 0
    for i in range (1800, year):
        if(Is_leap_year(i)):
            days += 366
        else:
            days += 365
    for m in range (1, month):
        days += Get_num_of_days_in_month(year, m)
    return days
def Get_start_day(year, day):
    return (3 + Get_total_num_of_days(year, month)) % 7
while True:
    year = int(input())
    month = int(input())
    print (Get_start_day(year, month))
