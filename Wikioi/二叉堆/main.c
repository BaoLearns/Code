#include <stdio.h>
int arr[10000];
int size=0;
int sum=0;

void Pop(int i)
{
    int t=arr[i];
    int j=i/2;
    while(j>=1 && i!=1)
    {
        if(arr[j]<=t)
            break;
        arr[i]=arr[j];
        i=j;
        j=i/2;
    }
    arr[i]=t;
    return ;
}

int Push()
{
    int e=arr[1];
    arr[1]=arr[size--];
    int t=arr[1];
    int i=1;
    int j=i*2;
    while(j<=size)
    {
        if(j+1<=size && arr[j] > arr[j+1])
            ++j;
        if(arr[j] > t)
            break;
        arr[i]=arr[j];
        i=j;
        j=i*2;

    }
    arr[i]=t;
    return e;
}
int main()
{
    int n,i,val;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        ++size;
        scanf("%d",arr+i);
        Pop(i);
    }
    int a,b;
    while(size > 1)
    {

        a=Push();
        b=Push();
        arr[++size]=a+b;
        Pop(size);
        sum=sum+a+b;
    }
    printf("%d\n",sum);
    return 0;
}
