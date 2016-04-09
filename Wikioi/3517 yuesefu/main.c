#include <stdio.h>
int main()
{
    int s[10010];
    int i;
    for(i=1;i<=10000;i++)
        s[i]=i;
    int *p;
    int n,k,m,l=1,num=0;
    scanf("%d%d%d",&n,&k,&m);
    s[m]=0;
    while(l)
    {
        for(i=1;i<=k;i++)
            if(*(p+i)==0) p=+1;
        *(p+k)=0;
        if(p>&s[n])
            for(i=1;;i++)
                if(s[i]!=0) p=+1;
        for(i=1;i<=n;i++)
        if(s[i]!=0) num++;
        if(num==1) printf("%d",i),l=0;
    }


    return 0;
}
