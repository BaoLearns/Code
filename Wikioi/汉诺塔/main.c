#include <stdio.h>
#include <stdlib.h>
int m;
void print(char i,char j)
{
    //printf("%d  ",m++);
    //printf("%c->%c\n",i,j);
}
void hanoi(int n,char i ,char j,char k)
{

    if(n==1) print(i,k);
    else
    {
            n--;
    hanoi(n,i,k,j);
    //print(i,k);
m++;
    hanoi(n,j,i,k);
    }
}
int main()
{
    int n;
    while (scanf("%d",&n))
    {
        m=1;
        hanoi(n,'A','B','C');
printf("%d\n",m);
    }
    return 0;
}
