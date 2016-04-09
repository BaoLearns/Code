#include <stdio.h>
#include <string.h>
int ff(int x)
{
    int a,b,len,i,j;
    char s[10];
    char k;
    sprintf(s,"%s",x);
    len=strlen(s);
    for(i=0;i<len;i++)
        for(j=i+1;j<len;j++)
                if(s[i]<s[j]) k=s[i],s[i]=s[j],s[j]=k;
    sscanf(s,"%d",&a);
    for(i=0;i<len/2;i++)
        k=s[i],s[i]=s[len-i-1],s[len-i-1]=k;
    sscanf(s,"%d",&a);
    return b-a;

}

int main()
{
    int i,j,cot=1,c=1;
    int num[1000];
    scanf("%d",&num[0]);
    printf("->%d\n",num[0]);
    for(;;)
    {
        num[cot]=ff(num[cot-1]);
        printf("->%d\n",num[cot]);
        int found=0;
        for(i=0;i<cot;i++)
            if(num[i]==num[cot]) {found=1;break;}
        if(found) break;
        cot++;
    }


    return 0;
}
