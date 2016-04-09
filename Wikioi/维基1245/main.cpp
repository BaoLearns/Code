#include <iostream>
#include <algorithm>
#define max 100100
using namespace std;
int n,num=0;
int heap[max*10];
int arrA[max],arrB[max];
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>arrA[i];
    for(int i=0;i<n;++i)
        cin>>arrB[i];
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            heap[num++]=arrA[i]+arrB[j];
    sort(heap,heap+num);
    for(int i=0;i<n;++i)
        cout<<heap[i]<<' ';
    cout<<endl;
    return 0;
}
