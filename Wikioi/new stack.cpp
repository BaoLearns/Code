#include <stdio.h>
typedef struct
{
	int *top;
	int *base;
}sqStack;
int main()
{
	sqStack s;
	int n=2;
   	*s->base=(int *)malloc(5*sizeof(int));
	s-top=s->base;
	Push(s,3);
	while (!StackIsEmpty(s))
	{
		pop(s,e);
		printf("%d",e);
	}
	printf("\n");
	return 0;
}