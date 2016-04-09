#include <stdio.h>
#include <math.h>
struct ss
{
    int x;
    int y;
}s[100];
int ff(int n,struct ss s[],int i,int j)
{
    int k,m,a,b,c,d,f;
    d=sqrt(pow((s[i].x-s[j].x),2)+pow((s[i].y-s[j].y),2));
    a=(-d*(s[i].x-s[j].x))/2+s[i].x;
    b=((s[j].y-s[i].y)/(s[i].x-s[j].x))*a+s[i].y;
    c=(-d*(s[j].x-s[i].x))/2+s[j].x;
    f=((s[i].y-s[j].y)/(s[j].x-s[i].x))*c+s[j].y;
    for(k=i+1;i<n;i++)
    {
        for(m=k+1;m<n;m++)
            if(a==s[k].x&&b==s[k].y && c==s[m].x&&f==s[m].y)
            return 1;
    }
    return 0;
}
int main()
{
    int i,j,n,t=0;
    while(scanf("%d",&n))
    {
    for(i=0;i<n;i++)
        scanf("%d%d",&s[i].x,&s[i].y);
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
            if(ff(n,s,i,j)) t++;
    }
    printf("%d\n",t/4);
    return 0;
}
