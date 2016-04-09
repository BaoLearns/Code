#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    map <char, char> Map;
    string st1 = "`1234567890-=qwertyuiop[]\\asdfghjkl;\'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
    string st2 = "`1234567890[]\',.pyfgcrl/=\\aoeuidhtns-;qjkxbmwvz~!@#$%^&*(){}\"<>PYFGCRL?+|AOEDIDHTNS_:QJKXBMWVZ";
    int len = st1.length();
    for(int i = 0; i < len; ++i)
        Map[st1[i]] = st2[i];
    Map[' '] = ' ';
    char ch;
    while(~scanf("%c", &ch))
    {
        if(Map.find(ch) != Map.end()) printf("%c", Map[ch]);
        else printf("%c", ch);
    }
    return 0;
}
