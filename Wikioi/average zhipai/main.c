#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,i,sum=0,avg,ant=0;
    int s[110];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",s+i),sum+=s[i];
    avg=sum/n;
    for(i=0;i<n;i++)
    {
        if(s[i]!=avg)
            s[i+1]+=s[i]-avg,ant++;
    }
    printf("%d\n",ant);
    return 0;
}
