#include <stdio.h>
#include <math.h>
#define Pi 4.0*atan(1.0)
int main()
{
 //   const double Pi=4.0*atan(1.0);
    double s;
    int n;
    while(scanf("%d",&n))//ÊäÈë¶ÈÊı
    {
       // printf("%lf\n",Pi);
    s=sin((n/180.0)*Pi);
    printf("%lf\n",s);
    }
    return 0;
}
