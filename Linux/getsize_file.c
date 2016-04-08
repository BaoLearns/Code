/*************************************************************************
    > File Name: getsize_file.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月04日 星期日 20时47分13秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	if(argc != 2)
	{
		perror("too less argv");
		exit(-1);
	}
	FILE *fp;
	if((fp = fopen(argv[1], "r")) == NULL)
	{
		perror("fopen");
		exit(-1);
	}
	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
	printf("%s size = %ld", argv[1], size);
	fclose(fp);
    return 0;
}
