/*************************************************************************
    > File Name: test01.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月18日 星期日 22时17分28秒
 ************************************************************************/

#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
void handler(int sig)
{
	printf("signal %d\n", sig);
	exit(-1);
}

int main(int argc, char **argv)
{
	signal(SIGSEGV, handler);
	for(int i = 0; i < 3; ++i)
		puts("Hello world");
	return 0;
}
