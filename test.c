/*************************************************************************
    > File Name: test.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2016年01月22日 星期五 23时55分54秒
 ************************************************************************/

#include <stdio.h>
int count = 0;
int fac(int i)
{
	count++;
	if(i == 0) return 1;
	return fac(i - 1) * i;
}
int main(int argc, char **argv)
{
	printf("%d, %d\n", fac(6), count);
    return 0;
}
