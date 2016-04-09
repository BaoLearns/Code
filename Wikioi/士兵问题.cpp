#include <stdio.h>
int main()
{
	int n,i,m;
    scanf("%d",&n);
    for(i=2;i<n;i++)
    {
    	if(n%i==0)
            break;
    }
    if(i>=n)
   	  printf("%d\n",n);
	else
    {
		for(i=2;n!=1;i++)
		{
			if(n%i==0)
			{
			m=i;
			n=n/i;
			i--;
			}
		}
		printf("%d\n",m);
	}
	return 0;
}
