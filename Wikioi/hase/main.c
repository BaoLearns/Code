#include <stdio.h>
#include <stdlib.h>
int s[1001]={0};
int main()
{
    int n,i,a,ant=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        s[a]=1;
    }
    for(i=1;i<=1000;i++)
        if(s[i]) ant++;
    printf("%d\n",ant);
    for(i=1;i<=1000;i++)
        if(s[i]) printf("%d ",i);
    printf("\n");
    return 0;
}
