#include <stdio.h>
#define max 1000100
struct node
{
    int val,idx;
}arr1[max],arr2[max];
int s[max];
int main()
{

    //freopen("window.in","r",stdin);
    //freopen("window.out","w",stdout);
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        int r=1,l=1;
        for(int i=1;i<=n;++i)
            scanf("%d",s+i);
        arr1[1].val=arr2[1].val=s[1];
        arr1[1].idx=arr2[1].idx=1;
        for(int i=2;i<=n+1;++i)
        {
            if(i>k)
            {
                printf("%d ",arr2[l].val);
                if(i-arr2[l].idx>=k)
                    ++l;
            }
            while(r>=l && arr2[r].val>s[i])
                --r;
            arr2[++r].val=s[i];
            arr2[r].idx=i;
        }
        putchar('\n');
        r=l=1;
        for(int i=2;i<=n+1;++i)
        {
            if(i>k)
            {
                printf("%d ",arr1[l].val);
                if(i-arr1[l].idx>=k)
                    ++l;
            }
            while(r>=l && arr1[r].val<s[i])
                --r;
            arr1[++r].val=s[i];
            arr1[r].idx=i;
        }
        putchar('\n');
    }
    return 0;
}
