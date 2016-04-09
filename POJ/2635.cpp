#include <cstdio>
#include <cstring>
#define maxn 1000007
#define MAXN 101
#define LL long long 
LL prim[maxn];
LL arr[MAXN];
bool is_prim[maxn];
int Init()
{
    for(int i = 2; i * i < maxn; ++i)
    {
        if(!is_prim[i])
            for(int j = 2 * i; j < maxn; j += i)
                is_prim[j] = true;
    }
    int pos = 0;
    for(LL i = 2; i < maxn; ++i)
        if(!is_prim[i]) prim[pos++] = i;
    return pos;
}
int main()
{
    int N = Init();
    char ch[MAXN];
    int L;
    while(scanf("%s%d", ch, &L), ch[0] != '0', L)
    {
        int len = strlen(ch), pos = 0, num = 12, p = len % num;
        LL val = 1;
        while(p--) val *= 10;
        for(int i = 0; i < len; i += num)
        {
            LL val = 0;
            for(int j = i; j < i + num && j < len; ++j)
                val = val * 10 + ch[j] - '0';
            arr[pos++] = val;
        }
        bool flag = true;
        for(int i = 0; prim[i] < L && i < N; ++i)
        {
            LL Mod = 0;
            for(int j = 0; j < pos; ++j)
            {
                if(j != pos - 1) Mod = (Mod * 1000000000000 + arr[j]) % prim[i];
                else Mod = (Mod * val + arr[j]) % prim[i];
            }
            if(Mod == 0)
            {
                printf("BAD %d\n", prim[i]);
                flag = false;
                break;
            }
        }
        if(flag) puts("GOOD");
    }
    return 0;
}
