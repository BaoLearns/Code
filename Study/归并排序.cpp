//归并排序
#include <iostream>
#define MAXN 10007
using namespace std;
void Merge_sort(int arr[], int p, int q, int t[])
{
    if(q - p > 1)
    {
        int m = p + (q - p) / 2;
        Merge_sort(arr, p, m, t); //分解左半边
        Merge_sort(arr, m, q, t); //分解右半边
        int l = p, r = m, pos = p;
        while(l < m || r < q) //合并
        {
            if(r >= q || (arr[l] < arr[r] && l < m)) t[pos++] = arr[l++];
            else t[pos++] = arr[r++];
        }
        for(int i = p; i < pos; ++i) arr[i] = t[i];
    }
}
int main()
{
    int n, arr[MAXN], t[MAXN];
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    Merge_sort(arr, 0, n, t);
    for(int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
