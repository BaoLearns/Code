/*************************************************************************
    > File Name: umask_example.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月04日 星期日 16时11分18秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argv, char **argc)
{
	umask(0);
	if(creat("test01", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) < 0)
	{
		perror("creat");
		exit(-1);
	}
	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if(creat("test02", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) < 0)
	{
		perror("creat");
		exit(-1);
	}
    return 0;
}
