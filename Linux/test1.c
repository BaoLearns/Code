/*************************************************************************
    > File Name: test1.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年09月28日 星期一 22时27分37秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	printf("stdin %d\n", fileno(stdin));
	printf("stdout %d\n", fileno(stdout));
	printf("stderr %d\n", fileno(stderr));
	FILE *fp;
	if((fp = fopen("./test.cpp", "r")) == NULL)
	{
		perror("open");
		exit(-1);
	}
	
	printf("%d\n", fileno(fp));
	return 0;
}
