
//求一个区间最大的连续和
#include <iostream>
#include <algorithm>
#define MAXN 100007
using namespace std;
int MaxSum(int arr[], int l, int r)
{
    if(r - l <= 1) return arr[l];
    int m = l + (r - l) / 2;
    int Max = max(MaxSum(arr, l, m), MaxSum(arr, m, r)); //分治找到左边部分，右边部分的最大和
    int MaxL = arr[m - 1], MaxR = arr[m];
    for(int i = m - 1, v = 0; i >= l; --i)//求出左边连续的最大和
    {
        v += arr[i];
        MaxL = max(MaxL, v);
    }
    for(int i = m, v = 0; i < r; ++i) //求出右边连续的最大和
    {
        v += arr[i];
        MaxR = max(MaxR, v);
    }
    return max(Max, MaxL + MaxR); //返回分治找到的最大和，左边加上右边做大连续和的最大值
}
int main()
{
    int n, arr[MAXN];
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    int sum = MaxSum(arr, 0, n);
    cout << sum << endl;
    return 0;
}
