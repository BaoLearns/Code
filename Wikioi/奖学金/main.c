#include <stdio.h>
struct name
    {
        int m;
        int chinese;
        int math;
        int engish;
        int sum;
    }a[100];
int main()
{
    struct name t;
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a[i].chinese,&a[i].math,&a[i].engish);
        a[i].m=i;
        a[i].sum=a[i].chinese+a[i].math+a[i].engish;
    }
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
            if(a[i].sum<a[j].sum) t=a[i],a[i]=a[j],a[j]=t;
    for(i=1;i<=5;i++)
        {
            for(j=i+1;j<=5;j++)
                if(a[i].sum==a[j].sum && a[i].chinese<a[j].chinese) t=a[i],a[i]=a[j],a[j]=t;

        }

      for(i=1;i<=5;i++)
        {
            for(j=i+1;j<=5;j++)
            {
                if(a[i].sum==a[j].sum && a[i].chinese==a[j].chinese && a[i].m>a[j].m) t=a[i],a[i]=a[j],a[j]=t;

            }
        }
    for(i=1;i<=n;i++)
        printf("%d %d\n",a[i].m,a[i].sum);
    return 0;
}
