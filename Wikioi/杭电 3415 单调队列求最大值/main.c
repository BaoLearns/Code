#include <stdio.h>
struct sum
{
    int x;
    int y;
    int max;
}sum;
typedef struct node
{
    int val;
    int idx;
}node;
int s[100100];
node arr[100100];
int t[200010]={0};
int main()
{
    int T;
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            int n,k,i,j=0,m=1;
            scanf("%d%d",&n,&k);
            int r=1,h=1;
            for(i=1;i<=n;++i)
            {
                scanf("%d",s+i);
                t[++j]=t[j-1]+s[i];
            }
            for(i=n+1;i<n+k;++i)
            {
                 s[i]=s[m++];
                 t[++j]=t[j-1]+s[i];
            }
            arr[1].val=t[1];
            arr[1].idx=1;
            sum.max=t[1];
            sum.x=sum.y=1;
            for(i=2;i<n+k;++i)
            {
                if(i-arr[h].idx>=k) ++h;
                while(r>=h && arr[r].val<s[i])
                {
                    --r;
                }
                arr[++r].val=t[i];
                arr[r].idx=i;
                int a=t[arr[r].idx]-t[arr[h].idx-1];
                printf("a=%d\n",a);
                if(a>sum.max) sum.max=a,sum.x=arr[h].idx,sum.y=arr[r].idx;
            }
            if(sum.y>n) sum.y=sum.y%n;
            printf("%d %d %d\n",sum.max,sum.x,sum.y);
        }
    }
    return 0;
}
