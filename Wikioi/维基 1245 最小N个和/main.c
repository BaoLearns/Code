#include <stdio.h>
#include <stdlib.h>
int comp(const int *a,const int * b)
{
    return *(int *)a-*(int *)b;
}
int A[100010],B[100010],s[100010];
int main()
{
    int n,i=0,j=0,m,num=0;
    scanf("%d",&n);
    m=n;
    while(m--)
    {
        scanf("%d",A+i++);
    }
    m=n;
    while(m--)
    {
        scanf("%d",B+j++);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            s[num++]=A[i]+B[j];
    }
    qsort(s,num,sizeof(int),comp);
    for(i=0;i<n;i++)
        printf("%d ",s[i]);
    putchar('\n');
    return 0;
}
