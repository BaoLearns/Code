#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, k, num[1025];
        cin >> n >> k;
        for(int i = 0; i < n; ++i)
            scanf("%d", &num[i]);
        while(k > 0)
        {
            while(next_permutation(num, num + n))
            {
                k--;
                if(k == 0)
                {
                    for(int i = 0; i < n; ++i) printf("%d ", num[i]);
                    putchar('\n');
                    break;
                }
            }
            sort(num, num + n);
            if(--k == 0)
            {
                for(int i = 0; i < n; ++i) printf("%d ", num[i]);
                putchar('\n');
                break;
            }
        }
    }
    return 0;
}

