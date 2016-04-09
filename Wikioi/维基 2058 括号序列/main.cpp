#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
char s[200010];
stack <char > st;
int main()
{
	int n,i,m;
	scanf("%d\n",&n);
	while(n--)
	{
		gets(s);
        m=strlen(s);
        st.push(s[0]);
        for(i=1;i<m;++i)
        {
            char ch=st.top();
            printf("1\n");
            if((s[i]=='}'&& ch=='{') || (s[i]==']'&& ch=='[') ||(s[i]=='>'&& ch=='<') || (s[i]==')'&& ch=='('))
                st.pop();
            else
            {
                if(s[i]=='}' || s[i]=='>'|| s[i]==')'||s[i]==']')
                    break;
                st.push(s[i]);
            }
            printf("%c,size=%d\n",ch,st.size());

        }
        st.empty() && i>=m?printf("TRUE\n"):printf("FALSE\n");
	}
	return 0;
}
