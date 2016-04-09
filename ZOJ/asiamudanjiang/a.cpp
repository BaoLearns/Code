#include <iostream>
#define MAXN 51
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, arr[MAXN];
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        int cnt = 0;
        for(int i = 1; i < n - 1; ++i)
            if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
                cnt++;
        cout << cnt << endl;
    }
    return 0;
}
