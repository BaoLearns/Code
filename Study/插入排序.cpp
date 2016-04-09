#include <bits/stdc++.h>
#define maxn 1005
using namespace std;
int arr[maxn];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    for(int i = 1; i < n; ++i)
    {
        int k = i;
        for(int j = k - 1; j >= 0; --j)
        {
            if(arr[k] < arr[j])
            {
                swap(arr[k], arr[j]);
                k--;
            }
            else
                break;
        }
    }
    for(int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
