#include <stdio.h>
int main()
{
    int n, x = 0, arr[101];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    for(int i = 0; i < n; ++i)
        x ^= arr[i];
    int num;
    for(int i = 0;; ++i)
    {
        if(x >> i & 1) 
        {
            num = i;
            break;
        }
    }
    int a1[101], a2[101], pos1 = 0, pos2 = 0;
    for(int i = 0; i < n; ++i)
    {
        if(arr[i] >> num & 1) a1[pos1++] = arr[i];
        else a2[pos2++] = arr[i];
    }
    x = 0;
    for(int i = 0; i < pos1; ++i)
        x ^= a1[i];
    printf("%d\n", x);
    x = 0;
    for(int i = 0; i < pos2; ++i)
        x ^= a2[i];
    printf("%d\n", x);
    return 0;
}
