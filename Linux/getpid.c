/*************************************************************************
    > File Name: getpid.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月13日 星期二 21时42分06秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	printf("\t pid \tppid \tpgid\n");
	printf("parent\t%d\t%d\t%d\n", getpid(), getppid(), getpgid(0));
	for(int i = 0; i < 2; ++i)
	{
		if(fork() == 0)
			printf("son   \t%d\t%d\t%d\n", getpid(), getppid(), getpgid(0));
	}	
	return 0;
}
