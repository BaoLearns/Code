#include <stdio.h>

int erfen(int *s,int val,int l,int r)
{
    if(l<r)
    {
        int mid=l+(r-l)/2;
        if(s[mid]==val)
            return mid;
        if(s[mid]>val)
            erfen(s,val,l,r-1);
        else
            erfen(s,val,l+1,r);
    }
    return -1;
}
int main()
{
    int s[10]={0,1,2,3,4,5,6,7,8,9};
    int val;
    while(scanf("%d",&val))
    {
        printf("%d\n",erfen(s,val,0,9)==-1?-1:erfen(s,val,0,9));

    }
    return 0;
}
