/*#include <stdio.h>
int partition(int s[],int p,int r)
{
    int i=p-1,j=p,t;
    for(;j<=r;j++)
        if(s[j]<=s[r]) t=s[j],s[j]=s[++i],s[i]=t;
    return i;
}
void quicksort(int s[],int p,int r)
{
    if(p<r)
    {
        int q=partition(s,p,r);
        quicksort(s,p,q-1);
        quicksort(s,q+1,r);
    }
}
int main()
{
    int n,s[100100];
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
        scanf("%d",s+i);
    quicksort(s,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",s[i]);
    return 0;
}*/

/*#include <stdio.h>
#include <stdlib.h>
int ff(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}
int main()
{
    int s[10]={2,1,4,7,8,5,9,6,3,0};
    qsort(s,10,sizeof(int),ff);
    int i;
    for(i=0;i<10;i++)
        printf("%d  ",s[i]);
    return 0;
}*/
/*#include <stdio.h>
int pritition(int s[],int p,int r)
{
    int i=p-1,j=p,t;
    for(;j<=r;j++)
        if (s[j]>=s[r]) t=s[j],s[j]=s[++i],s[i]=t;
    return i;
}
void quicksort(int s[],int p,int r)
{
    int q=pritition(s,p,r);
    if(p<r)
    {
        quicksort(s,p,q-1);
        quicksort(s,q+1,r);
    }

}
int main()
{
    int s[30000],ant=0;
    int a,b;
    int i;
long long t=0;
    while (scanf("%d%d",&a,&b)==2)
    {
            for(i=0;i<a;i++)
                scanf("%d",s+i);
            quicksort(s,0,a-1);
            for(i=0;i<a;i++)
            {
                t=t+s[i];
                if(t<=b) ant++;

            }
        printf("%d\n",ant);
    }
    return 0;
}
*/
