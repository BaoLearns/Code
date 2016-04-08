/*************************************************************************
    > File Name: A.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年11月01日 星期日 09时58分51秒
 ************************************************************************/
/*
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

#define P pair <int, int>

using namespace std;

const int INF = 1e9;
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
char maze[9][9];

bool ok(int x, int y, char ch)
{
	if(x >= 0 && x < 8 && y >= 0 && y < 8 && (maze[x][y] == '.' || maze[x][y] == ch)) return true;
	return false;
}

int bfs(int x, int y, char ch, int cnt)
{
	queue <P> que;
	int d[8][8];
	for(int i = 0; i < 8; ++i)
		for(int j = 0; j < 8; ++j)
			d[i][j] = INF;
	que.push(P(x, y));
	d[x][y] = 0;
	while(!que.empty())
	{
		P e = que.front();
		que.pop();
		//cout << e.first << " " << e.second << " " << cnt << endl;
		if(maze[e.first][e.second] == ch) cnt--;
		if(cnt == 0) return d[e.first][e.second] - 1;
		for(int i = 0; i < 4; ++i)
		{
			int dx = e.first + dir[i][0], dy = e.second + dir[i][1];
			if(ok(dx, dy, ch) && d[dx][dy] == INF)
			{
				d[dx][dy] = d[e.first][e.second] + 1;
				que.push(P(dx, dy));
			}
		}
	}
	//cout << "Error" << endl;
}

int main(int argc, char **argv)
{
	int bx, by, wx, wy;
	int cntb = 0, cntw = 0;
	for(int i = 0; i < 8; ++i)
	{
		scanf("%s", maze[i]);
		for(int j = 0; j < 8; ++j)
		{
			if(maze[i][j] == 'W') 
			{
				cntw++;
				wx = i, wy = j;
			}
			if(maze[i][j] == 'B') 
			{
				cntb++;
				bx = i, by = j;
			}
		}	
	}
	for(int i = 0; i < 8; ++i)
		cout << maze[i] << endl;	
	cout << bfs(bx, by, 'B', cntb) << " " << bfs(wx, wy, 'W', cntw) << endl;
	cout << (bfs(bx, by, 'B', cntb) > bfs(wx, wy, 'W', cntw)? 'A': 'B') << endl;
    return 0;
}
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	string st[8];
	for(int i = 0; i < 8; ++i)
		cin >> st[i];
	int ansa = 100, ansb = 100;
	for(int i = 0; i < 8; ++i)
	{
		for(int j = 0; j < 8; ++j)
		{
			if(st[i][j] == 'W')
			{
				bool f = true;
				for(int k = i - 1; k >= 0; --k)
					if(st[k][j] != '.') f = false;
				if(f) ansa = min(ansa, i);
			}
		}
	}
	for(int i = 0; i < 8; ++i)
	{
		for(int j = 0; j < 8; ++j)
		{
			if(st[i][j] == 'B')
			{
				bool f = true;
				for(int k = i + 1; k < 8; ++k)
					if(st[k][j] != '.') f = false;
				if(f) ansb = min(ansb, 7 - i);
			}
		}
	}
	//cout << ansa << " " << ansb << endl;
	cout << (ansa <= ansb? "A": "B") << endl;
	return 0;
}
