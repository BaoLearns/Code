#include <stdio.h>
#include <math.h>
int main()
{
	int m,s,c=1;
	int a[7];
	int i,n,j;
	scanf("%d",&n);
	for(i=6;a[0]==1;i--)
	{
	
		if(n>=pow(2,i))
		{	
			a[0]=1;
			n=n-pow(2,i);
			for(j=i-1;n=0;j--)
			{
				if(n>=pow(2,j))
				{
					a[c]=1;
				n=n-pow(2,j);
				}
				else 
					a[c]=0;
				c++;

			}
		}
	
	}
	for(c=0;c<7;c++)
	printf("%d",a[c]);
	return 0;
}