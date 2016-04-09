
//给你一个有序的数列arr，有n个值
//给你一个k
//在这n个序列中找到找到一个最小的i使arr[i]>=k
//找到输出i，没找到输出n
#include <stdio.h>
#include <stdlib.h>
#define max 10000
int arr[max];
int main()
{
    int n,k,i;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;++i)
        scanf("%d",arr+i);
    //这样处理是方便没有找到的情况
    //也可以先判断数列的最大的元素与k比较
    int l=-1,r=n;
    //当r-l>1的时候就一直找
    while(r-l>1)
    {
        int mid=l-(l-r)/2;
        if(arr[mid] >= k)
            r = mid;
        else
            l = mid;
    }
    printf("%d\n",r);
    return 0;
}
