//给你很多条边，选三条边组成最长的周长

#include <iostream>
#include <algorithm>
using namespace std;
#define max 1010
int arr[ max];
int main()
{
    int n;
    int falg=0,c=0;
    cin>>n;
    for(int i = 0;i < n; ++i)
        cin>>arr[i];
    sort( arr, arr + n);
    for(int i = n - 1;i >= 0 && !falg; --i)
    {
        for(int j = i -1;j >= 0 && !falg; --j)
        {
            for(int k = j-1; k >= 0 && !falg; -- k)
            {
                if(arr[i] < arr[j] + arr[k])
                {
                    c=arr[i]+arr[j]+arr[k];
                    falg=1;
                }
            }
        }
    }
    cout<<c<<endl;
    return 0;
}
