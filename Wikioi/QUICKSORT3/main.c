#include <stdio.h>
#include <stdlib.h>
int prition(int s[],int p,int r)
{
    int i=p,j=r,t,x=s[p];
    while (i<j)
    {
        while (s[j] > x)
            i++;
        while (s[i] < x)
            j--;
        t=s[i],s[i]=s[j],s[j]=t;
    }
    return i;
}
void quicksort(int s[],int p,int r)
{
    if(p<r)
    {
        int q=prition(s,p,r);
        quicksort(s,p,q-1);
        quicksort(s,q+1,r);
    }
}
int main()
{
    int s[10]={1,4,7,8,5,2,3,6,98,0};
    quicksort(s,0,9);
    int i;
    for(i=0;i<10;i++)
        printf("%d ",s[i]);
    return 0;
}
