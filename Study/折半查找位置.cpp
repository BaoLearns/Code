#include <bits/stdc++.h>
#define maxn 1005
using namespace std;
int arr[maxn];
int *binarserch(int *arr, int n, int key)
{
    int *low = arr, *high = arr + n - 1;
    while(low < high)
    {
        int *mid = low + (high - low) / 2;
        if(*mid >= key)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr, arr + n);
    int key;
    while(cin >> key)
    {
        int *pos = binarserch(arr, n, key);
        cout << pos - arr << endl;
    }
    return 0;
}
