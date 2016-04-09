#include <cstdio>
#include <algorithm>
#define LL long long
using namespace std;
int main()
{
    int n, s;
    scanf("%d%d", &n, &s);
    LL cost = 0, Min = 1000001;
    for(int i = 0; i < n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        Min = Min < x?(Min < x + i * s? Min: x + i * s): (x < x + i * s? x: x + i * s);
        cost += Min * y;
    }
    printf("%lld\n", cost);
    return 0;
}
