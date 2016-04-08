/*************************************************************************
    > File Name: flock_file.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年09月30日 星期三 14时07分41秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

struct flock* file_lock(short type, short whence)
{
	static struct flock ret;
	ret.l_type = type;
	ret.l_start = 0;
	ret.l_whence = whence;
	ret.l_len = 0;
	ret.l_pid = getpid();
	return &ret;
}
int main(int argc, char **argv)
{
	int fd = open(argv[1], O_WRONLY | O_APPEND);
	time_t now;
	for(int i = 0; i < 1000; ++i)
	{
		fcntl(fd, F_SETLKW, file_lock(F_WRLCK, SEEK_SET));
		time(&now);
		printf("%s\t%s F_SETLKW lock file %s for 5s\n", ctime(&now), argv[0], argv[1]);
		char buf[BUFSIZ] = {0};
		sprintf(buf, "hello world %d\n", i);
		int len = strlen(buf);
		if(write(fd, buf, len))
			printf("%s\t%s write file sccess\n", ctime(&now), argv[0], argv[1]);
		sleep(5);
		fcntl(fd, F_SETLKW, file_lock(F_UNLCK, SEEK_SET));
	}
	close(fd);
	return 0;
}







