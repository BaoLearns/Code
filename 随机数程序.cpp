#include <cstdio>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#define maxn 1000
int main()
{
	srand(time(NULL));
	while(true)
	{
		int a;
		printf("\n\n\n\n                              runing , plese wating....... \n\n\n\n\n\n");
		printf("                              ");
		while(true)
		{
			a=rand() % maxn;
			printf("%3d", a);
			printf("\b\b\b");
			if(kbhit())
				break;
			
		}
		printf("this randam number is:     %d\n                              ", a);
		system("pause");
		system("cls");
	}
	return 0;
}
