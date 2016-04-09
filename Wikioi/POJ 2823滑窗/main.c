#include <stdio.h>
typedef struct node
{
    int val;
    int idx;
}node;
int s[10000100];
node arr1[10000100];
node arr2[10000100];
int main()
{
    int n,k,i;
    while(~scanf("%d%d",&n,&k))
    {
        if (n<k) k=n;
        int r=1,h=1;
        for(i=1;i<=n;++i)
            scanf("%d",s+i);
        arr1[1].val=arr2[1].val=s[1];
        arr1[1].idx=arr2[1].idx=1;
        for(i=2;i<=n+1;++i)
        {
            if(i<=k)
            {
                while(r>=h && arr2[r].val>s[i])
                {
                    --r;
                }
                arr2[++r].val=s[i];
                arr2[r].idx=i;
            }
            else
            {
                printf("%d ",arr2[h].val);
                if(i-arr2[h].idx>=k) ++h;
                while(r>=h && arr2[r].val>s[i])
                {
                    --r;
                }
                arr2[++r].val=s[i];
                arr2[r].idx=i;
            }
        }
        putchar('\n');
        r=1,h=1;
        for(i=2;i<=n+1;++i)
        {
            if(i<=k)
            {
                while(r>=h && arr1[r].val<s[i])
                {
                    --r;
                }
                arr1[++r].val=s[i];
                arr1[r].idx=i;
            }
            else
            {
                printf("%d ",arr1[h].val);
                if(i-arr1[h].idx>=k) ++h;
                while(r>=h && arr1[r].val<s[i])
                {
                    --r;
                }
                arr1[++r].val=s[i];
                arr1[r].idx=i;
            }
        }
        putchar('\n');
    }
    return 0;
}
