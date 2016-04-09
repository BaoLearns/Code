#include <stdio.h>
#include <stdlib.h>
#define max 100010
int s[max];
int cnt=0;
void sort(int *s,int p,int q,int r)
{
    int a[q-p+1],b[r-q];
    int i,j,k;
    for(i=0;i<q-p+1;++i)
        a[i]=s[i+p];
    for(i=0;i<r-q;++i)
        b[i]=s[i+q+1];
    for(i=0;i<q-p+1;++i)
        printf("%d ",a[i]);
    putchar('\n');
    for(i=0;i<r-p;++i)
        printf("%d ",b[i]);
    putchar('\n');
    i=0,j=0,k=p;

    while(i<q-p+1 && j<r-q)
    {
        if(a[i] <= b[j])
        {
            s[k++]=a[i++];
        }
        else
       	{
	        s[k++]=b[j++];
            ++cnt;
        }
    }
    while(i < q-p+1)
    {
        s[k++]=a[i++];
        cnt+=r-q-1;

    }
    while(j < p-q)
    {
        s[k++]=b[j++];
    }
    printf("cnt=%d,p=%d,q=%d,r=%d\n",cnt,p,q,r);
    return;
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
    return ;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;++i)
        scanf("%d", s+i);
    mrag_sort(s,0,n-1);
    printf("%d\n",cnt);
    for(i=0;i<n;++i)
        printf("%d ",s[i]);
    return 0;
}
