#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <stack>
#define N 3
#define M 3
using namespace std;
const char *step[4] = { "upper", "rigth", "lower", "left"};
int maze[5][5];
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
void dfs(int x, int y, vector <int> vec)
{
    if(x == N - 1 && y == M - 1)
    {
        for(vector <int> :: iterator it = vec.begin(); it != vec.end(); ++it)
            cout << step[*it] << endl;
    }
    for(int i = 0; i < 4; ++i)
    {
        int dx = dir[i][0] + x, dy = dir[i][1] + y;
        if(dx >= 0 && dx < N && dy >= 0 && dy < M && maze[dx][dy] == 1)
        {
            vec[vec.size()] = i;
            dfs(dx, dy, vec);
        }
    }
}
int main()
{
    srand(time(0));
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
        {
            maze[i][j] = rand() % 2;
            cout << maze[i][j] << " " << "\n"[j != M - 1];
        }
    vector <int > vec;
    dfs(0, 0, vec.begin());
    return 0;
}
