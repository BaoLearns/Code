#include <stdio.h>
#include <stdlib.h>
int arr[10];
int main()
{
    int size=10;
    int rear=0,front=0;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int m;
        scanf("%d",&m);
        if(m==1)
        {
            scanf("%d",&arr[rear++]);

        }
        else
            ++front;



    }

    return 0;
}
