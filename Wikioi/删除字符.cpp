#include <stdio.h>
#include <string.h>
int main()
{
    char a[1000000];
	int i,j,n,x=0;
	gets(a);
	n=strlen(a);
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(a[i]==a[j]) a[i]=a[j]=1;
	for(i=0;i<strlen(a);i++)
		if(a[i]!=1) x++;
	printf("%d",x);
	return 0;
} 
