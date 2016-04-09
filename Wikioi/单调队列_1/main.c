#include <stdio.h>
int main()
{
    int A[100],B[100],C[100];//构造三个队列
    int i=0,j=0,k=0;//三个下表分别未A、B、C、数组的下表
    A[0]=1;
    int p=0,q=0;//p、q是个指向
    while(A[i]<100)
    {
        B[j++]=A[i]*2+1;//给B数组赋值
        C[k++]=A[i]*3+1;// 给A数组赋值
        i++;
        if (B[p]>=C[q])//求下一个A数组的值，如果B数组的值比C数组的值小，就等于C数组的值，否则等于B数组的值
            A[i]=C[q],q++;
        else A[i]=B[p],p++;
    }
    i=0;
    while(A[i]<100)
    {
        printf("%d ",A[i++]);
    }
    putchar('\n');
    i=0;
    while(B[i]<100)
    {
        printf("%d ",B[i++]);
    }
    putchar('\n');
    i=0;
    while(C[i]<100)
    {
        printf("%d ",C[i++]);
    }
    putchar('\n');
    return 0;
}
