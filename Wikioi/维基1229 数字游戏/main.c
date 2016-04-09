#include <stdio.h>
#include <stdlib.h>
#define max 1000000
int hash[max];
int n,x,k,c;
int find(int ans,int m)
{
    int i;
    if(n==m)
    {
        if((ans+x)%k==0)
            c=ans;
    }
    for(i=0;i<10;++i)
    {
        if(hash[i])
        {
            hash[i]--;
            if(!c)
                find(ans*10+i,m+1);
            hash[i]++;
        }
    }
}
int main()
{
    int m,i,y;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;++i)
    {
        scanf("%d",&y);
        hash[y]++;
    }
    for(i=0;i<m;++i)
    {
        scanf("%d%d",&x,&k);
        c=0;
        find(0,0);
        c?printf("%d\n",c):printf("None\n");
    }
    return 0;
}
