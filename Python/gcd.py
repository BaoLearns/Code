def gcd(a, b):
    if b <= 0:
        return a
    return gcd(b, a % b)
def GCD(a, b):
    while b > 0:
        a, b = b, a % b
    return a
while True:
    a = int(raw_input())
    b = int(raw_input())
    print gcd(a, b), GCD(a, b)
