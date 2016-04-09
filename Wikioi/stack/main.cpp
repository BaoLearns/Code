#include <cstdio>
#include <malloc.h>
#define desize 100
#define desizeadd 10
typedef struct Stack
{
    int *base, *top;
    int size;
}Stack,* PStack;
PStack S;
void Init_stack()
{
    S->base=(int *)malloc(sizeof(int) * desize);
    if(S->base == NULL)
    {
        printf("malloc fail\n");
        exit(0);
    }
    S->top=S->base;
    S->size=desize;
}
int main()
{
    Init_stack();
    return 0;
}
