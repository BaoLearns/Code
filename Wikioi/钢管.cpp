#include <stdio.h>
struct gang
{
    int len;
    int c;
    int date;
}a[10000];
int main()
{
    int n,i,j;
    struct gang t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&a[i].len,&a[i].c,&a[i].date);
    }
    for(i=0;i<n;i++)
        for(j=i;j<n-1;j++)
        if(a[i].len<a[j].len) t= a[i],a[i]=a[j],a[j]=t;
    for(i=0;i<n;i++)
        for(j=i;j<n-1;j++)
        if(a[i].len==a[j].len && a[i].c>a[j].c) t= a[i],a[i]=a[j],a[j]=t;
    for(i=0;i<n;i++)
        for(j=i;j<n-1;j++)
        if(a[i].c==a[j].c && a[i].date<a[j].date) t= a[i],a[i]=a[j],a[j]=t;
    printf("%d\n",a[0].date);
	return 0;
}
