#include <iostream>
#include <stdio.h>
using namespace std;
#define max 300010
int par[max];
int num[max];
void init(int n)
{
    for(int i=0;i<n;++i)
        par[i]=i;
}
int find(int x)
{
    if(par[x]==x)
        return x;
    return par[x]=find(par[x]);
}
void unite(int x,int y)
{
    x=find(x),y=find(y);
    if(x==y)
        return ;
    par[y]=x;
}
int main()
{
    //freopen("suspects.in","r",stdin);
    //freopen("suspects.out","w",stdout);
    int n,m,k;
    while(~scanf("%d%d",&n,&m))
    {
        init(n);
        for(int i=0;i<m;++i)
        {
            scanf("%d",&k);
            for(int j=0;j<k;++j)
            {
                scanf("%d",num+j);
                if(j>0)
                    unite(num[0],num[j]);
            }
        }
        int cnt=0;
        for(int i=1;i<n;++i)
            if(find(0)==find(i))
                ++cnt;
        printf("%d\n",cnt+1);
    }
    return 0;
}
