#include <iostream>    
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#define MAXN 10
using namespace std;
int arr[MAXN];
vector <int> G[400000];
int Num[10][10];
void Init()
{
    Num[1][3] = Num[3][1] = 2;
    Num[4][6] = Num[6][4] = 5;
    Num[7][9] = Num[9][7] = 8;
    Num[1][7] = Num[7][1] = 4;
    Num[2][8] = Num[8][2] = 5;
    Num[3][9] = Num[9][3] = 6;
    Num[1][9] = Num[9][1] = 5;
    Num[3][7] = Num[7][3] = 5;
}
int main()
{
    Init();
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) 
            cin >> arr[i];
        sort(arr, arr + n);
        for (int i = 0; i < 400000; ++i) G[i].clear();
        bool used[10], side[10];
        int num = 0;
        memset(used, true, sizeof used);
        memset(side, true, sizeof side);
        for (int i = 0; i < n; ++i) side[arr[i]] = false;
        do
        {
            for (int i = 0; i < n; ++i) used[arr[i]] = false;
            bool flag = false;
            for(int i = 0; i < n - 1; ++i)
            {
                int temp = (arr[i] + arr[i + 1]) / 2;
                if(Num[arr[i]][arr[i + 1]] && (!used[temp] || side[temp]))
                {
                    flag = true;
                    break;
                } 
                used[arr[i]] = true, used[arr[i  + 1]] = true;
            }
            if(!flag)
            {
                for(int i = 0; i < n; ++i)
                    G[num].push_back(arr[i]);
                num++;
            }
        
        }while(next_permutation(arr, arr + n));
        cout << num << endl;
        for(int i = 0; i < num; ++i)
        {
            for(int j = 0; j < n; ++j)
                printf("%d%c", G[i][j], j < n - 1? ' ': '\n');
        }
    }
}
