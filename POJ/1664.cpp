#include <iostream>
#include <algorithm>
#include <set>
#define LL long long
using namespace std;
set <LL> Set;
int arr[15];
int dfs(int dep, int num, int m, int val)
{
    if(dep == num + 1)
    {
        LL v = 0;
        //sort(arr, arr + dep);
        //sort(arr + 1, arr + dep);
        for(int i = 1; i < dep; ++i)
            v = v * 10 + arr[i];
        if(m == 0 && Set.find(v) == Set.end())
        {
            //for(int i = 1; i < dep; ++i) cout << arr[i] << " ";
            //cout << v << "    dsfagsd" << val << endl;
            Set.insert(v);
            return 1;
        }
        //cout << val << "     " << v << endl;
        return 0;
    }
    int cnt = 0;
    for(int i = 1; i <= m - (num - dep); ++i)
    {
        arr[dep] = i;
        cnt += dfs(dep + 1, num, m - i, val * 10 + i);
    }
    return cnt;
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int m, n;
        cin >> m >> n;
        int sum = 0;
        Set.clear();
        for(int i = 1; i <= n; ++i)
            sum += dfs(1, i, m, 0);
        cout << sum << endl;
    }
    return 0;
}
