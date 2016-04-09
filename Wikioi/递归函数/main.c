#include <stdio.h>
int  main()
{
    int a[101][101]={0};
    int n,i,j,num,s=0;
    scanf("%d",&n);
    a[i=n-1][j=n-1]=n*n;
    num=n*n;
    while (num>1)
    {
        while (j-1>=0&&!a[i][j-1]) a[i][--j]=--num;
        while (i-1>=0&&!a[i-1][j]) a[--i][j]=--num;
        while (j+1<n&&!a[i][j+1]) a[i][++j]=--num;
        while (i+1<n&&!a[i+1][j]) a[++i][j]=--num;
    }
    for(i=0;i<n;i++)
        {for(j=0;j<n;j++)
            printf("%d ",a[i][j]);
            printf("\n");
        }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    if(i==j||i+j==n) s=s+a[i][j];
    printf("%d",s);
    return 0;
}
