/*
#include <iostream>
#include <algorithm>
#include <vector>
#define LL long long
#define MAX 10000001
using namespace std;
vector <LL> vec;
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n, s;
        cin >> n >> s;
        vec.clear();
        vec.push_back(0);
        for(int i = 0; i < n; ++i)
        {
            LL e;
            cin >> e;
            vector <LL> :: iterator it = vec.begin() + i;
            vec.push_back(*it + e);
        }
        vec.erase(vec.begin());
        //for(auto i : vec)
            //cout << i << " ";
        if(*vec.end() < s) 
        {
            cout << 0 << endl;
            continue;
        }
        vector <LL> :: iterator it = vec.begin();
        int ans = MAX;
        while(*it + s < *(vec.end()))
        {
            int t = lower_bound(it, vec.end(), *it + s) - vec.begin();
            int cnt = t - (it - vec.begin());
            ans = min(ans, cnt);
            it++;
            if(ans == 0) 
            {
                cout << t << " " << cnt << endl;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define LL long long
#define IT vector <LL> :: iterator
#define MAX 10000001
using namespace std;
vector <LL> vec;
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        vec.clear();
        int n, s;
        cin >> n >> s;
        LL Sum = 0;
        for(int i = 0; i < n; ++i)
        {
            LL e;
            cin >> e;
            Sum += e;
            vec.push_back(e);
        }
        if(Sum < s) 
        {
            cout << 0 << endl;
            continue;
        }
        LL sum = 0;
        int ans = MAX;
        IT be = vec.begin(), ed = vec.begin();
        while(true)
        {
            while(ed != vec.end() && sum < s)
            {
                sum += *ed;
                ed++;
            }
            //cout << sum << "!!!" << endl;
            if(sum < s)
                break;
            int t = ed - be;
            ans = min(ans, t);
            sum -= *be;
            be++; 
        }
        cout << ans << endl;
    }
    return 0;
}
/*
2
10 15
5 1 3 5 10 7 4 9 2 8
5 11
1 2 3 4 5
*/
