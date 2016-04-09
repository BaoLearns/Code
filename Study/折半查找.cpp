#include <stdio.h>
int main()
{
    int n, i, arr[100];
    scanf("%d", &n);
    for( i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);
    int key;
    scanf("%d", &key);
    int low = 1, high = n;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(arr[mid] == key)
        {
            printf("YES\n");
             break;
         }
        else if(arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if(low > high)
        printf("NO\n");
    return 0;
}
