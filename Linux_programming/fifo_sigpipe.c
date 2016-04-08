/*************************************************************************
    > File Name: fifo_sigpipe.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: Sat Oct 31 19:22:22 2015
 ************************************************************************/

#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void handler(int sig)
{
	printf("sig %d\n", sig);
}

int main(int argc, char **argv)
{
	signal(SIGPIPE, handler);
	unlink("FIFO");
	mkfifo("FIFO", 0664);
	pid_t pid = fork();
	if(pid < 0)
	{
		perror("fork");
		exit(-1);
	}
	else if(pid == 0)
	{
		int fd;
		if((fd = open("FIFO", O_RDONLY)) < 0)
		{
			perror("open");
			exit(-1);
		}
		close(fd);
	}
	else
	{
		int fd;
		if((fd = open("FIFO", O_WRONLY)) < 0)
		{
			perror("open");
			exit(-1);
		}
		sleep(1);
		int ret = write(fd, "hello Royecode", 14);
		printf("ret %d\n", ret);
	}
    return 0;
}
