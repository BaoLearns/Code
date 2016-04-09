#include <cstdio>
int main()
{
    freopen("factor.in","r",stdin);
    freopen("factor.out","w",stdout);
    long long n;
    while(~scanf("%lld",&n))
    {
        for(int i = 2;n != 1;++i)
        {
            if(n%i==0)
            {
                printf("%d ",i);
                while(n%i==0)
                    n/=i;
            }
        }
        putchar('\n');
    }
    return 0;
}
