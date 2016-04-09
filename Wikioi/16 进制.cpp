5
/*    功  能：16进制转换为10进制
      Author: CHEN
	  Ver   : 1.0
*/
#include <stdio.h>
#include <string.h>
void main()
{
	int covertHex2Dec(char hex[]);
	char hex[100];
	int res;
	printf("input a hex num:");
	gets(hex);
	res = covertHex2Dec(hex);
	printf("Result = %d\n", res);
}
int covertHex2Dec(char hex[])
{

	int dec = 0, n, p = 1, tmp;
	int i, j;
	n = strlen(hex);

	for(i=n-1;i>=0;i--)
	{
	   tmp = 1;

	   for(j=n-1;j>i;j--)
	     tmp = tmp * 16;
	   if(hex[i]>'0' && hex[i]<='9')
		   tmp = (hex[i] - 48) * tmp;
	   else
		  if(hex[i]>='a' && hex[i]<='f')
			  tmp = (hex[i] - 97 + 10)*tmp;
		  else
		      tmp = (hex[i] - 65 + 10)*tmp;
	   dec = dec + tmp;
	}
	return dec;
}
