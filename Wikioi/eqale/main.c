#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,i,max,p=0,sum=0,sum1=0,sum2=0,avg,ant=0;
    int s[110];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",s+i),sum=+s[i];
    avg=sum/4;
    max=s[0];
    for(i=1;i<n;i++)
        if(s[i]>max) max=s[i],p=i;
    for(i=0;i<n;i++)
    {
        if(i<p) sum1=+s[i];
        if(i>p) sum2=+s[i];
    }
    s[p]=(p-i+1)*avg-sum1;
    for(i=p-1;i>=0;i--)
    {
        if(s[i]<s[p]) s[p]=s[p]-avg-s[i],ant++;
        if(s[i]>s[p]) s[p]=s[p]+s[i]-avg,ant++;
    }
    s[p]=(n-p+1)*avg-sum2;
    for(i=p+1;i<n;i++)
    {
        if(s[i]<s[p]) s[p]=s[p]-avg-s[i],ant++;
        if(s[i]>s[p]) s[p]=s[p]+s[i]-avg,ant++;
    }
    printf("%d\n",ant);
    return 0;
}
