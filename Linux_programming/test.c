/*************************************************************************
    > File Name: test.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月18日 星期日 20时54分59秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main(int argc, char **argv)
{
/*	printf("pid %d\t ppid %d\t pgid %d\n", getpid(), getppid(), getpgid(0));
	printf("pgid %d\n", getpgrp());
	//printf("tcgetpgrp");
	printf("uid %d\t gid %d\n", getuid(), getgid());
*/
/*
	uid_t uid, euid, suid;
	getresuid(&uid, &euid, &suid);
	printf("uid %d\teuid %d\tsuid %d\tgetegid %d\n", uid, euid, suid, getegid());	
  	*/
	int t = 0;
	pid_t pid = fork();
	if(pid < 0) 
	{
		perror("vfork");
		exit(-1);
	}
	else if(pid == 0)
	{
		t = 1;
		printf("child %d\n", t);
	}
	else
	{
		sleep(1);
		printf("parent %d\n", t);
	}
	return 0;
}
