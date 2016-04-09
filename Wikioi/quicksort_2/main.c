#include <stdio.h>
int findpos(int *s ,int l,int r)//≤È’“Œª÷√
{
    int val=s[l];
    while(l<r)
    {
        while (l<r && s[r]>val)
            --r;
        s[l]=s[r];
        while(l<r && s[l]<val)
            ++l;
        s[r]=s[l];
    }
    s[l]=val;
    return l;
}
void quicksort(int *s,int l,int r)
{
    if(l<r)
    {
        int pos=findpos(s,l,r);
        quicksort(s,l,pos-1);
        quicksort(s,pos+1,r);
    }
}
int main()
{
    int s[10]={4,5,0,1,-2,3,6,8,7,-9};
    quicksort(s,0,9);
    int i;
    for(i=0;i<10;++i)
        printf("%d ",s[i]);
    printf("\n");
    return 0;
}
