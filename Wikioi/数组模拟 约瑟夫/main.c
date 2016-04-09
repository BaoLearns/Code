#include <stdio.h>
int main()
{
    int n,m,l;
    scanf("%d%d",&n,&m);
    l=n;
    int s[n];
    int i;
    for(i=0;i<n;i++)
        s[i]=i+1;
    int cnt=1;
    i=0;
    while(l)
    {
        if(cnt==m &&s[i]!=0)
        {
            //i=i%n;
            printf("%d ",s[i]);
            s[i]=0;
            cnt=1;
            l--;
        }
        if(s[n]!=0) cnt++;
        if(cnt==m &&s[i]!=0)
        {
            //i=i%n;
            printf("%d ",s[i]);
            s[i]=0;
            cnt=1;
            l--;
        }
        i=(i+1)%n;
    }
    /*for(i=0;i<n;i++)
        if(s[i]) printf("%d\n",s[i]);*/
    return 0;
}
