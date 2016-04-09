#include <stdio.h>
int n,hash[10],num[11];
void ff(int m)
{
    if(m==n)
    {
        int j;
        for(j=0;j<n;++j)
            printf("%d ",num[j]);
        putchar('\n');
    }
    else
    {
        int i;
        for(i=1;i<=n;++i)
        {
            if(!hash[i])
            {
                ++hash[i];
                num[m]=i;
                ff(m+1);
                --hash[i];
            }
        }
    }
}
int main()
{
    while(~scanf("%d",&n))
        ff(0);
    return 0;
}
