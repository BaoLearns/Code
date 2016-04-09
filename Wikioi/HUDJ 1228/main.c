#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char arr[100];
char hash[10][10]={{"zero"},{"one"},{"two"},{"three"},{"four"},{"five"},{"six"},{"seven"},{"eight"},{"nine"}};
int find(char *arr)
{
    int i;
    for(i=0;i<10;++i)
    {
        if(strcmp(hash[i],arr)==0)
            return i;
    }
}
int main()
{

    int a[2]={0},b[2]={0};
    int t=0,g=0;
    int falg=1;
    while(1)
    {
        scanf("%s",arr);
        printf("%s\n",arr);
        //int i;
        if(arr=='+')
        {
            falg=0;
           continue;
        }

        if(arr =='=')
        {
            printf("%d,=%d\n",a[0],b[0]);
            int s=0;
            if(t==1)
                s+=a[0]*10+a[1];
            else
                s+=a[0];
            if(g==1)
                s+=b[0]*10+b[1];
            else
                s+=b[0];
            if(s==0)
                break;
            else
                printf("%d\n",s);
            memset(a,0,sizeof(a));
            memset(b,0,sizeof(b));
            t=g=0;
            falg=1;
            continue;
        }

        if(falg)
            a[t++]=find(arr);
        else
            b[g++]=find(arr);
        printf("%d,%d\n",a[0],b[0]);

    }
    return 0;
}
