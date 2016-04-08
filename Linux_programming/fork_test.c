/*************************************************************************
    > File Name: fork_test.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月18日 星期日 15时51分11秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
void test()
{
	printf("exiting");
}
int main(int argc, char **argv)
{
	//atexit(test);
	//void *arg[2] = {"hello", NULL};
	//on_exit(test, arg);
	printf("pid %d\t ppid %d\n", getpid(), getppid());
	pid_t pid = fork();
	if(pid < 0)
	{
		perror("fork");
		exit(-1);
	}
	else if(pid == 0) 
	{
		printf("pid %d\t ppid %d\n", getpid(), getppid());
		sleep(2);
		printf("pid %d\t ppid %d\n", getpid(), getppid());
		exit(10);
	}
	else 
	{
		sleep(1);
		//puts("parent");
		exit(0);
	}
    exit(10);
}
/*
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	int fd = open("./in", O_CREAT | O_RDWR | O_APPEND, 0664);
	pid_t pid = fork();
	if(pid == 0)
	{
		write(fd, "child\n", 6);
	}
	else
	{
		write(fd, "parent\n", 7);
	}
	return 0;
}*/
