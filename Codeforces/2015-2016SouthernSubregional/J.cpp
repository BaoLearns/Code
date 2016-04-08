#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int w, h, dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1}, cnt[11][11];
char maze[11][11];
int ans = 0;
bool used[11][11][26];
bool ok(int x, int y, char d)
{
	return x >= 0 && x < w && y >= 0 && y < h && maze[x][y] != '*';
}
void dfs(int x, int y, char d)
{
	if(used[x][y][d - 'A']) return;
	//cout << x << " " << y << " " << d << endl;
	cnt[x][y] = 1;
	used[x][y][d - 'A'] = true;
	if(d == 'U')
	{
		if(ok(x - 1, y, d))
			dfs(x - 1, y, d);
		else 
			dfs(x, y, 'R');
	}
	else if(d == 'R')
	{
		if(ok(x, y + 1, d))
			dfs(x, y + 1, d);
		else
			dfs(x, y, 'D');
	}
	else if(d == 'D')
	{
		if(ok(x + 1, y, d))
			dfs(x + 1, y, d);
		else
			dfs(x, y, 'L');
	}
	else
	{
		if(ok(x, y - 1, d))
			dfs(x, y - 1, d);
		else
			dfs(x, y, 'U');
	}
}
int main(int argc, char **argv)
{
	cin >> w >> h;
	int x, y;
	getchar();
	for(int i = 0; i < w; ++i)
	{
		cin >> maze[i];
		for(int j = 0; j < h; ++j)
			if(maze[i][j] != '*' && maze[i][j] != '.')
				x = i, y = j;
	}
	dfs(x, y, maze[x][y]);
	cnt[x][y] = 1;
	int ans = 0;
	for(int i = 0; i < w; ++i)
		for(int j = 0; j < h; ++j)
			ans += cnt[i][j];
	cout << ans << endl;
	return 0;
}
