#include<stdio.h>
int main()
{
	int i,n,a[10],max,min;
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	max=min=a[0];
	for(i=1;i<10;i++)
	{
		if(max<a[i])
		max=a[i];
		if(min>a[i]) min=a[i];
	}
	a[0]=max,a[9]=min;
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	return 0;
}
