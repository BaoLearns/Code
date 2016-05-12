def find(b, v = 4):
    for i in xrange(1, 5):
        if b[i] == v:
            return [i, v]
stage = [[0] * 6 for i in xrange(6)]

stage[1] = [-1, 2, 2, 3, 4]
stage[2] = [-1, 'find4', 'pos1', 1, 'pos1']
stage[3] = [-1, 'lab2', 'lab1', 3, 'find4']
stage[4] = [-1, 'pos1', 1, 'pos2', 'pos2']
stage[5] = [-1, 'lab1', 'lab2', 'lab4', 'lab3']

t = int(raw_input())

while True:
    t -= 1
    if t < 0:
        break
    p, v = [0], [0]
    for i in xrange(1, 6):
        d = map(int, raw_input().split())
        s = stage[i][d[0]]
        if isinstance(s, int):
            ans = [s, d[s]]
        elif s == 'find4':
            ans = find(d, 4)    
        elif s[:3] == 'lab':
            n = int(s[3:4])
            ans = find(d, v[n])
        else:
            n = int(s[3:4])
            ans = [p[n], d[p[n]]]
        p.append(ans[0])
        v.append(ans[1])
        print ans[0], ans[1]


                
            
