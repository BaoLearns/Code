#include <stdio.h>
#include <stdlib.h>
#define max 500100
int s[max];
long long cnt;
void sort(int *s,int p,int q,int r)
{
    int n=q-p+1,m=r-q;
    int a[n],b[m];
    int i,j,k;
    for(i=0;i<n;++i)
        a[i]=s[i+p];
    for(i=0;i<m;++i)
        b[i]=s[i+q+1];
    i=j=0,k=p;
    while(i<n && j<m)
    {
        if(a[i] <= b[j])
            s[k++]=a[i++];
        else
        {
            s[k++]=b[j++];
            cnt+=n-i;
        }
    }
    while(i<n)
    {
        s[k++]=a[i++];

    }
    while(j < m)
    {
        s[k++]=b[j++];
    }
}
void mrag_sort(int *s,int p,int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        mrag_sort(s,p,q);
        mrag_sort(s,q+1,r);
        sort(s,p,q,r);
    }
}
int main()
{
    int n;
    while(scanf("%d",&n) && n!=0)
    {
        cnt=0;
        int i;
        for(i=0;i<n;++i)
            scanf("%d",s+i);
        mrag_sort(s,0,n-1);
        printf("%lld\n",cnt);
    }
    return 0;
}
