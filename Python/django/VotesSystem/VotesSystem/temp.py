from datetime import date

start = date(year=1753, month=1, day=1)
end = date(year=9999,month=12,day=31)

month = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

ans = []
t = 0
while start <= end:
    if date.weekday(start) == 0 and (start.day == 1 or start.day == 11 or start.day == 21):
        v = int(start.day) + int(start.month) * 100 + int(start.year) * 10000
        print v
        if start.month == 1 and start.day == 1:
            print '-' * 50
            s = raw_input()
        #with open('/home/royecode/Code/ZOJ/Contest146/D.cpp', 'a') as fp:

        #    fp.write("%d," %v)
    try:
        start = date(start.year, start.month, start.day + 1)
    except ValueError:
        try:
            start = date(start.year, start.month + 1, 1)
        except ValueError:
            start = date(start.year + 1, 1, 1)