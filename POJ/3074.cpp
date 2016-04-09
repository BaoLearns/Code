#include <iostream>
#include <cstring>
#include <algorithm>
#include <iterator>
#define P pair <int, int>
using namespace std;
int arr[9][9];
bool row[9][10], col[9][10], G[9][10];
P point[81];
bool dfs(int cnt)
{
    if(cnt <= 0) return true;
    int x = point[cnt - 1].first, y = point[cnt - 1].second;
    if(x == -1) return true;
    int num = 0;
    for(int i = 1; i < 10; ++i)
    {
        if(row[x][i] || col[y][i] || G[x / 3 * 3 + y / 3][i]) continue;
        num++;
    }
    if(num == 0) return false;
    for(int i = 1; i < 10; ++i)
    {
        if(row[x][i] || col[y][i] || G[x / 3 * 3 + y / 3][i]) continue;
        row[x][i] = col[y][i] = G[x / 3 * 3 + y / 3][i] = true;
        arr[x][y] = i;
        if(num == 1) point[cnt - 1].first = point[cnt - 1].second = -1;
        if(dfs(cnt - 1)) return true;
        if(num == 1) point[cnt - 1].first =  x, point[cnt].second = y;
        row[x][i] = col[y][i] = G[x / 3 * 3 + y / 3][i] = false;
    }
    return false;
}
bool cmp(P a, P b)
{
    int num[6];
    memset(num, 0, sizeof(num));
    for(int i = 1; i < 10; ++i)
    {
        num[0] += row[a.first][i]? 1: 0;
        num[1] += col[a.second][i]? 1: 0;
        num[2] += G[a.first / 3 * 3 + a.second / 3][i]? 1: 0;
        num[3] += row[b.first][i]? 1: 0;
        num[4] += col[b.second][i]? 1: 0;
        num[5] += G[b.first / 3 * 3 + b.second / 3][i]? 1: 0;
    }
    if(num[0] != num[3]) return num[0] < num[3];
    else if(num[1] != num[4]) return num[1] < num[4];
    else return num[2] < num[5];
}
int main()
{
    string st;
    while(cin >> st, st != "end")
    {
        int cnt = 0;
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(G, false, sizeof(G));
        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
            {
                if(st[i * 9 + j] != '.')
                {
                    arr[i][j] = st[i * 9 + j] - '0';
                    int k = arr[i][j];
                    row[i][k] = col[j][k] = G[i / 3 * 3 + j / 3][k] = true; 
                }
                else
                {
                    arr[i][j] = 0;
                    //point[cnt++] = P(i, j);
                }
            }
        }
        for(int i = 0; i < 9; ++i)
        {
            int num1 = 0, pos1, num2 = 0, pos2;
            for(int j = 0; j < 9; ++j)
            {
                if(!arr[i][j])
                {
                    pos1 = j;
                    num1++;
                }
                if(!arr[j][i])
                {
                    pos2 = j;
                    num2++;
                }
            }
            if(num1 == 1)
            {
                for(int j = 0; j < 10; ++j)
                {
                    if(!row[i][j])
                    {
                        row[i][j] = true;
                        arr[i][pos1] = j;
                    }
                }
            }
            if(num2 == 1)
            {
                for(int j = 0; j < 10; ++j)
                {
                    if(!col[i][j])
                    {
                        col[i][j] = true;
                        arr[i][pos2] = j;
                    }
                }
            }
        }
        //for()
        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
                if(arr[i][j] == 0) point[cnt++] = P(i, j);
        }
        /*for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
                cout << arr[i][j];
            cout << endl;
        }*/
        //for(int i = 0; i < cnt; ++i)
          //  cout << point[i].first << "    " << point[i].second << endl;
        sort(point, point + cnt, cmp);
        //cout << endl << endl ;
        //for(int i = 0; i < cnt; ++i)
          //  cout << point[i].first << "    " << point[i].second << endl;
        dfs(cnt);
        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
                cout << arr[i][j];
        }
        cout << endl;
    }
    return 0;
}
