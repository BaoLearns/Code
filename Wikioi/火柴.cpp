#include <stdio.h>
int main()
{
	int a[25]={6,2,5,5,4,5,6,3,7,6,8,4,7,7,6,7,8,5,9,8,11,7,10,10,9};
	int n,i,j,k,num1=0;
	scanf("%d",&n);
	for(i=0;i<25;i++)
	{
		for(j=0;j<25;j++)
		{
			for(k=0;k<25;k++)
			{
				if((i+j==k) && (a[i]+a[j]+a[k]==n-4))
				{
					num1++;
				printf("%d %d %d\n",i,j,k);
				}
			}
		}
	}
	printf("%d\n",num1);
	return 0;
}