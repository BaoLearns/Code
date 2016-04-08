/*************************************************************************
    > File Name: static.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年11月01日 星期日 12时45分03秒
 ************************************************************************/

#include <stdio.h>
int count(int i)
{
	static int count = 0;
	count += i;
	return count;
}
int main(int argc, char **argv)
{
	for(int i = 0; i <=5; ++i)
	{
		int j = count(i);
		printf("i = %d, j = %d\n", i, j);
	}
    return 0;
}
