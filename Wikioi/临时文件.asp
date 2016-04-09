#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    char s[4],t[4];
    int k[1000]={0};
    int c=1,m=0;
    while (c==1)
    {
        scanf("%s",s);
        strcpy(t,s);
        int i,j;
        int  ti;
        for(i=0;i<=3;i++)
        {
            for(j=0;j<=3;j++)
            {
                if (s[i]<s[j]) ti=s[i],s[i]=s[j],s[j]=ti;
                if (t[i]>t[j]) ti=t[i],t[i]=t[j],t[j]=ti;
            }
        }
        for(i=3,j=0;i>=0;i++,j++)
        {
            if(s[i]-t[i]<0) s[i-1]--,k[m]=k[m]+(s[i]-t[i]+10)*pow(10,j);
            else k[m]=k[m]+(s[i]-t[i])*pow(10,j);
        }
        printf("%d\n",k[m++]);
        for(i=0;i<m;i++)
        {
            for(j=i+1;j<m;j++)
                if(k[i]==k[j]) c=0;
        }
    }
    return 0;
}
