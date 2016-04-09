import string
st = str(raw_input())
ans = 0
if st[len(st) - 1] == 'k':
    w = 5
    val = int(st[0])
    for i in range(1, 367, 1):
        if w == val:
            ans += 1
        w = w % 7 + 1
else:
    val = int(st[0])
    if st[1] in string.digits:
        val = val * 10 + int(st[1])
    if val <= 29:
        ans = 12
    elif val == 30:
        ans = 11
    else:
        ans = 7
print ans


