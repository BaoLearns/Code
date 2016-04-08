/*************************************************************************
    > File Name: test_heap.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年09月30日 星期三 15时55分46秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <unistd.h>
int main(int argc, char **argv)
{
	void *p = malloc(10);
	printf("%p\n", p);
	void *t = sbrk(0);
	printf("%p\n", t);
	printf("%ld\n", abs((long)t - (long)p));
    return 0;
}
