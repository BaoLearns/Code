#include <stdio.h>
#include <string.h>
#define maxn 300;
int f[maxn];
int main()
{	int n,i,j;
	scanf("%d",&n);
	memset(f,0,sizeof(f));
	f[0]=1;
	for(i=2;i<n;i++)
	{
		int c;
		for(j=0;j<maxn;j++)
		{
			int s=f[j]*i+c;
			f[j]=s%10;
			c=s/10;
		}
	}
	for(i=maxn;i>=0;i--) 
		if(f[i]) break;
	for(j=i;j>=0;j--)
		printf("%d",f[j]);
	printf("\n");
	return 0;
}