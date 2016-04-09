#include <stdio.h>
void fi(int s[])
{
    int i;
    for(i=0;i<10;i++)
    scanf("%d",s+i);
}
void f2(int s[])
{
    int i;
    int *max,*min,t;
    max=min=s;
    for(i=0;i<10;i++)
       {
           if(s[i]>*max ) max=&s[i];
           if(s[i]<*min) min=&s[i];
       }
    t=s[0],s[0]=*min,*min=t;
    t=s[9],s[9]=*max,*max=t;


}
void f3(int s[])
{
    int i;
    for(i=0;i<10;i++)
        printf("%-5d",s[i]);
    printf("\n");
}
int main()
{
    int s[10];
    fi(s);
    f2(s);
    f3(s);
    return 0;
}
