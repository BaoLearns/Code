#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define LL long long
using namespace std;
vector <LL> vec;
int main()
{
    LL n;
    while(scanf("%I64d", &n) != EOF)
    {
        vec.clear();
        queue <LL> que;
        LL ans = 0, l = 1, sum = 0, temp = 1;
        while((l - 1) * (l - 1) <= n)
        {
            while(sum < n)
            {
                sum += l * l;
                que.push(l);
                l++;
            }
            //cout << sum << "___" << endl;
            if(sum == n)
            {
                ans++;
                vec.push_back(que.size());
                while(que.size())
                {
                    vec.push_back(que.front());
                    que.pop();
                }
                vec.push_back(0);
            }
            if(que.front() == temp) que.pop();
            sum -= temp * temp;
            temp++;
        }
        if(ans)
            cout << ans << endl;
        for(vector <LL> :: iterator it = vec.begin(); it != vec.end(); ++it)
        {
            if(!*it)
                printf("\n");
            else
                printf("%I64d ", *it);
        }
    }
    return 0;
}
