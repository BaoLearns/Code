#include <cstdio>
#include <cstring>
#define MAXN 1000007
char ch[MAXN];
int next[MAXN];
void get_next(const char p[])
{
    int len = strlen(p), k = -1, j = 0;
    next[0] = -1;
    while(j < len)
    {
        if(k == -1 || p[k] == p[j])
        {
            k++;
            j++;
            if(p[k] != p[j]) next[j] = k;
            else next[j] = next[k];
        }
        else k = next[k];
    }
    for(int i = 0; i < len; ++i)
        printf("%d%c", next[i], i < len - 1? ' ': '\n');
    printf("%d\n", len % (len - next[len]) == 0? len / (len - next[len]): 1);
}
int main()
{
    while(~scanf("%s", ch), ch[0] != '.')
        get_next(ch);
    return 0;
}
