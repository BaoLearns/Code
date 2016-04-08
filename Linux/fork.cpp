/*************************************************************************
    > File Name: fork.cpp
    > Author: Royecode
    > Email: Royecode@163.com 
    > Created Time: 2015年09月13日 星期日 16时15分54秒
 ************************************************************************/

#include <iostream>
#include <unistd.h>
#include <stdio.h>
using namespace std;
int main()
{
/*	pid_t fpid;
	int count = 0;
	fpid = fork();
	if(fpid < 0) cout << "error in fork" << endl;
	else if (fpid == 0) 
	{
		cout << "I am child process, my father is " << getpid();
		cout << "我是爹的儿子" << endl;
		count++;
	}
	else 
	{
		cout << "I am parent process, my son is " << getpid() << endl;
		cout << "我是孩子他爹" << endl;
		count++;
	}
	cout << count << endl; */
	int pid = fork();
	if(pid < 0)
		perror("error");
	if(pid == 0)
	{
		for(int i = 0; i < 100; ++i)
			printf("A");
	}
	else 
	{
		for(int i = 0; i < 100; ++i)
			printf("B");
	}
	return 0;
}

