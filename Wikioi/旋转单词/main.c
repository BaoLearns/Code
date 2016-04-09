#include <stdio.h>
#include <string.h>
int main()
{
    int m,i,j=0,n,x1,x2;
    char a[1000],b[1000];
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        for(j=0;a[j]!='\n';j++)
        scanf("%c",&a[j]);
        scanf("%d",&n);
        x1=strlen(a);
        x2=n%x1;
        for(i=x1-x2;i<x1;i++)
        {
            b[j]=a[i];
            a[i]='\0';
            j++;
        }
        printf("%s%s\n",b,a);
    }
    return 0;
}
