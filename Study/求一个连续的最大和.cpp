
//��һ����������������
#include <iostream>
#include <algorithm>
#define MAXN 100007
using namespace std;
int MaxSum(int arr[], int l, int r)
{
    if(r - l <= 1) return arr[l];
    int m = l + (r - l) / 2;
    int Max = max(MaxSum(arr, l, m), MaxSum(arr, m, r)); //�����ҵ���߲��֣��ұ߲��ֵ�����
    int MaxL = arr[m - 1], MaxR = arr[m];
    for(int i = m - 1, v = 0; i >= l; --i)//����������������
    {
        v += arr[i];
        MaxL = max(MaxL, v);
    }
    for(int i = m, v = 0; i < r; ++i) //����ұ�����������
    {
        v += arr[i];
        MaxR = max(MaxR, v);
    }
    return max(Max, MaxL + MaxR); //���ط����ҵ������ͣ���߼����ұ����������͵����ֵ
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
