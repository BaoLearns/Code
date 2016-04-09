#include <iostream>
#include <algorithm>
#include <vector>
#define LL long long
#define INF 1000000000000000005
using namespace std;
LL LLabs(LL n)
{
    return n > 0? n : -n;
}
int main()
{
    int n;
    while(cin >> n, n)
    {
        vector <LL> vec;
        vector <pair<LL, LL> > L;
        for(int i = 0; i < n; ++i)
        {
            LL e;
            cin >> e;
            vec.push_back(e);
        }
        int K = n / 2;
        LL ans = INF, num = 0;
        //枚举前一半
        for(int i = 0; i < (1 << K); ++i)
        {
            LL sum = 0, cnt = 0;
            for(int j = 0; j < K; ++j)
            {
                if(i >> j & 1)
                {
                    sum += vec[j];
                    cnt++;
                }
            }
            L.push_back(make_pair(sum, cnt));
            //只要前半部分的子集
            sum = LLabs(sum);
            if(ans > sum && cnt)
            {
                ans = sum;
                num = cnt;
            }
            else if(ans == sum && cnt)
                num = min(num, cnt);
        }
        sort(L.begin(), L.end());
        //枚举后一半
        for(int i = 0; i < (1 << (n - K)); ++i)
        {
            LL sum = 0, cnt = 0;
            for(int j = 0; j < n - K; ++j)
            {
                if(i >> j & 1)
                {
                    sum += vec[j + K];
                    cnt++;
                }
            }
            vector <pair<LL, LL> > :: iterator it = lower_bound(L.begin(), L.end(), make_pair(-sum, INF));
            vector <pair<LL, LL> > :: iterator it2 = it - 1;
            //在二分到的位置，取当前和前一个绝对值较小的一个
            if(LLabs(sum + it -> first) > LLabs(sum + it2 -> first)) it = it2;
            else if(LLabs(sum + it -> first) == LLabs(sum + it2 -> first))
            {
                if(it -> second > it2 -> second)
                    it = it2;
            }
            //前半部分和后半部分的子集绝对值之和
            LL S = LLabs(sum + it -> first);
            if(ans > S && cnt + it -> second)
            {
                ans = S;
                num = cnt + it -> second; 
            }
            else if(ans == S && cnt + it -> second)
                num = min(num, cnt + it -> second);
            //只要后半部分的子集
            S = LLabs(sum);
            if(ans > S && cnt)
            {
                ans = S;
                num = cnt;
            }
            if(ans == S && cnt)
                num = min(num, cnt);
        }
        cout << ans << " " << num << endl;
    }
    return 0;
}
