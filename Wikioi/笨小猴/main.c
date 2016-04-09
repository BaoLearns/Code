#include <stdio.h>
#include <string.h>
int main()
{
    char s[110];
    int i,j,m,n,fal=0,num=0;
    int b[26]={0};
    gets(s);
    for(i=0;i<strlen(s);i++)
        for(j=0;j<26;j++)
    if(s[i]==j+97) b[j]++;
    m=n=0;
    for(i=0;i<26;i++)
        if(b[i]!=0) num++;
    for(i=0;i<26;i++)
    {
        if(m<b[i]) m=b[i];
        if(b[i]!=0&&num!=1)
        {
            if(fal==0)
            n=b[i],fal++;
            if(n>b[i]) n=b[i];
        }
    }
    if(m-n>1)
    {
        for(i=2;i<=(m-n);i++)
        if((m-n)%i==0) break;
    if(i>=(m-n))
    printf("Lucky Word\n%d\n",m-n);
    else
    	printf("No Answer\n0\n");
    }
    else
    printf("No Answer\n0\n");
    printf("%d   %d\n",m,n);
    for(i=0;i<26;i++)
        printf("%d   ",b[i]);
	return 0;
}
