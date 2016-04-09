#include<stdio.h>
#include <string.h>
int main()
{
  char a[1000000];
  int i,n,k=0,j,num=0;
  gets(a);
  n=strlen(a);
 for(i=n-1;i>=0;i--)
  {
     if((a[i]>=65&&a[i]<=122)||(a[i]<=97&&a[i]<=122))
     {
         if(a[i]!=' ')k++;
		 else
	  {
		  for(j=n-k-1;j<=n-1;j++)
		  {
			  printf("%c",a[j]);
			  if(num==0)printf("\b");
			  num++;
		  }
		  n=n-k-1;
			k=0;
	  }		 
	if(i==0)
	{
		printf(" ");
		for(j=0;j<n;j++)
			printf("%c",a[j]);
	}
     }
  }
 printf("\n");
  return 0;
}
