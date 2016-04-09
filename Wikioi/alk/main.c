#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,n,a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    void ff(int a[],int q,int r);
    ff(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
void ff(int a[],int q,int r)
{
    int f(int a[],int q,int r);
    if(q<r)
    {
        int p=f(a,q,r);
    ff(a,q,p-1);
    ff(a,p+1,r);
    }
}
int f(int a[],int q,int r)
{
    int i,j,n;
    for(j=q,i=j-1;j<r;j++)
    {
        if(a[j]>a[r])
            n=a[i++],a[i]=a[j],a[j]=n;
    }
    n=a[i+1],a[i+1]=a[r],a[r]=n;
    return i+1;
}
