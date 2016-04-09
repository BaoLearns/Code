/*
 * 一个三角形，选择一条路径让这条路径包括的点和最大
 *            1
 *          2    3
 *       4     5    6
 *    7
 *和就是14
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 1007
using namespace std;
int G[MAXN][MAXN]; //存储三角
int Sum[MAXN][MAXN]; //三角形的和
int main()
{
    int n, l = 0, times = 0;
    cin >> n;
    for(int i = 0; times < n; ++i) //存储的时候是从左往右，从上到下存储，第一行存一个，第n行存n个
    {
        for(int j = 0; j <= i && times < n; ++j)
        {
            cin >> G[i][j];
            Sum[i][j] = G[i][j];
            times++;
        }
        l++;
    }
    for(int i = 0; i < l; ++i)
    {
        for(int j = 0; j <= i; ++j)
            cout << G[i][j] << " ";
        cout << endl;
    }
    for(int i = l - 2; i >= 0; --i)
    {
        for(int j = 0; j <= i; ++j)
        {
            Sum[i][j] = G[i][j] + max(Sum[i + 1][j], Sum[i + 1][j + 1]);   //在一点节点的下一层左边节点和右边节点选择和最大的节点，状态是从下往上推
        }
    }
    cout << Sum[0][0] << endl;
    return 0;
}


