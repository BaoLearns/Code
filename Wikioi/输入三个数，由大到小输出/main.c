#include <stdio.h>
#include <string.h>
int main()
{
    char a[100],b[100],c[100];
    char p[100];
    char *p1=&a,*p2=&b,*p3=&c;
    scanf("%s%s%s",&a,&b,&c);
    if(strcmp(a,b)==1)p=*p1,*p1=*p2,*p2=p;
    if(strcmp(b,c)==1)p=*p2,*p2=*p3,*p3=p;
    if(strcmp(a,c)==1)p=*p1,*p1=*p3,*p3=p;
    printf("%s %s %s\n",*p1,*p2,*p3);
    //printf("%d %d %d\n",a,b,c);
    return 0;
}
