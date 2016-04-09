#include <iostream>
using namespace std;
int arr[25],n,k;
bool dfs(int i,int sum)
{
    if(i==n)
        return sum==k;
    if(dfs(i+1,sum))
        return true;
    if(dfs(i+1,sum+arr[i]))
        return true;
    return false;
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;++i)
        cin>>arr[i];
    dfs(0,0)?cout<<"Yes":cout<<"No";
    cout<<endl;
    return 0;
}
