/*#include <iostream>
#define MAXN 6001
using namespace std;
int hash[MAXN];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int e;
        cin >> e;
        hash[e]++;
    }
    int cnt = 0;
    for(int i = 1; i <= n; ++i)
    {
        while(hash[i] > 1)
        {
            for(int j = i + 1; j < MAXN; ++j)
                if(hash[j] == 0)
                {
                    hash[j]++;
                    cnt += j - i;
                    break;
                }
            hash[i]--;
        }
    }
    cout << cnt << endl;
    return 0;
}
*/
/*
#include <iostream>
#include <set>
#define MAXN 1000000
#define LL long long
using namespace std;
int s1[MAXN], s2[MAXN];
set <LL> Set;
bool cal(int st1, int en1, int st2, int en2)
{
    LL val = 0;
    for(int i = st1; i < en1; ++i)
        val = val * 10 + s1[i];
    val *= 10;
    for(int i = st2; i < en2; ++i)
        val = val * 10 + s2[i];
    cout << val << endl;
    if(Set.find(val) == Set.end())
    {
        Set.insert(val);
        return true;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    int k1, k2;
    cin >> k1;
    for(int i = 0; i < k1; ++i)
        cin >> s1[i];
    cin >> k2;
    for(int i = 0; i < k2; ++i)
        cin >> s2[i];
    int st1 = 0, st2 = 0, en1 = k1, en2 = k2;
    int cnt = 0;
    while(st1 != en1 && st2 != en2)
    {
        int a = s1[st1++], b = s2[st2++];
        if(a > b)
        {
            s1[en1++] = min(a, b);
            s1[en1++] = max(a, b);
            
        }
        else
        {
            s2[en2++] = min(a, b);
            s2[en2++] = max(a, b);
        }
        if(!cal(st1, en1, st2, en2))
        {
            cout << -1 << endl;
            return 0;
        }
        cnt++;
    }
    if(st1 == en1)
        cout << cnt << " " << 2 << endl;
    else 
        cout << cnt << " " << 1 << endl;
    return 0;
}
*/
/*
#include <iostream>
#include <cstring>
#define LL long long
#define MAXN 5000005
using namespace std;
bool prim[MAXN];
int arr[MAXN];
int dp[MAXN];
int Init()
{
    for(int i = 2; i * i < MAXN; ++i)
    {
        if(!prim[i])
        {
            for(int j = 2 * i; j < MAXN; j += i)
                prim[j] = true;
        }
    }
    int pos = 0;
    for(int i = 2; i < MAXN; ++i)
        if(!prim[i]) arr[pos++] = i;
    return pos;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int N = Init();
    for(int i = 2; i < MAXN; ++i)
    {
        if(dp[i] > 0) continue;
        int c = i, num = 0;
        for(int j = 0; j < N && c != 1; ++j)
        {
            while(c % arr[j] == 0)
            {
                num++;
                c /= arr[j];
            }
        }
        dp[i] = num;
        for(int j = 0; j < N && i * arr[j] < MAXN; ++j)
            dp[i * arr[j]] = num + 1;
        //cout << i << endl;
    }
    dp[1] = 1;
    for(int i = 2; i < MAXN; ++i)
    {
        int c = i, num = 0;
        for(int j = 2;c != 1;j++)
        {
            while(c % j == 0)
            {
                num++;
                c /= j;
            }
        }
        dp[i] = num;
    }
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        LL cnt = 0;
        for(int i = b + 1; i <= a; ++i)
            cnt += dp[i];
        cout << cnt << endl;
    }
    return 0;
}
*/
/*
#include <iostream>
#include <cstring>
#define LL long long
#define MAXN 5000005
using namespace std;
bool prim[MAXN];
int arr[MAXN];
int dp[MAXN];
int Init()
{
    for(int i = 2; i * i < MAXN; ++i)
    {
        if(!prim[i])
        {
            for(int j = 2 * i; j < MAXN; j += i)
                prim[j] = true;
        }
    }
    int pos = 0;
    for(int i = 2; i < MAXN; ++i)
        if(!prim[i]) arr[pos++] = i;
    return pos;
}
int main()
{
    std::ios::sync_with_stdio(false);
    memset(dp, 0, sizeof(dp));
    int N = Init();
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        LL cnt = 0;
        for(int i = b + 1; i <= a; ++i)
        {
            if(dp[i] > 0) continue;
            int c = i, num = 0;;
            for(int j = 0; j < N && c != 1; ++j)
            {   
                while(c % arr[j] == 0)
                {
                    c /= arr[j];
                    num++;
                }
            }
            dp[i] = num;
            for(int j = 0 ; j < N && arr[j] * i <= a; ++j)
                dp[arr[j] * i] = num + 1;
        }
        for(int i = b + 1; i <= a; ++i)
            cnt += dp[i];
        cout << cnt << endl;
    }
    return 0;
}*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string ch[5];
        for(int i = 0; i < 5; ++i)
            cin >> ch[i];
        for(int i = 0; i < 5; ++i)
        {
            if(ch[i].size() > 2)
                ch[i][1] = (ch[i][1] - '0') * 10 + ch[i][2] - '0';
            else
                ch[i][1] = ch[i][1] - '0';
        }
        int ans = 100000;
        for(int i = 0; i < 4; ++i)
        {
            int num1 = 0, num2 = 0, num3 = 0;
            for(int j = 0; j < 5; ++j)
                if(ch[j][0] != 'A' + i) num1++;
            for(int j = 1; j < 5; ++j)
            {
                int a = abs(ch[j][1] - ch[j - 1][1]);
                num1 += a - 1;
            }
            num3 += abs(ch[0][1] - 10) - 1;
            num3 += abs(ch[0][1] - 11) - 1;
            num3 += abs(ch[0][1] - 12) - 1;
            num3 += abs(ch[0][1] - 13) - 1;
            num3 += abs(ch[0][1] - 1) - 1;
            ans = min(ans, num1 + min(num2, num3));

        }
        cout << ans << endl;
    }
    return 0;
}
