/*#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>
using namespace std;
int main()
{

	struct rlimit r;
	if(getrlimit(RLIMIT_CPU, &r) < 0)
	{
		perror("getrlimit error");
		exit(1);
	}
	printf("RLIMIT_CPU cur %d\n", r.rlim_cur);
	printf("RLIMIT_CPU max %d\n", r.rlim_max);
	r.rlim_cur = 1;
	r.rlim_max = 2;
	if(setrlimit(RLIMIT_CPU, &r) < 0)
	{
		perror("setrlimit error");
		exit(1);
	}
	if(getrlimit(RLIMIT_CPU, &r) < 0)
	{
		perror("getrlimit error");
		exit(1);
	}
	printf("RLIMIT_CPU cur %d\n", r.rlim_cur);
	printf("RLIMIT_CPU max %d\n", r.rlim_max);
	//while(true);
	r.rlim_cur = 10;
	r.rlim_max = 20;
	if(setrlimit(RLIMIT_STACK, &r) < 0)
	{
		perror("setrlimit error");
		exit(1);
	}
	printf("RLIMIT_STACK cur %d\n", r.rlim_cur);
	printf("RLIMIT_STACK max %d\n", r.rlim_max);
	//re();
	r.rlim_cur = 1;
	r.rlim_max = 3;
	
	if(setrlimit(RLIMIT_NOFILE, &r) < 0)
	{
		perror("setrlimit error");
		exit(1);
	}
	printf("RLIMIT_NOSIZE cur %d\n", r.rlim_cur);
	printf("RLIMIT_NOSIZE max %d\n", r.rlim_max);
	ofstream out, out2;
	out.open("a1.in");
	for(int i = 0; i < 1000; ++i) out << "HHHHH";
	//out.close();
	out2.open("a2.in");
	out.close();
	out2.close();
	cout << "end" << endl;
	r.rlim_cur = 100;
	r.rlim_max = 200;
	
	if(setrlimit(RLIMIT_DATA, &r) < 0)
	{
		perror("setrlimit error");
		exit(1);
	}
	printf("RLIMIT_DATA cur %d\n", r.rlim_cur);
	printf("RLIMIT_DATA max %d\n", r.rlim_max);
	int *a = new int[500];
	for(int i = 0; i < 500; ++i) a[i] = -1;
	cout << "end" << endl;
	struct rlimit r;
	printf("sizeof(r) %lld\n", sizeof(struct rlimit));
	if(getrlimit(RLIMIT_AS, &r) < 0)
	{
		perror("getrlimit errror");
		exit(1);
	}
	printf("RLIMIT_AS cur %d\n", r.rlim_cur);
	printf("RLIMIT_AS max %d\n", r.rlim_max);
	r.rlim_cur = 10;
	r.rlim_max = 10000;
	if(setrlimit(RLIMIT_AS, &r) < 0)
	{
		perror("getrlimit error");
		exit(1);
	}
	cout << sizeof(int) * 2 << endl;
	int *a = new int[2];

	return 0;
}*/
/*
#include <stdio.h>  
#include <sys/resource.h>  
  
void pr_limits(char* name, int resource){  
        struct rlimit limit;  
        if(getrlimit(resource, &limit) <0){  
                perror("getrlimit");  
        }  
  
        printf("%-15s",name);  
        if(limit.rlim_cur == RLIM_INFINITY){  
                printf("(infinite)     ");  
        }else{  
                printf("%-15ld",limit.rlim_cur);  
        }  
  
        if(limit.rlim_max == RLIM_INFINITY){  
                printf("(infinite)     ");  
        }else{  
                printf("%-15ld",limit.rlim_max);  
        }  
        printf("\n");  
}  
  
int main(void){  
        pr_limits("LIMIT_AS",RLIMIT_AS);  
        pr_limits("RLIMIT_CORE",RLIMIT_CORE);  
        pr_limits("RLIMIT_CPU",RLIMIT_CPU);  
        pr_limits("RLIMIT_DATA",RLIMIT_DATA);  
        pr_limits("RLIMIT_FSIZE",RLIMIT_FSIZE);  
        pr_limits("RLIMIT_LOCKS",RLIMIT_LOCKS);  
        pr_limits("RLIMIT_MEMLOCK",RLIMIT_MEMLOCK);  
        pr_limits("RLIMIT_NOFILE",RLIMIT_NOFILE);  
        pr_limits("RLIMIT_NPROC",RLIMIT_NPROC);  
        pr_limits("RLIMIT_RSS",RLIMIT_RSS);  
        pr_limits("RLIMIT_STACK",RLIMIT_STACK);  
        return 0;
}*/	
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>

int main()
{
	struct rusage start, end;
	if(getrusage(0, &start) < 0) 
	{
		perror("getrusage error");
		exit(1);
	}
	int k = 0;
	for(int i = 0; i < (int)1e10; ++i);
		k++;
	getrusage(0, &end);
	double usertime = (end.ru_utime.tv_sec - start.ru_utime.tv_sec) + (end.ru_utime.tv_usec - start.ru_utime.tv_usec) / 10e6;
	double kerneltime = (end.ru_stime.tv_sec - start.ru_stime.tv_sec) + (end.ru_stime.tv_usec - start.ru_stime.tv_usec) / 10e6;
	printf("usertime %lf, kerneltime %lf\n", usertime, kerneltime);	
	printf("ru_maxrss %ld\n", start.ru_maxrss);
	printf("ru_ixrss %ld\n", start.ru_ixrss);
	return 0;
}
