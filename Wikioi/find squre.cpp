#include <stdio.h>
int main()
{
    char s[1000];
    int len,i=0,a,b;
    scanf("%d\n",&len);
    scanf("%s",s);
    while(i<len)
    {
        if(i==0) len--;
        if(s[i] < s[len]) printf("%c",s[i]),i++;
        else if(s[i] > s[len]) printf("%c",s[len]),len--;
        else
        {
			a=i,b=len;
            printf("%c",s[i]);
            while(i<=len)
            {
                if(s[i++]>s[len--])
                {
                    len=b-1;
                    break;
                }
                else if(s[i++]<s[len--])
                {
                    i=a-1;
                    break;
                }
				else i++,len--;
            }
        }
    }
    putchar('\n');
    return 0;
}
