/*
#include <iostream>
#include <set>
#include <queue>
#define maxn 10005
#define IT set <int> :: iterator
using namespace std;
set <int> Set;
bool prim[maxn];
int main()
{
    for(int i = 2; i < maxn; ++i)
    {
        if(!prim[i])
        {
            Set.insert(i);
            for(int j = i; j < maxn; j += i)
                prim[j] = true;
        }
    }
    for(auto i : Set)
        cout << i << " ";
    cout << endl;
    int n;
    while(cin >> n, n)
    {
        int ans = 0;
        for(IT it1 = Set.begin(); it1 != Set.end(); ++it1)
        {
            if(*it1 > n) break;
            int sum = 0;
            for(IT it2 = it1; it2 != Set.end(); it2++)
            {
                sum += *it2;
                if(sum > n)
                    break;
                if(sum == n)
                {
                    ans++;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
*/
#include <iostream>
#include <set>
#include <queue>
#define maxn 100001
using namespace std;
bool prim[maxn];
set <int> Set;
int main()
{
    for(int i = 2; i < maxn; ++i)
    {
        if(!prim[i])
        {
            Set.insert(i);
            for(int j = i; j < maxn; j += i)
                prim[j] = true;
        }
    }
    int n;
    while(cin >> n, n)
    {
        int ans = 0;
        queue <int> que;
        for(set <int> :: iterator it1 = Set.begin(); it1 != Set.end(); ++it1)
        {
            int sum = *it1;
            for(set <int> :: iterator it2 = Set.begin(); it2 != Set.end(); ++it2)
            {
                que.push(*it2);
                if(sum > n)
                {
                    break;
                    while(que.size()) que.pop();
                }
                if(sum == n)
                {
                    ans++;
                    while(que.size())
                    {
                        cout << que.front() << " ";
                        que.pop();
                    }
                    cout << endl;
                    cout << "        _____" << sum << endl;
                }
                sum += *it2;
            }
        }
        cout << ans << endl;
        //cout << endl;
    }
    return 0;
}
