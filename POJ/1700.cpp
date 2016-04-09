#include <iostream>
#include <algorithm>
#define MAXN 1005
using namespace std;
int arr[MAXN];
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        sort(arr, arr + n);
        if(n == 1)
            cout << arr[0] << endl;
        else if(n == 2)
            cout << arr[1] << endl;
        else
        {
            int i, sum = 0;
            for(i = n - 1; i > 2; i -= 2)
                sum += min(arr[0] + 2 * arr[1] + arr[i], 2 * arr[0] + arr[i] + arr[i - 1]);
            if(i == 2) sum += arr[0] + arr[1] + arr[2];
            else if(i == 1) sum += arr[1];
            else sum += arr[0];
            cout << sum << endl;
        }
    }
    return 0;
}
/*
9
1 45 46 47 48 49 50 51 52
4
1 5 2 10
3
1 5 10
4
1 50 50 100
*/
