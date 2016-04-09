#include <stdio.h>
void ff(int x)
{
	int s;
	if(x==0)s=1;
	else if(x==1)s=x;
	else s=((2*x-1)*s-ff(x-1)-(x-1)*ff(x-2))/x;
	printf("%d",s);
	return 0;
}
int main ()
{
	int x;
	scanf("%d",&x);
	ff(x);
	return 0;
}