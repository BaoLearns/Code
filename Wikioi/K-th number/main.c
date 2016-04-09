#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 101000
int s[MAX],t[MAX];
int partition(int s[],int p,int r)
{
    int i=p-1,j=p,t;
    for(;j<=r;j++)
        if(s[j]<=s[r]) t=s[j],s[j]=s[++i],s[i]=t;
    return i;
}
void quicksort(int s[],int p,int r)
{
    if(p<r)
    {
        int q=partition(s,p,r);
        quicksort(s,p,q-1);
        quicksort(s,q+1,r);
    }
}
int main()
{

    int i,n,m;
    while (scanf("%d%d",&n,&m))
    {
            memset(s,0,sizeof(n));
            memset(t,0,sizeof(n));
        for(i=1;i<=n;i++)
            scanf("%d",s+i);
            while(m--)
            {
                int a,b,k;
                scanf("%d%d%d",&a,&b,&k);
                memcpy(t,s,sizeof(s));
                quicksort(t,a,b);
                printf("%d\n",t[a+k-1]);
            }
    }
    return 0 ;
}
