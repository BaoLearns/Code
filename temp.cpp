#include <iostream>

using namespace std;

void qsort(int *arr, int L, int R, int val, int cnt)
{
    int l = L, r = R;
    while(l < r)
    {
        while(l < r && arr[r] >= val) r--;
        while(l < r && arr[l] < val) l++;
        swap(arr[l], arr[r]);
    }
    if(cnt) qsort(arr, l, R, val + 1, cnt - 1);
}

void show(int *arr, int n)
{
    for(int i = 0; i < n; ++i)
        cout << arr[i] << (i < n - 1? " ": "\n");
}

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    int val;
    cin >> val;
    qsort(arr, 0, n - 1, val, 1);
    cout << "resule:" << endl;
    show(arr, n);
    return 0;
}
