
//����һ�����������arr����n��ֵ
//����һ��k
//����n���������ҵ��ҵ�һ����С��iʹarr[i]>=k
//�ҵ����i��û�ҵ����n
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
    //���������Ƿ���û���ҵ������
    //Ҳ�������ж����е�����Ԫ����k�Ƚ�
    int l=-1,r=n;
    //��r-l>1��ʱ���һֱ��
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
