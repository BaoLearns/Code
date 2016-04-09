/*#include <stdio.h>
#include <stdlib.h>
int ff(int s[],int l,int r)
{
    int j=r-1;
    int t;
    for(;l<=j;l++)
    {
        if(s[l]>s[r])
            for(;j>0;j--)
            {
                if(s[j]<s[r])
                {
                    t=s[l],s[l]=s[j],s[j]=t;
                    j--;
                    break;
                }
            }
    }
    t=s[l],s[l]=s[r],s[r]=t;
    return l;
}
void quicksort(int s[],int l,int r)
{

    if(l<r)
    {
        int q=ff(s,l,r);
        quicksort(s,l,q-1);
        quicksort(s,q+1,r);
    }
}
int main()
{
    int i;
    int s[10]={1,4,7,8,5,6,3,2,1,0};
    quicksort(s,0,9);
    for (i=0;i<10;i++)
        printf("%d  ",s[i]);
    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
char ff(void const *a, void const *b)
{
    return *(char*)a-*(char *)b;
}
int main()
{
    char s[10];
    int i;
    for (i=0;i<10;i++)
    scanf("%c",s+i);
    qsort(s,10,sizeof(char),ff);
    for(i=0;i<10;i++)
        printf("%c  ",s[i]);
    return 0;
}
