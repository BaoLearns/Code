#include <stdio.h>
#include <stdlib.h>
struct
{
    char name[20];
    int avg;
    int pin;
    char b;
    char x;
    int l;
    int g;
}s[1010],t;
int main()
{
    int n,i,j,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s%d%d%c%c%c%c%d",s[i].name,&s[i].avg,&s[i].pin,&s[i].b,&s[i].b,&s[i].x,&s[i].x,&s[i].l);
        s[i].g=0;
        if(s[i].avg>80&&s[i].l>=1) s[i].g+=8000;
        if(s[i].avg>85&&s[i].pin>80) s[i].g+=4000;
        if(s[i].avg>90) s[i].g+=2000;
        if(s[i].avg>85&&s[i].x=='Y') s[i].g+=1000;
        if(s[i].avg>80&&s[i].b=='Y') s[i].g+=850;
        sum+=s[i].g;
    }
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        if(s[i].g<s[j].g) t=s[i],s[i]=s[j],s[j]=t;
    printf("%s\n%d\n%d\n",s[0].name,s[0].g,sum);
    return 0;
}
