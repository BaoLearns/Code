#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define debug(x) cout << #x << " " << x << endl;

using namespace std;

const int MAXN = 1e5;
const int INF = 2e9;
const double EPS = 1e-9;

int solve(int n, int cnt, int val, bool f, int arr[]) //f == true l ->  r
{
	//debug(cnt);
	if(f)
	{
		for(int i = 0; i < n; ++i)
		{
			if(arr[i] <= val)
			{
				cnt--;
				val++;
				arr[i] = 2e9;
			}
		}
	}
	else
	{
		for(int i = n - 1; i >= 0; --i)
		{
			if(arr[i] <= val)
			{
				cnt--;
				val++;
				arr[i] = 2e9;
			}
		}
	}
	if(cnt > 0)
		return 1 + solve(n, cnt, val, f == false? true: false, arr);
	return 0;
}
int main()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; ++i)
		cin >> arr[i];
	cout << solve(n, n, 0, true, arr) << endl;
	return 0;
}
