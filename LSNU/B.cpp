/*************************************************************************
    > File Name: B.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月11日 星期日 16时07分01秒
 ************************************************************************/

#include <iostream>
#include <map>
#include <set>
#include <cstdio>
using namespace std;

int main(int argc, char **argv)
{
	string st;
	map <string, int> Map;
	set <string> Set;
	int cnt = 0;
	while(getline(cin, st))
	{
		if(st.length() > 0)
		{
			cnt++;
			Map[st]++;
			Set.insert(st);
		}
	}
//	cnt--;
	//cout << cnt << endl;
	for(set <string>::iterator it = Set.begin(); it != Set.end(); ++it)
	{
		cout << *it << " ";
	   	printf("%0.4lf\n", 1.0 * Map[*it] / cnt * 100);
	}
    return 0;
}
