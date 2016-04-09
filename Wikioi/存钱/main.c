#include <stdio.h>
int main()
{
    void shellsort(int a[],int n);
    int b[11]={0,2,5,6,3,7,8,0,9,12,1};
    int m=10,i;
    shellsort(b,m);
    for(i=1;i<=m;i++)
        printf("%d ",b[i]);
    putchar('\n');
    return 0;
}
void shellsort(int a[],int n)
{
    int gap=n,i,j,flag;
    int kmp;
    while (gap>1)
    {
        gap=gap/2;
        do
        {
            flag=0;
            for(i=1;i<=n-gap;i++)
            {
                j=i+gap;
                if(a[i]>a[j]) kmp=a[i],a[i]=a[j],a[j]=kmp,flag=1;
            }
        }
        while (flag!=0);
    }
}
