/*************************************************************************
    > File Name: cp.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月04日 星期日 13时07分58秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	//printf("%d\n", argc);
	if(argc != 3)
	{
		puts("plese input format, for example \"cp src_file dst_file\"");
		exit(EXIT_FAILURE);
	}
	int fp_src, fp_dst;
	if((fp_src = open(argv[1], O_RDONLY)) < 0)
	{
		perror("open src");
		exit(EXIT_FAILURE);
	}
	if((fp_dst = open(argv[2], O_CREAT | O_WRONLY, 0664)) < 0)
	{
		perror("open dst");
		exit(EXIT_FAILURE);
	}
	char buf[1024];
	while(1)
	{
		memset(buf, '\0', 1024);
		int size = read(fp_src, buf, 1024);
		if(size < 0)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		else if(size == 0) break;
		write(fp_dst, buf, size);
	}
	close(fp_src);
	close(fp_dst);
	return 0;
}
