#include <stdio.h>
int main()
{
	char a[100],*p;
	p=a;
	int n,m,i;
	printf("plese enter n:");
	scanf("%d",&n);
	printf("plese enter a:");
	for(i=0;i<n;i++)
		scanf("%c",&a[i]);
	printf("plese enter m:");
	scanf("%d",&m);
	for(i=0;i<n;i++,p++)
	{
		if(i+m<n) printf("%c",*(p+m));
		else printf("%c",*(p+m-n));
	}
	printf("\n");
	return 0;
}
