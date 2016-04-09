#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define what_case(x) cout <<#x << "->" << x
using namespace std;
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
bool row[9][10]; //row[i][j] i行的j是否已用
bool col[9][10]; //col[i][j] i列的j是否已用
bool G[9][10];   //G[i][j] 第i个3 * 3 的j是否已用
int arr[9][9];
typedef struct node
{
    int x, y;
    node(int i, int j)
    {
        x = i;
        y = j;
    }
}node;
vector <node> Node;
bool dfs(int cnt)
{
    //cout << cnt - 1 << endl;
    if(cnt <= 0) return true;
    int x = Node[cnt - 1].x, y = Node[cnt - 1].y;
    //what_case(x) << "  ";
    //what_case(y) << endl;
    for(int i = 1; i < 10; ++i)
    {
        if(row[x][i] || col[y][i] || G[x / 3 * 3 + y / 3][i]) continue;
        //cout << "   --------------" << i << endl;
        row[x][i] = col[y][i] = G[x / 3 * 3 + y / 3][i] = true;
        arr[x][y] = i;
        if(dfs(cnt - 1)) return true;
        row[x][i] = col[y][i] = G[x / 3 * 3 + y / 3][i] = false;    
    }
    return false;
}
int main()
{
    int T;
    cin >> T;
    for(int I = 1; I <= T; ++I)
    {
        Node.clear();
        int temp[9][9];
        for(int i = 0; i < 9; ++i)
        {
            memset(row[i], false, sizeof(row[i]));
            memset(col[i], false, sizeof(col[i]));
            memset(G[i], false, sizeof(G[i]));
        }
        //char ch;
        //while(ch = getchar(), ch == ' ' || ch == '\n' || ch == EOF);
        for(int i = 0; i < 9; ++i)
        {
            getchar();
            for(int j = 0; j < 9; ++j)
            {
                char ch;
                ch = getchar();
                arr[i][j] = ch - '0';
                if(arr[i][j])row[i][arr[i][j]] = col[j][arr[i][j]] = G[i / 3 * 3 + j / 3][arr[i][j]] = true;
                else
                    Node.push_back(node(i, j));
                temp[i][j] = arr[i][j];
            }
        }
        printf("Scenario #%d:\n", I);
        if(dfs(Node.size()))
        {
            for(int i = 0; i < 9; ++i)
            {
                for(int j = 0; j < 9; ++j)
                    cout << arr[i][j];
                cout << endl;
            }
        }
        else
        {
            for(int i = 0; i < 9; ++i)
            {
                for(int j = 0; j < 9; ++j)
                    cout << temp[i][j];
                cout << endl;
            }
        }
        string st;
        getline(cin, st);
        cout << endl;
    }
    return 0;
}
