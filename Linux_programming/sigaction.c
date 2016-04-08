/*************************************************************************
    > File Name: sigaction.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年11月02日 星期一 14时44分00秒
 ************************************************************************/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
void handler(int sig)
{
	printf("signal = %d\n", sig);
	sleep(1);
}
int main(int argc, char **argv)
{
	struct sigaction new, old;
	new.sa_handler = handler;
	new.sa_flags = 0;
	sigemptyset(&new.sa_mask);
	sigaction(SIGUSR1, &new, &old);
	sigemptyset(&new.sa_mask);
	sigaction(SIGALRM, &new, &old);
	ualarm(20, 50);
	while(1)
	{
		printf("helld world\n");
		sleep(1);
		raise(SIGUSR1);
		//kill(getpid(), SIGUSR1);	
	}
    return 0;
}
