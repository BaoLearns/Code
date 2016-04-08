/*************************************************************************
    > File Name: C.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月11日 星期日 14时10分01秒
 ************************************************************************/

#include <iostream>

using namespace std;

int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};
const int MAXN = 107;
int n, m;
string st[MAXN];

void dfs(int x, int y)
{
	st[x][y] = '.';
	for(int i = 0; i < 8; ++i)
	{
		int dx = dir[i][0] + x, dy = dir[i][1] + y;
		if(dx >= 0 && dx < n && dy >= 0 && dy < m && st[dx][dy] == 'W')
			dfs(dx, dy);
	}
}
int main(int argc, char **argv)
{
	while(cin >> n >> m)
	{
		for(int i = 0; i < n; ++i)
			cin >> st[i];
		int ans = 0;
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
				if(st[i][j] == 'W')
			   	{
					ans++;
					dfs(i, j);
				}
		}
		cout << ans << endl;
	}
    return 0;
}
