#include <stdio.h>
#include <string.h>
int main()
{
    char a[11],b[11]={'\0'};
    int i,j,m,c;
    gets(a);
    if(a[0]==48 && strlen(a)==1)
        printf("0\n");
    else
    {
    if(a[0]=='-')
        i=1,b[0]='-';
    else
        i=0;
    for(j=strlen(a)-1;i<strlen(a) && j>=0;j--,i++)
        b[j]=a[i];
    if(a[0]=='-')
        m=1;
    else
        m=0;
    c=strlen(b);
    for(i=0;i<strlen(a);i++)
    {
        if(b[m]=='0')
        {
        for(j=m;j<c-1;j++)
            b[j]=b[j+1];
            b[j+1]='\0';
            c=strlen(b);
        }
    }

    for(i=0;i<strlen(b);i++)
        printf("%c",b[i]);
    printf("\n");
    }
    return 0;
}
