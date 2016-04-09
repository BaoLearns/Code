#include <stdio.h>
int rear=0,front=0;
int main()
{
    int s[1010];
    int chi,n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&chi);
        if(chi==1) scanf("%d",s+rear++);
        else front++;
    }
    if(front==rear) printf("impossible!\n");
    else printf("%d\n",s[front]);
    return 0;
}
