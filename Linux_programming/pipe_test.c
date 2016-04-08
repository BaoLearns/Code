/*************************************************************************
    > File Name: pipe_test.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月21日 星期三 16时41分31秒
 ************************************************************************/
/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
void handler(int sig)
{
	if(SIGPIPE == sig) printf("recv SIGPIPE\n");
}
int main(int argc, char **argv)
{
	signal(SIGPIPE, handler);
	int fd[2];
	if(pipe(fd) < 0)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	close(fd[0]);
	int ret = write(fd[1], "hello world", 20);
	printf("ret %d\n", ret);
	//close(fd[1]);
	//char buf[BUFSIZ];
	//memset(buf, 0, sizeof(buf));
	//int ret = read(fd[0], buf, 10);
	//printf("ret = %d, buf %s\n!!\n", ret, buf);
	
	int fd[2];
	if(pipe(fd) < 0)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	close(fileno(stdout));
	dup(fd[1]);
	printf("%d\n", fd[1]);
	write(fd[1], "hello royecode", 14);
	char buf[BUFSIZ];
	memset(buf, 0, sizeof buf);
	int ret = read(fd[0], buf, BUFSIZ);
	fprintf(stderr, "ret %d, buf %s\n", ret, buf);
	return 0;
}*/
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int fd;
	char buf[BUFSIZ];
	if(argc != 2)
	{
		fprintf(stderr, "ERROR INPUT");
		exit(EXIT_FAILURE);
	}
	if((fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0664)) < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	if(dup2(fd, fileno(stdout)) < 0)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	while(scanf("%s", buf) != EOF)
	{
		if(strcmp(buf, "q") == 0) break;
		//write(fileno(stdout), buf, sizeof buf);
		printf("%s", buf);
	}
	return 0;
}
