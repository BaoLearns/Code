/*************************************************************************
    > File Name: b.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年07月25日 星期六 22时46分36秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	const string goal("anniversary");
	int t;
	scanf("%d", &t);
	while(t--)
	{
		string st;
		int len = st.length();
		bool flag = false;
		for(int i = 0; i < len && !flag; ++i)
		{
			int pos = 0, cnt = 0;
			for(int j = i; j < len && !flag; ++j)
			{
				if(st[j] == goal[pos]) pos++;
				else if(pos != 0) cnt++;
				if(cnt == 3)
				{
					if(pos == 10) flag = true;
					break;
				}
				if(pos == 10)
				{
					if(cnt == 2) flag = true;
					break;
				}
			}
		}
		puts(flag?"YES": "NO");
	}
	return 0;
}
