#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    //freopen("cd.in","r",stdio);
    //freopen("cd.out","w",stdout);
    int T,ans;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if(m<13)
        {
            ans=n/m;
            if(n%m>0)
                ans++;
        }
        else if(m==13)
        {
            ans=n/12;
            if(n%12>0)
                ans++;
        }
        else
        {
            ans=n/m;
            if(n%m>0)
                ans++;
            if(n%m==13)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
