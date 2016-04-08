def Init():
    for i in xrange(1007):
        maze.append([])
        for j in xrange(1007):
            maze[i].append(False)
def Input():
    n = int(raw_input())
    for i in xrange(n):
        x, y = map(int, raw_input().split())
        maze[x][y] = True
def Solve():
    ans = 0
    for i in xrange(1, 1001):
        r1, c1, r2, c2 = i + 1, i - 1, i - 1, i + 1
        count = int(maze[i][i])
        while r1 < 1001 and c1 > 0:
            if maze[r1][c1]:
                count += 1
            r1 += 1
            c1 -= 1
        while r2 > 0 and c2 < 1001:
            if maze[r2][c2]:
                count += 1
            r2 -= 1
            c2 += 1
        ans += count * (count - 1) / 2
    for i in xrange(1, 1001):
        r1, c1, r2, c2 = i - 1, 1001 - i - 1, i + 1, 1001 - i + 1
        count = int(maze[i][1001 - i])
        while r1 > 0 and c1 > 0:
            if maze[r1][c1]:
                count += 1
            r1 -= 1
            c1 -= 1
        while r2 < 1001 and c2 < 1001:
            if maze[r2][c2]:
                count += 1
            r2 += 1
            c2 += 1
        ans += count * (count - 1) * 2
    print ans
maze = []
Init()
Input()
Solve()
