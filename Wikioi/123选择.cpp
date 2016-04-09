#include <stdio.h>
int main()
{
	int ff(int x,int y,int (*p)(int ,int));
	int max(int ,int);
	int min(int ,int);
	int add(int ,int);
	int (*p)(int,int);
	int a,b,c,n;
	printf("plese enter a and b:");
	scanf("%d%d",&a,&b);
	printf("plese enter 1 or 2 or 3:");
	scanf("%d",&n);
	if(n==1)ff(a,b,max);
	else if(n==2)ff(a,b,min);
	else if( n==3)ff(a,b,add);
	c=(*p)(a,b);
	if(n==1)printf("max=%d\n",c);
	else if(n==2)printf("min=%d",c);
	else printf("add=%d",c);
	return 0;
}
int ff(int x,int y,int (*p)(int ,int ))
{
int s;
s=(*p)(x,y);
return 0;

}
int max(int x,int y)
{
int z;
if(x>y)z=x;
else z=y;
return z;
}
int min(int x,int y)
{
int z;
if(x<y)z=x;
else z=y;
return z;
}
add(int x,int y)
{int z;
z=x+y;
return z;
}