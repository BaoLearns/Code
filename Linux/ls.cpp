/*************************************************************************
    > File Name: ls.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月06日 星期二 18时03分48秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("Error.no match argv");
		exit(-1);
	}
	DIR *dir;
	if((dir = opendir(argv[1])) == NULL)
	{
		perror("open");
		exit(-1);
	}
	chdir(argv[1]);
	struct dirent *t;
	struct stat *statbuf;
	while((t = readdir(dir)) != NULL)
	{
		stat(t -> d_name, statbuf);
		printf("%s\t", t -> d_name);
		cout << statbuf -> st_mode << "\t" <<  statbuf -> st_size << endl;
	}
    return 0;
}
