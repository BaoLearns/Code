#include <stdio.h>
int tree[20];
int n;

void preorder(int i)
{
    printf("%d ",tree[i]);
    if(2*i<=2*n+1 && tree[2*i]!=0)
        preorder(2*i);
    if(2*i+1<=2*n+1 && tree[2*i+1]!=0)
        preorder(2*i+1);
}

void inorder(int i)
{

    if(2*i<=2*n+1 && tree[2*i]!=0)
        inorder(2*i);
    printf("%d ",tree[i]);
    if(2*i+1<=2*n+1 && tree[2*i+1]!=0)
        inorder(2*i+1);
}

void deorder(int i)
{

    if(2*i<=2*n+1 && tree[2*i]!=0)
        deorder(2*i);

    if(2*i+1<=2*n+1 && tree[2*i+1]!=0)
        deorder(2*i+1);
    printf("%d ",tree[i]);
}
int main()
{
    tree[1]=1;
    scanf("%d",&n);

    int i;
    for(i=2;i<=2*n+1;++i)
        scanf("%d",&tree[i]);
    for(i=1;i<=2*n+1;++i)
        printf("tree[%d]=%d\n",i,tree[i]);
    putchar('\n');
    preorder(1);
    putchar('\n');
    inorder(1);
    putchar('\n');
    deorder(1);
    putchar('\n');
	return 0;
}

