#include <stdio.h>
int main()
{
	int y,m,d,s=0;
	scanf("%d %d %d",&y,&m,&d);
	if((y%4==0 && y%100!=0)||y%400==0)
		s=1;
	else 
	{
		m--;
		switch (m)
	{
	
			case 12:s=s+31,m--;
			case 11:s=s+30,m--;
			case 10:s=s+31,m--;
			case 9:s=s+30,m--;
			case 8:s=s+31,m--;
			case 7:s=s+31,m--;
			case 6:s=s+30,m--;
			case 5:s=s+31,m--;
			case 4:s=s+30,m--;
			case 3:s=s+31,m--;
			case 2:s=s+28,m--;
			case 1:s=s+31,m--;
	}
	}
	s=s+d;
	printf("%d\n",s);
	return 0;
}