#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define max 100000
int hash[max];
int main()
{
    int n,m,x;
    while(~scanf("%d",&n))
    {
        while(n--)
        {
            int flag=1;
            memset(hash,0,sizeof(hash));
            scanf("%d",&m);
            for(int i=0;i<m;++i)
            {
                scanf("%d",&x);
                hash[x]++;
            }
            for(int i=0;i<max;++i)
            {
                if(hash[i])
                {
                    for(int j=hash[i];j>0;--j)
                    {
                        if(flag)
                        {
                            printf("%d",i);
                            flag=0;
                        }
                        else
                            printf(" %d",i);
                    }
                }
            }
            putchar('\n');
        }
    }
    return 0;
}
