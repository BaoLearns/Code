#include <stdio.h>
#define max 1010
int pre[max];
int n,m;
void Init(int m)
{
    for(int i=1;i<=m;++i)
        pre[i]=i;
}
int Find(int x)
{
    return pre[x]==x?x:Find(pre[x]);
}
void Union(int x,int y)
{
    int fx=Find(x),fy=Find(y);
    if(fx==fy)
        return ;
    pre[fx]=fy;
    --n;
}
int main()
{
    while(scanf("%d%d",&n,&m) && n && m)
    {
        Init(n);
        int x,y;
        for(int i=0;i<m;++i)
        {
            scanf("%d%d",&x,&y);
            Union(x,y);
        }
        printf("%d\n",n-1);
    }
    return 0;
}
