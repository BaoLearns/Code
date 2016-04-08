#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector <int> vec;
    int ans = 0, MAX = 0;
    for(int i = 0; i < n; ++i)
    {
        int e;
        cin >> e;
        ans += e / 10;
		vec.pb(10 - e % 10);
		MAX += (100 - e) / 10 + 1;
		if(e % 10 == 0) MAX--;
    }
    sort(vec.begin(), vec.end());
	int cnt = 0;
    for(int i = 0; i < vec.size() && vec[i] <= k; ++i)
    {
        cnt++;
        k -= vec[i];
    }
	if(k > 0) cnt += k / 10;
	cout << ans << " " << cnt << " " << MAX << endl;
    cout << ans + min( cnt, MAX)  << endl;
    return 0;
}
