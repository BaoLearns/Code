/*************************************************************************
    > File Name: const.c
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年11月01日 星期日 12时56分33秒
 ************************************************************************/

#include <stdio.h>

int main(int argc, char **argv)
{
	int val = 10;
	int data = 12;
	const int *pt = &val;// pt是个指向int的指针，所指向地址的内容不能够修改，可改变所指向的地址
	//*pt = 11; //error
	//pt = &data; //right
	int *const pt2 = &val; //pt2是个指向int的常指针，不可改变所指向地址，可改变指向地址的内容
	//*pt2 = 15; //right
	//pt2 = &data; //error 
	int const *pt3 = &val; //等同与 const int *pt
	//*pt3 = 11;//error
	//pt3 = &data;
	const int const *pt4 = &val;
	//*pt4 = 44;
	printf("%d\n", *pt4);
	pt4 = &data;
	printf("%d\n", *pt4);
	return 0;
}
