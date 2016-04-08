/*************************************************************************
    > File Name: lseek_example.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年09月30日 星期三 13时25分49秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
void PERROR(const char *ch)
{
	perror(ch);
	exit(-1);
}
int main(int argv, char **argc)
{
	char buf1[] = "1234567890";
	char buf2[] = "abcdefghijk";
	char buf3[] = "ABCDEFGHIJK";
	int ft;
	if((ft = creat("/tmp/test2", 0644)) < 0)
		PERROR("creat");
	if(write(ft, buf1, 10) != 10)
		PERROR("write");
	if(lseek(ft, 20, SEEK_SET) == -1)
		PERROR("lseek");
	if(write(ft, buf2, 10) != 10)
		PERROR("write");
	if(lseek(ft, 10, SEEK_SET) == -1)
		PERROR("lseek");
	if(write(ft, buf3, 10) != 10)
		PERROR("write");
	if(write(ft, "\0", 1) != 1)
		PERROR("write");
	close(ft);
    return 0;
}
