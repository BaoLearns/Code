T = int(raw_input())
while True:
    T -= 1
    if T < 0:
        break
    a, b, c, d = map(int, raw_input().split())
    print c, b + d
    print a, b + d
