/*************************************************************************
    > File Name: time.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: Sat Oct 31 21:50:54 2015
 ************************************************************************/
/*
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

void handler(int sig)
{
	printf("sig = %d\t", sig);
	printf("%d\n", ftime());
}

int main()
{
	//kill(getpid(), SIGALRM);
	signal(SIGALRM, handler);
	struct itimerval val;
	val.it_interval.tv_sec = 2;
	val.it_interval.tv_usec = 0;
	val.it_value.tv_sec = 2;
	val.it_value.tv_usec = 0;
	setitimer(ITIMER_REAL, &val, NULL);
	while(1);
	return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int sig)
{
	if(sig == SIGUSR1)
		puts("received SIGUSR1");
	else if(sig == SIGUSR2)
		puts("received SIGUSR2");
	else
		puts("Error");
}
int main()
{
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while(1)
	pause();
	return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int sig)
{
	printf("signal %d\n", sig);
}
void foo(int sig, siginfo_t *info, void *p)
{
	printf("signal = %d\n", sig);
	printf("sender pid = %d\n", info -> si_pid);
}
int main()
{
	struct sigaction act, oact;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = foo;
	sigaction(SIGUSR1, &act, &oact);
	while(1)
	{
		printf("hello world");
		pause();
	}
	return 0;
}
