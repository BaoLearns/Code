#include <stdio.h>
void ff(int s[],int n)
{
    int i;
    for(i=1;i<=n;i++)
            s[i]=i;
    return ;
}
int main()
{
    int n;
    while(scanf("%d",&n))
    {
        int s[n+1],i,num=n;
        ff(s,n);
        int j;
        for(j=1;j<=n;j++)
            printf("%d ",s[j]);
        putchar('\n');
        int min,c=1;
        for(min=2;c;min++)
        {
            i=1;
            while(num>1)
            {
                i=i%n;
                if(s[i] && i %min==0)
                    {
                        s[i]=0;
                        num--;
                    }
                    if(!s[2]) break;
                i++;
            }
            for(j=1;j<=n;j++)
            printf("%d ",s[j]);
            putchar('\n');
            if(s[2]) printf("%d\n",min),c=0;
            else ff(s,n);
        }
    }

    return 0;
}
