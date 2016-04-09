#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Findpost(char *Insort,char *Pointsort,int m,int n)
{
    int i;
    for(i=m;i<=n;++i)
    {
        if(Pointsort[n]==Insort[i])
            break;
    }
    return i;
}
void Presort(char *Insort,char *Pointsort,int m,int n)
{
    //int i,j;
    //printf("%c ",Pointsort[n]);
    if(n-m<=1)
    {
        printf("%c ",Insort[m]);
        return;
    }
    int p=Findpost(Insort,Pointsort,m,n);
    printf("%c ",Insort[p]);
    Presort(Insort,Pointsort,m,p-1);
    Presort(Insort,Pointsort,p+1,n);


    //return exit(-1);
}
int main()
{
    char Insort[9]={'D','B','E','A','C','F'};
    char Pointsort[9]={'D','E','B','F','C','A'};

    int n=6;
    //n=length(Insort);
    //m=length(Pointsort);
    Presort(Insort,Pointsort,0,n-1);
    return 0;
}
