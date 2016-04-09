
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int arr[100];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", arr + i);
    sort(arr, arr + n);
    for(int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    putchar('\n');
    int x, y;
    while(scanf("%d%d", &x, &y) != EOF)
    {
        int e = upper_bound(arr, arr + n, y) - lower_bound(arr, arr + n, x);
        printf("%d\n", e);
    }
    return 0;
}