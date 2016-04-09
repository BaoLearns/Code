#include <stdio.h>
#include <string.h>
int main()
{
	char a[6],b[6];
    int n1,n2,i,s1=1,s2=1;
    gets(a);
    n1=strlen(a);
    gets(b);
    n2=strlen(b);
    for(i=0;i<n1;i++)
    	s1=s1*(a[i]-64);
    for(i=0;i<n2;i++)
   		s2=s2*(a[i]-64);
	((s1%47)==(s2%47))?printf("GO\n"):printf("STAY\n");
    return 0;
}