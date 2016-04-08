/*************************************************************************
    > File Name: sizeof.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年11月01日 星期日 13时46分50秒
 ************************************************************************/

#include <stdio.h>

int main(int argc, char **argv)
{
	int a[10];
	int *ptr = &a[5];
	a[5] = 200;
	printf("sizeof(a) = %ld\n", sizeof(a));
	printf("sizeof(a[100]) = %ld\n", sizeof(a[100]));
	printf("sizeof(a[1]) = %ld\n", sizeof(a[1]));

	printf("sizeof(*ptr) = %ld\n", sizeof(*ptr));
	printf("sizeof(ptr) = %ld\n", sizeof(ptr));
	printf("sizeof(long*) = %ld\n", sizeof(long *));
	printf("sizeof(int)*ptr = %ld\n", sizeof(int) + *(ptr));

    return 0;
}
