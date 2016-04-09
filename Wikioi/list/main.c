#include <stdio.h>
#include <stdlib.h>
#define LIST-INIT-SIZE 100
#define LISTINCREMENT 10
typedef struct
{
    ElemType * elem;
    int length;
    int listsize;
}sqlist;
int main()
{
    Status InitList-sq(soList L)
    {
        L.elem=(ElemType *)malloc (LIST-INIT-SIZE * sizeof(ElemType));
        L.length=0;
        L.listsize=LIST-INIT-SIZE;
    }
    return 0;
}
