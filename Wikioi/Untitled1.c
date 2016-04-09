
#include <stdio.h>
int main()
{
    double a[12];
    int i,s=0;
    for(i=0;i<12;i++)
    {
        scanf("%2f",a+i);
        s=s+a[i];
    }
    printf("%f2",s);
    return 0;
}
