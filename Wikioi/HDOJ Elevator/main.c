#include <stdio.h>
#include <stdlib.h>
int main()
{
    char ch;
    int s=0,x;
    while(1)
    {
        scanf("%c",&ch);
        if(ch=='0')
            break;
        if(ch=='\n')
        {
            printf("%d\n",s+5);
            s=0;
        }
        else
        {
            s+=x >ch-48?(x-ch-48)*4:(ch-48-x)*6;
            x=ch-48;
            printf("x=%d\n",x);
        }
    }
    return 0;
}
