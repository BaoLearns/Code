#include <cstdio>
#include <cstring>
#include <map>
#define LL long long
using namespace std;
map <LL, const char*> Map;
int main()
{
    char ch[100];
    while(true)
    {
        gets(ch);
        int len = strlen(ch);
        if(len < 2) break;
        LL v = 0;
        int i;

        while(ch[i] != ' ') i++;
        for(i = 0; i < len; ++i)
            v = v * 10 + ch[i] - 'a';
        
        strcpy(c, ch + i);
        Map[v] = c;
    }
    for(auto it: Map) printf("%d   %s\n", it.first, it.second);
    while(~scanf("%s", ch))
    {
        LL v = 0, len = strlen(ch);
        for(int i = 0; i < len; ++i) v = v * 10 + ch[i] - 'a';
        if(Map.find(v) == Map.end()) puts(Map[v]);
        else puts("eh");
        putchar('\n');
    }
    return 0;
}
