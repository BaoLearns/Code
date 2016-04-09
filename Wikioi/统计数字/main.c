#include <stdio.h>
int a[10010]={0},num[150000000]={0};
int main()
{
    int n,i,j=0,max=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&j);
        if(j>max) max=j;
        a[j]=j;
        num[j]++;
    }
    for(i=0;i<max;i++)
    {
        if(a[i]!=0 && num[i]!=0) printf("%d %d\n",a[i],num[i]);
    }
    return 0;
}
