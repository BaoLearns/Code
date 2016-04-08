#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>
int main(int argc, char **argv)
{
	for(int i = 0; i < argc; ++i)
		printf("%s\n", argv[i]);
	struct rlimit r;
	if(getrlimit(RLIMIT_CPU, &r) < 0)//获得默认执行时间
	{
		perror("getrlimit error");
		exit(1);
	}
	printf("RLIMIT_CPU cur %d\n", r.rlim_cur);
	printf("RLIMIT_CPU max %d\n", r.rlim_max);
	r.rlim_cur = 1; //修改软限制
	r.rlim_max = 2; //修改硬限制
	if(setrlimit(RLIMIT_CPU, &r) < 0) //修改限制
	{
		perror("setrlimit error");
		exit(1);
	}
	if(getrlimit(RLIMIT_CPU, &r) < 0)//重新获得限制
	{
		perror("getrlimit error");
		exit(1);
	}
	printf("RLIMIT_CPU cur %d\n", r.rlim_cur);
	printf("RLIMIT_CPU max %d\n", r.rlim_max);
	while(true) //测试系统的反应
		;
	return 0;
