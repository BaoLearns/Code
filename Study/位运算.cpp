/*#include <cstdio>
#include <bits/stdc++.h>
#define maxn 0xfff
#define M 0101
using namespace std;
int main()
{
    cout << M << endl;
    cout << maxn << endl;
    printf("%d\n", 105 << 2);
    long long  m = 1 << 21;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        int e;
        scanf("%d", &e);
        m ^= (1 << e);   
    }
    for(int i = 0; i < 21; ++i)
    {
        if((m >> i) & 1 == 1)   
            printf("%d ",i);
    }
    int a = 1, b = 2;
    a ^= b;
    b ^= a;
    a ^= b;
    printf("%d %d\n", a, b);
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    set <int > Set;
    int num = 1 << 30;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int e;
        cin >> e;
        num |= 1 << e;
    }
    for(int x = num; x; x = (x - 1) & num)
    {
        int val = 0;
        for(int i = 0; i < 10; ++i)
        {
            if(x >> i & 1)
            {
                val = val * 10 + i;
            }
        }
        if(val)
            Set.insert(val);
    }
    for(auto i : Set)
        cout << i << endl;
    return 0;
}
