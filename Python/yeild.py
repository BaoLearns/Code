def fab(max):
    a, b, n = 0, 1, 0
    if(max < 0):
        return None
    if(max == 1 or max == 2):
        return 1
    while(n < max):
        a, b = b, a + b
        print a
        n += 1
fab(10)

