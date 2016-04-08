/*************************************************************************
    > File Name: signal.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: Sat Oct 31 20:01:01 2015
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

void handler(int sig)
{
	printf("signal = %d\n", sig);
}

int main(int argc, char **argv)
{
	printf("%p\n", main);
	signal(SIGCHLD, handler);
	pid_t pid = fork();
	if(pid < 0)
	{
		perror("fork");
		exit(-1);
	}
	else if(pid == 0)
	{
		printf("child\n");
	}
	else
	{
		sleep(1);
		printf("father\n");
	}
    return 0;
}
