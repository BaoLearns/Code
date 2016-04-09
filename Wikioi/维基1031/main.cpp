#include <iostream>
using namespace std;
int arr[20]={0};
int n;
void dfs(int m)
{
    if( m== n)
    {
        for( int i =0; i < n ; ++i )
            printf("%d ",arr[i]);
        putchar('\n');
    }
    for( int i = 1;  i <= n; ++i)
    {
        if(arr[0]==0)
            arr[m++]=i;
        else
        {
            int e=arr[m] + i;
            for(int j = 2; j < e; ++j)
            {
                if( e % j == 0)
                return ;
            }
            dfs(m+1);
    }
}
int main()
{
    scanf("%d", &n);
    dfs(0);
    return 0;
}
