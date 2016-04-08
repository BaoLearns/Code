/*************************************************************************
    > File Name: exec_test.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月18日 星期日 15时55分17秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int cnt = 2;
	while(cnt--)
	{
		pid_t pid = fork();
		if(pid < 0)
		{
			perror("fork");
			exit(-1);
		}
		else if(pid == 0)
		{
			if(cnt == 1) execl("./fork_test", NULL);
			if(cnt == 0) execl("./plus_test", NULL);
		}
	//	puts("!!!!");
	}
    return 0;
}
