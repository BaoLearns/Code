/*************************************************************************
    > File Name: exec.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月18日 星期日 21时43分04秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char **argv)
{
	pid_t pid = fork();
	if(pid < 0)
	{
		perror("fork");
		return -1;
	}
	else if(pid == 0)
	{
		execl("/bin/ls", "ls", "-al", "/home", NULL);

	}
	else
	{
		printf("parent\n");
	}
    return 0;
}
