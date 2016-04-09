#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int comp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int n,m,i=0,j;
    scanf("%d",&n);
    int s[n];
    m=n;
    while(n--)
    {
        scanf("%d",s+i);
        i++;
    }
    qsort(s,i,sizeof(int),comp);
    int t[m];
    memset(t,0,sizeof(int)*m);
    /*for(i=0;i<m;i++)
        printf("%d ",t[i]);*/
    i=0,j=0;
    int p=0,q=0;
    t[p]=s[i]+s[i+1];
    t[p+1]=t[p]+s[i+2];
    q++;
    i=2;
    q=2;
    //p=0;
    //i=0;
    m=m-2;
    while(--m)
    {
        if(s[i]<t[p] && s[i+1]<t[p])
            {
                t[q++]=s[i]+s[i+1];
                i=i+2;
            }
        else if(s[i]>t[p]&&s[i]>t[p+1])
            {
                t[q++]=t[p]+t[p+1];
                p=p+2;
            }
        else
            {
                t[q++]=s[i++]+t[p++];
            }
        printf("p=%d,q=%d,t[]=%d\n",p,q,t[p-1]);
    }
    printf("%d\n",t[q-1]);
    return 0;
}
