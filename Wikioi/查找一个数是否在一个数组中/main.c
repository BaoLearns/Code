#include <stdio.h>
int main()
{
    void input(float arr[], int n);
    void bubblesort(float arr[], int n);
    int search(float arr[],int n, float num);
    void output(float arr[], int n);
    int n,num;
    float a[100];
    scanf("%d",&n);
    input(a,n);
    bubblesort(a,n);
    scanf("%d",&num);
    printf("%d\n",search(a,n,num));
    output(a,n);
    return 0;
}
void input(float arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
    scanf("%f",arr+i);
}
void bubblesort(float arr[], int n)
{
    int i,j,t;
    for(i=0;i<n;i++)
        for(j=0;j<n-i;j++)
            if(arr[j]>arr[j+1]) t=arr[j],arr[j]=arr[j+1],arr[j+1]=t;
}
int search(float arr[],int n, float num)
{
    int i,s=0;
    for(i=0;i<n;i++)
    {   if(arr[i]==num)
        {
            s=1;
            break;
        }
    }
    return s;
}
void output(float arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%f   ",arr[i]);
}
