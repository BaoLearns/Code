#include <cstdio>
#include <cstring>
#define MAXN1 10007
#define MAXN2 1000007
char p[MAXN1], s[MAXN2];
int next[MAXN1];
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
}
int KMP(const char s[], const char p[])
{
    int lens = strlen(s), lenp = strlen(p);
    int cnt = 0, i = 0, j = 0;
    while(i < lens)
    {
        if(j == -1 || s[i] == p[j])
        {
            i++;
            j++;
        }
        else j = next[j];
        if(j == lenp)
        {
            cnt++;
            j = next[j];
        }
    }
    return cnt;
}
int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s%s", p, s);
        get_next(p);
        printf("%d\n", KMP(s, p));
    }
    return 0;
}
