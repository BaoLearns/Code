/*************************************************************************
    > File Name: plus.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月18日 星期日 16时00分00秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char **argv)
{
	int k;
	for(int i = 0; i < 100000; ++i) k = i;
	printf("k = %d\n", k);
	sleep(2);
    return 0;
}
