#include <stdio.h>
int main()
{
	int n,i=0,m;
	char a[100];
	scanf("%d%d",&n,&m);
	while (n>0)
	{
		a[i]=n%m+48;
		switch (a[i])
		{
		case 10:a[i]='A';break;
		case 11:a[i]='B';break;
		case 12:a[i]='C';break;
		case 13:a[i]='D';break;
		case 14:a[i]='E';break;
		case 15:a[i]='F';break;
		}
		n=n/m;
		i++;
	}
	printf("%s",a);
	printf("\n");
	return 0;
}
