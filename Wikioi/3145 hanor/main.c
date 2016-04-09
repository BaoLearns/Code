#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void print(int num ,char i,char j)
{
    printf("%d form %c to %c\n",num,i,j);
}
void hanor( int n , char one , char two ,char therr )
{
    if( n == 1 )
    {
        print( n ,one , therr);
    }
    else
    {
        hanor ( n-1 , one , therr , two );
        print (n, one , therr);
        hanor (n -1 , two , one, therr);
    }
}
int main()
{
    int n;
    char one='A',two='B',therr='C';
    scanf("%d",&n);
    printf("%.0lf\n",pow(2,n)-1);
    hanor(n,one,two,therr);
    return 0;
}
