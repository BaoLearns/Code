#include <stdlib.h>

int main()
{
    int n,i,j,k,c=1;
    scanf("%d", &n);
    int s[25010];
    for( i = 0; i < n; ++i)
        scanf("%d", s + i);
    int cnt = 1;
    if(n <= 1)
        printf("0\n");
    else
    {
        for( i = 2; i < n; ++i)
        {
            ++cnt;
            c=1;
            for( j = i - 1; j >= 0 && c==1; --j)
            {
                if( s[ j] > s[ j - 1])
                {
                    c=0;
                    int val=s[j];
                    for( k = j-2; k >= 0; --k)
                        {
                            if( s[k] > val)
                            {
                                val = s[ k];
                                ++cnt;
                            }
                        }
                }
                else
                    ++cnt;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}

