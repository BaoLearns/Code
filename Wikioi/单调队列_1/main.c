#include <stdio.h>
int main()
{
    int A[100],B[100],C[100];//������������
    int i=0,j=0,k=0;//�����±�ֱ�δA��B��C��������±�
    A[0]=1;
    int p=0,q=0;//p��q�Ǹ�ָ��
    while(A[i]<100)
    {
        B[j++]=A[i]*2+1;//��B���鸳ֵ
        C[k++]=A[i]*3+1;// ��A���鸳ֵ
        i++;
        if (B[p]>=C[q])//����һ��A�����ֵ�����B�����ֵ��C�����ֵС���͵���C�����ֵ���������B�����ֵ
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
