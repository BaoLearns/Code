#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 10010
#define INX 1000000
double arr[max];
int n,k;
int Find(double mid)
{
    int num=0,i;
    for(i=0;i<n;++i)
        num+=(int)(arr[i]/mid);
    return num>=k;
}

int main()
{
    int i;
    while(~scanf("%d%d",&n,&k))
    {
        for(i=0;i<n;++i)
            scanf("%lf",arr+i);
        double l=0,r=INX;
        for(i=0;i<100;++i)
        {
            double mid=(l+r)/2;
            if(Find(mid))
                l=mid;
            else
                r=mid;
        }
        printf("%.2f\n",floor(r*100)/100);
    }
    return 0;
}
