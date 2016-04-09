#include <iostream>
#include <set>
#define n 5
using namespace std;
int maze[10][10];
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int cnt = 0;
set <int> Set;
void dfs(int x, int y, int val, int num)
{
    if(num == 6)
    {
        if(Set.find(val) == Set.end())
        {
            cnt++;
            Set.insert(val);
        }
        return;
    }
    for(int i = 0; i < 4; ++i)
    {
        int dx = x + dir[i][0], dy = y + dir[i][1];
        if(dx >= 0 && dx < 5 && dy >= 0 && dy < 5)
            dfs(dx, dy, val * 10 + maze[dx][dy], num + 1);
    }
}
int main()
{
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> maze[i][j];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            dfs(i, j, 0, 0);
    cout << cnt << endl;
    return 0;
}
