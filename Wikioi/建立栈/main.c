#include <stdio.h>
#include <malloc.h>
#define size 100
#define addsize 10
typedef struct
{
	int *top;
	int *base;
	int StackSize;
}sqStack;
void InitStack(sqStack *s);
int StackIsEmpty(sqStack *s);
int StackPush(sqStack *s);
int GetTop(sqStack *s);
void Pop(sqStack *s);
int StackLength(sqStack *s);
void StackTraverse(sqStack *s);
int main()
{
	sqStack s;

	InitStack(&s);
	StackIsEmpty(&s);
	StackPush(&s);
	GetTop(&s);
	Pop(&s);
	printf("The stack length is %d",StackLength(&s));
	StackTraverse(&s);
	return 0;
}
void InitStack(*s)//构造一个空栈
{
	s->base=(int *) malloc(size * sizeof(int));
	if(!s->base) printf( "base not used.\n");
	s->top=s->base;
	s->StackSize=size;
}
int StackIsEmpty(*s)
{
	if(s->StackSize==0) return 1;
	else return 0;
}
void StackPush(*s)
{
	if(s->top-s->base > size)
	{//追加栈
		s->base=int(*)relloc(s->base,(size+addsize *sizeof()int));
		if(!s->base) printf("base not used.\n");
		s->top=s->base+s->StackSize;
	}
	s->top=+1;
}
int GetTop(sqStack *s)
{

	int e;
	if(s->base==s->top) printf("The stack is null.\n");
	else
		e=*(s->top-1);
	return e;
}
void Pop(sqStack *s)
{
	int e;
	if(s->base==s->top) printf("The stack is null.\n");
	else e=*(s->top--);
	printf("The top's e =%d\n",e);
}
int StackLength(*s)
{
	int length;
	if(s->base==s->top) pritnf("The stack is null.\n");
	else length=s->top-s->base;
	return length;
}
void StackTraverse(*s)
{
	if(StackIsEmpty(s)) printf("The stack is empty.\n");
	else if(!s->base) printf("The stack is not exit.\n");
	else
	{
		int *q=s->top;
		while(q!=s->base)
		{
			printf("%d  ",*p);
			p--;
		}
		printf("\n");
	}
}


























