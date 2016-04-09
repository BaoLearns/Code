#include <iostream>
#include <set>
#include <cstring>
#include <cstdio>
#define maxn 10005
using namespace std;
char dir[maxn][20];
void replace(char *ch, char *Dir, int len)
{
    int i = 0, j = 0;
    int cnt = 0;
    while(i < len && j < len)
    {
        if(ch[i] != Dir[j])
            cnt++;
        if(cnt > 1)
            return;
        i++;
        j++;
    }
    if(cnt == 1)
    {
        printf(" %s", Dir);
    }
}
bool chang(char *ch, char *Dir, int len)
{
    int i = 0, j = 0;
    while(i < len && j < len)
    {
        if(ch[i] == Dir[j])
            i++;
        j++;
            
    }    
    return i == len - 1 && j == len;
}
int main()
{
    char ch[20];
    bool flag = false;
    int pos = 0;
    while(scanf("%s", dir[pos]))
    {
        if(dir[pos][0] == '#')
            break;
        pos++;
    }
    while(scanf("%s", ch))
    {
        if(ch[0] == '#')
            break;
        int flag = true;
        for(int i = 0; i < pos; ++i)
        {
            if(strcmp(ch, dir[i]) == 0)
            {
                printf("%s is correct\n", ch);
                flag = false;
                break;
            }
        }
        if(flag)
        {
            printf("%s :", ch);
            int len1 = strlen(ch);
            for(int i = 0; i < pos; ++i)
            {
                int len2 = strlen(dir[i]);
                if(len1 == len2)
                    replace(ch, dir[i], len1);
                else if(len1 == len2 - 1 && chang(ch, dir[i], len2)) printf(" %s", dir[i]);
                else if(len1 - 1 == len2 && chang(dir[i], ch, len1)) printf(" %s", dir[i]);
            }
            putchar('\n');
        }
    }
    return 0;
}
