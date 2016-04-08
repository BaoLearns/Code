#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int is_dirent(const char *path_name)
{
	DIR *dir_temp;
   	if((dir_temp = opendir(path_name)) == NULL)
			return 0;
	return 1;
}

void creat_dirent(const char *path_name, int mode)
{
	if(!is_dirent(path_name))
	{
		if(mkdir(path_name, mode) < 0)
		{
			perror("mkdir failure");
			exit(-1);
		}
	}
}

void cp_file(const char *src, const char *dst, int mode)
{
	int fd_src, fd_dst; 
	//printf("src %s,dst %s\n", src, dst);
	if((fd_src = open(src, O_RDONLY)) < 0)
	{
		perror("open src failure");
		exit(-1);
	}
	if((fd_dst = open(dst, O_CREAT | O_WRONLY, mode)) < 0)
	{
		perror("open dst failure");
		exit(-1);
	}
	char buf[BUFSIZ];
	while(1)
	{
		memset(buf, 0, BUFSIZ);
		int size = read(fd_src, buf, BUFSIZ);
		if(size < 0)
		{
			perror("read failuer");
			exit(-1);
		}
		else if(size == 0)
			break;
		write(fd_dst, buf, size);
	}
	close(fd_src);
	close(fd_dst);
}

char *get_name(const char *src, const char *dst)
{
	char *ch = (char *)malloc(1024);
	strcpy(ch, dst);
	int len1 = strlen(src), len2 = strlen(dst);
	ch[len2] = '/';
	len2++;
	for(int i = 0; i < len1; ++i)
		ch[len2 + i] = src[i];
	ch[len1 + len2] = '\0';
	return ch;
}

void travel_dirent(const char *src, const char *dst)
{
	DIR *dir_temp;
	if((dir_temp = opendir(src)) == NULL)
	{
		perror("opendir failure");
		exit(-1);
	}
	struct dirent *dp;
	struct stat statbuf;
	chdir(src);
	while((dp = readdir(dir_temp)) != NULL)
	{
		lstat(dp -> d_name, &statbuf);
		if(S_ISDIR(statbuf.st_mode))
		{
			if(!strcmp(dp -> d_name, ".") || !strcmp(dp -> d_name, ".."))
				continue;
			char *ch = get_name(dp -> d_name, dst);
			creat_dirent(ch, statbuf.st_mode);
			travel_dirent(dp -> d_name, ch);
			free(ch);
		}
		else
		{
			char *ch = get_name(dp -> d_name, dst);
			cp_file(dp -> d_name, ch, statbuf.st_mode);
			free(ch);
		}
	}
	chdir("..");
	closedir(dir_temp);
}

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		printf("ERROR!Pless usage %s src_dir dst_dir", argv[0]);
		exit(-1);
	}
	umask(0000);
	DIR *dir_temp;
	if((dir_temp = opendir(argv[1])) == NULL)
	{
		perror("No dirent");
		exit(-1);
	}
	struct dirent *dp;
	struct stat statbuf;
	chdir(argv[1]);
	if((dp = readdir(dir_temp)) != NULL)
	{
		lstat(dp -> d_name, &statbuf);
		creat_dirent(argv[2], statbuf.st_mode);
		travel_dirent(argv[1], argv[2]);
	}
    return 0;
}
