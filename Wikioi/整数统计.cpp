#include <stdio.h>
#include <string.h>
int main()
{
	char x[210],y[210];
	char a[210],b[210],c[210]={'0'};
	int i,n;
	scanf("%s%s",x,y);
	n=strlen(x)-strlen(y);
	if(n>0)
	{
		for(i=strlen(y)-1;i>=0;i--)
		{
			if((x[i+n]+y[i])/10>0) c[i-1]=(x[i+n]+y[i])/10;
			a[i]=x[i+n]+y[i]+c[i]-96;
		}
		for(i=n;i>=0;i--)
			a[i]=x[i+n]+c[i]-48;
		
	}
	if(n=0)
	{
		for(i=strlen(y)-1;i>=0;i--)
		{
			if((x[i]+y[i])/10>0) c[i-1]=(x[i]+y[i])/10;
			a[i]=x[i+n]+y[i]+c[i]-96;
		}
		
	}
	if(n<0)
	{
		for(i=strlen(x)-1;i>=0;i--)
		{
			if((x[i]+y[i-n])/10>0) c[i-1]=(x[i]+y[i-n])/10;
			a[i]=x[i]+y[i-n]+c[i]-96;
		}
		for(i=n;i>=0;i--)
			a[i]=y[i-n]+c[i]-48;
		
	}
	printf("%s\n",a);
	return 0;
}