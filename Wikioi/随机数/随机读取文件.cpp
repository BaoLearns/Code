#include <cstdio>
#include <cstdlib>
int main()
{
	int arr[10]={1,5,3,4,5};
	int *p=arr;
	printf("%d",*p++);
	return 0;
}