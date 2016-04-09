/*
 * һ�������Σ�ѡ��һ��·��������·�������ĵ�����
 *            1
 *          2    3
 *       4     5    6
 *    7
 *�;���14
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 1007
using namespace std;
int G[MAXN][MAXN]; //�洢����
int Sum[MAXN][MAXN]; //�����εĺ�
int main()
{
    int n, l = 0, times = 0;
    cin >> n;
    for(int i = 0; times < n; ++i) //�洢��ʱ���Ǵ������ң����ϵ��´洢����һ�д�һ������n�д�n��
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
            Sum[i][j] = G[i][j] + max(Sum[i + 1][j], Sum[i + 1][j + 1]);   //��һ��ڵ����һ����߽ڵ���ұ߽ڵ�ѡ������Ľڵ㣬״̬�Ǵ���������
        }
    }
    cout << Sum[0][0] << endl;
    return 0;
}


