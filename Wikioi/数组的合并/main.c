#include <stdio.h>
#include <stdlib.h>
int len(int *n)
{
    int m=0;
    while (*n++!=0)
    m++;
    return m;
}
int main()
{
    int s[100]={1,2,3,4,5,6,7},t[100]={1,2,5,4,8,9,10,25,48,45,64,545,545,415,2,5,4,8};
    int n=len(s),m=len(t);
    int i,j;
    for(i=0;i<m;i++)
    {
        int k=1;
        for(j=0;j<n;j++)
            {
                if(t[i]==s[j])
                k=0;
                break;
            }
        if(k) s[n++]=t[i];
    }
    printf("%d\n",n);
    for(i=0;i<n;i++)
        printf("%d ",s[i]);
    putchar('\n');
    return 0;
}
