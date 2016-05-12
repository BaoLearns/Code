T = int(raw_input())
while True:
    T -= 1
    if T < 0:
        break
    n = int(raw_input())
    print n + sum(map(int, raw_input().split()))
