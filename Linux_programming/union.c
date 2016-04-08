/*************************************************************************
    > File Name: union.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年11月02日 星期一 16时28分50秒
 ************************************************************************/

#include <stdio.h>

union val
{
	char c[4];
	int i;
};
int main(int argc, char **argv)
{
	union val data;
	data.c[0] = 0x04;
	data.c[1] = 0x03;
	data.c[2] = 0x03;
	data.c[3] = 0x11;
	printf("%x\n", data.i);
    return 0;
}
