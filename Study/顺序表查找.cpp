#include <stdio.h>
int main()
{
    int arr[100];
    int n, key;
    int i;
    scanf("%d", &n);
    for(i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    scanf("%d", &key);
    for(i = 0; i < n; ++i)
        if(arr[i] == key)
            break;
    if(i < n)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
