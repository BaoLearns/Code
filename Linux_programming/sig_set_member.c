/*************************************************************************
    > File Name: sig_set_member.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: Mon Nov  2 17:00:29 2015
 ************************************************************************/

#include <stdio.h>
#include <signal.h>

void show(sigset_t set)
{
	for(int i = 0; i < 1; ++i)
	{
		printf("0x%8x\n", set.__val[i]);
		if((i + 1) % 8 == 0) printf("\n");
	}
}
int main(int argc, char **argv)
{
	sigset_t set;
	sigemptyset(&set);
	show(set);
	sigaddset(&set, 2);
	show(set);
    return 0;
}
