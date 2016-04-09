#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int T;
    cin >> T;
    for(int I = 1; I <= T; ++I)
    {
        printf("Case #%d:\n", I);
        int n, m;
        scanf("%d%d", &n, &m);
        if(n > m) swap(n, m);
        int q;
        scanf("%d", &q);
        while(q--)
        {
            putchar('\n');
        }
    }
    return 0;
}
