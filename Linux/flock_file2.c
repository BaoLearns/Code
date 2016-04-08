/*************************************************************************
    > File Name: flock_file.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年09月30日 星期三 14时07分41秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argv, char **argc)
{
	freopen("/tmp/out", "w", stdout);
	for(int i = 0; i < 10; ++i)
		printf("!!!!!!!");
	sleep(10);
	fclose(stdout);
    return 0;
}
