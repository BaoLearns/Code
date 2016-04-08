n = raw_input()
l = map(int, raw_input().split())
odd_number, odd_min = 0, 1e9 + 7
s = sum(l)
for i in l:
    if (i & 1) == 1:
        odd_number += 1
        odd_min = min(odd_min, i)
if (odd_number & 1) == 1:
    s -= odd_min
print s
