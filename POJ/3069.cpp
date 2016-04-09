#include <iostream>
#include <algorithm>
#define maxn 1010
using namespace std;
int arr[maxn];
int main()
{
    int r, n;
    while(cin >> r >> n )
    {
        if(r == n && n == -1) break;
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        sort(arr, arr + n);
        int ans = 0;
        int i = 0;
        while(true)
        {
            int s = arr[i] + r;
            while(i < n && arr[i] <= s) i++;
            int p = arr[i - 1] + r;
            while(i < n && arr[i] <= p) i++;
            ans++;
        }
        cout << ans << endl;
        
    }
    return 0;
}
