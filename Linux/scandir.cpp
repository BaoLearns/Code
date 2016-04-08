/*************************************************************************
    > File Name: scandir.cpp
    > Author: Royecode
    > Email: Royecode@163.com 
    > Created Time: 2015年09月13日 星期日 15时26分53秒
 ************************************************************************/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string>

void scan_dir(char *dir, int depth)
{
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	if((dp = opendir(dir)) == NULL)
	{
		puts("无法打开目录");
		return;
	}
	chdir(dir);
	while((entry = readdir(dp)) != NULL)
	{
		lstat(entry->d_name, &statbuf);
		if(S_IFDIR & statbuf.st_mode)
		{
			if(strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0)
				continue;
			printf("%s %s\n", depth, entry->d_name);
			scan_dir(entry->d_name, depth + 4);
		}
		else printf("%s\n",  entry->d_name);
	}
	chdir("..");
	closedir(dp);
}
int main()
{
	puts("begin");
	char dir[100];
	getcwd(dir, sizeof dir);
	printf("%s\n", dir);
	//scanf("%s", dir);
	//scan_dir(dir, 0);
	puts("done");
	mkdir("/home/royecode/Programming/KKKKK", 777);
	rmdir("/home/royecode/Programming/KKKKK");
	chdir("/");
	getcwd(dir, sizeof dir);
	printf("%s\n", dir);
	scan_dir("/home/royecode/Programming", 0);
	return 0;
}

