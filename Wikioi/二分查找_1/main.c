#include <stdio.h>
#include <stdlib.h>
int erfen(int *s,int n,int l,int r)
{
     while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(n==s[mid])
            return mid;
        if(n<s[mid])
            r=mid-1;
        else
            l=mid+1;

    }
    return 0;
}
int main()
{
    int s[11]={0,1,2,3,4,5,6,7,8,9,10};
    printf("����������ҵ�����");
    int n;
    while(scanf("%d",&n))
    {
        int pos=erfen(s,n,1,10);
        if(pos)
            printf("�������λ����%d\n",pos);
        else
            printf("�������������\n");
    }
    return 0;
}
