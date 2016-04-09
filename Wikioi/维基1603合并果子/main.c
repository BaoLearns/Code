#include <stdio.h>
#include <stdlib.h>
int sum;
int comp( const void *a, const void  *b)
{
    return *( int *)a - *( int *)b;
}
int diandiao( int *s, int n)
{
    int i, j = 0, c = 0;
    int arr[10010] = { 0};
    for( i = 0; i < n; )
    {
        if(i == n-2 && arr[0] > 0)
        {
            arr[ ++j] = s[ i] ;
            arr[ ++j] = s[ i + 1];
            break;
        }
        if(c == 0 && i + 1 < n)
        {
            arr[ j] = s[ i] + s[ i+ 1];
            c = 1;
            i += 2;
        }
        else
        {
            arr[ j] = arr[ j] + s[ i];
            ++i;
        }
        sum = sum + arr[ j];
        if(( arr[ j] > s[ i] && arr[ j] > s[ i + 1] && i + 1 < n))
        {
            c = 0;
            ++j;
        }
    }
    if(j == 0)
        return sum;
    for(i = 0 ; i < j+1 ; ++ i)
        printf("%d " , arr[i]);
    putchar('\n');
    qsort( arr, j + 1, sizeof( int), comp);
    /*for(i = 0 ; i <=j ; ++ i )
        printf("%d " , arr[i]);
    putchar('\n');*/
    diandiao( arr , j + 1 );

}
int main()
{
    int n , i ;
    int s [ 10010];
    while(scanf("%d", &n))
    {
        sum = 0;
        for( i = 0 ; i < n ; ++i)
        scanf("%d",s + i);
        qsort( s, n, sizeof( int), comp);
        printf("%d\n",diandiao( s, n));
    }
    return 0;
}
