Map = {}
for i in range(0, 101, 1):
    Map[i] = 0
for i in range(2, 101, 1):
    if Map[i] == 0:
        for j in range(i * 2, 101, i):
            Map[j] = 1
for i in range(2, 101, 1):
    if Map[i] == 0:
        print i,
