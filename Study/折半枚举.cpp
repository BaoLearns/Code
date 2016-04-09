#include <iostream>
#include <vector>
#include <algorithm>
#define maxn 100005
using namespace std;
int arr[35];
int SUM, n;
vector <int> sum1, sum2;
void read()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    cin >> SUM;
}
void solve()
{
    int K = n / 2;
    for(int i = 0; i < (1 << K); ++i)
    {
        int sum = 0;
        for(int j = 0; j < K; ++j)
        {
            if((i >> j) & 1) sum += arr[j];
        }
        sum1.push_back(sum);
    }
    sort(sum1.begin(), sum1.end());
    for(auto i: sum1) cout << i << endl;
    for(int i = 0; i < n - K; ++i)
    {
        int sum = 0;
        for(int j = 0; j < n - K; ++j)
            if(i >> j & 1) sum += arr[j];
        //int pos = lower_bound(sum1.begin(), sum1.end(), SUM - sum);
        
    }
}
int main()
{
    read();
    solve();
    return 0;
}
