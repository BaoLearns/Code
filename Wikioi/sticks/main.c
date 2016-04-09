#include <stdio.h>
#include <stdlib.h>
int main()
{
    //freopen("sticks.in","r",stdin);
    //freopen("sticks.in","w",stdout);
    int n,x,s,i,max;
    while(~scanf("%d",&n))
    {
        s=max=0;
        for(i=0;i<n;++i)
        {
            scanf("%d",&x);
            max=max>x?max:x;
            s+=x;
        }
        for(i=max;;++i)
        {
            if(s%i==0)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
