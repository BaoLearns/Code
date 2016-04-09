#include <stdio.h>
int main()
{
    char a[]={"hello!"};
    char b[10];
    int i,n,j=0;
    char *p=a;
    scanf("%d",&n);
    for(i=5;i>n;i--)
        b[j++]=a[i];
    for (i=0;i<6;i++)
    {
        if(i+n<6) a[i+n]=p[i];
        else  a[i+n-6]=b[j--];
    }
    for(i=0;i<6;i++)
        printf("%c",a[i]);
    printf("\n");
    return 0;
}
