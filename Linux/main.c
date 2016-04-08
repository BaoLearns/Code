/*************************************************************************
    > File Name: main.cpp
    > Author: Royecode
    > Email: Royecode@163.com 
    > Created Time: 2015年09月15日 星期二 21时22分45秒
 ************************************************************************/

#include <stdio.h>
int main(int argc, char **argv)
{
	int n;
	while(~scanf("%d", &n))
		printf("%*s%s\n", n, "", "hello world");

	return 0;
}

