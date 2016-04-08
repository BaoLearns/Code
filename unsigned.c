/*************************************************************************
    > File Name: unsigned.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年11月01日 星期日 18时41分50秒
 ************************************************************************/

#include <stdio.h>

void show(int c)
{
	for(int i = 31; i >=0; --i)
	{
		printf("%d", c >> i & 1);
		if(i % 4 == 0) printf(" ");
	}
	puts("\0");
}
int main(int argc, char **argv)
{
	unsigned i;
	for(i = 9; i > 0; --i)
		printf("%u\n", i);
    unsigned int a = 6;
	int b = -20;
	puts(a + b > 6?"> 6": "<=6");
	show(a);
	show(b);
	show(a + b);
	signed int c = a + b;
	return 0;
}
