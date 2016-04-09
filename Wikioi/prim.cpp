#include <stdio.h>
#include <string.h>
int main()
{
    int a[10010],m[3],i,j,k,n,c=0,s;
	scanf("%s",a);
	for(i=0,k=0;i<strlen(a),i++)
	{
		m[k++]=a[0];
		for(j=i+1;j<strlen(a);j++)
			if(a[j]!=m[k]) m[k++]=a[j],break;
		for(n=j+1;n<strlen(a);n++)
			if(a[k++])
	}
    return 0;
}
