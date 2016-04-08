/*************************************************************************
    > File Name: test.cpp
    > Author: Royecode
    > Email: Royecode@163.com 
    > Created Time: 2015年09月18日 星期五 15时10分18秒
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define PRINT(x) cout << #x << " " << &x << endl
#define CHECK(x) if(x == NULL) {cout << "error" << endl;\
	exit(-1);}
using namespace std;

int main()
{
	/*int i = 0, j;
	puts("stack");
	int a, b;
	PRINT(a);
	PRINT(b);
	puts("heap");
	int *pta = (int*)malloc(200);
	CHECK(pta);
	int *ptb = (int*)malloc(200);
	CHECK(ptb);
	PRINT(pta);
	PRINT(ptb);
	PRINT(i);
	PRINT(j);*/
	int a, b;
	cout << a + b << endl;
	while(cin >> a >> b) cout << a + b << endl;
	return 0;
}
