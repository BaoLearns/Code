#include <stdio.h>
#include <string.h>
int main()
{
    char a[15],b[1000010];
    int n1,n2,i,j,num=0,fal,n=0,pot=0;
    gets(a);
    gets(b);
    n1=strlen(a);
    n2=strlen(b);
    for(i=n2;i>=0;i--)
        b[i+1]=b[i];
    b[0]=32;
    for(i=1;i<=n2+1;i++)
    {
        fal=0;
        for(j=0;j<n1;j++)
        {
            if (b[i]==a[j] || b[i]==a[j]+32 ||b[i]==a[j]-32)
                i++,fal++;
        }
        if((fal==n1 && (b[i]==32||b[i]=='\0') && b[i-n1-1]==32))
            {
                num++;
                if(n==0) pot=i-n1,n++;
            }
    }
    if(num!=0)
        printf("%d %d\n",num,pot-1);
    else
        printf("-1\n");
    return 0;
}
