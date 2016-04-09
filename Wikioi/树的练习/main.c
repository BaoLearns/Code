#include <stdio.h>
#include <stdlib.h>
int tree[16]={0,1,2,3,0,0,4,5,0,0,0,0,0,0,0,6};

void preorder(int n)
{
    printf("%d ",tree[n]);
    if(2*n<=15 && tree[2*n]!=0)
        preorder(2*n);
    if(2*n+1<=15 && tree[2*n+1]!=0)
        preorder(2*n+1);
}

void inorder(int n)
{

    if(2*n<=15 && tree[2*n]!=0)
        inorder(2*n);
    printf("%d ",tree[n]);
    if(2*n+1<=15 && tree[2*n+1]!=0)
        inorder(2*n+1);
}

void deorder(int n)
{

    if(2*n<=15 && tree[2*n]!=0)
        deorder(2*n);

    if(2*n+1<=15 && tree[2*n+1]!=0)
        deorder(2*n+1);
    printf("%d ",tree[n]);
}
int main()
{

    printf("先序遍历：");
    preorder(1);
    printf("\n-------------\n");
    printf("中序遍历：");
    inorder(1);
    printf("\n-------------\n");
    printf("后序遍历：");
    deorder(1);
    printf("\n-------------\n");
    return 0;
}
