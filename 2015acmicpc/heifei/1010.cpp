#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned ll
#define debug(x) cout << #x << " " << x << endl;
#define P pair <int, int>
using namespace std;

const int MAXN = 1e5+7;
const int INF = 2e9+7;
const double EPS = 1e-9;
P arr[MAXN];
vector <int> ans;
int main()
{
    vector <int> vec = {1, 2, 3};
    vec.insert(vec.begin() + 1, 9);
    for(auto it: vec) debug(it);
    int t;
    scanf("%d", &t);
    for(int I = 1; I <= t; ++I)
    {
        ans.clear();
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%d%d", &arr[i].first, &arr[i].second);
        sort(arr, arr + n);
        int num = 0;
        bool f = true;
        for(int i = n - 1; i >= 0; --i)
        {
            if(arr[i].second > num)
            {
                f = false;
                break;
            }
            //debug(ans[i]);
            /*int num1 = num, k = i;
            while(arr[i].second > 0 && arr[i].second < num1)
            {
                swap(ans[k], ans[k + 1]);
                num1--;
                k++;
            }*/
            if(arr[i].second > 0 && arr[i].second < num) ans.insert(ans.begin() + arr[i].second, arr[i].first);
            else ans.pb(arr[i].first);
            num++;
        }
        printf("Case #%d: ", I);
        if(!f) puts("impossible");
        else
        {
            for(int i = n - 1; i >= 0; --i)
                printf("%d%c", ans[i], i  != 0? ' ': '\n');
        }
    }
    return 0;
}

