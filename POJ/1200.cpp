/*#include <iostream>
#include <set>
#define LL long long
#define MOD 0x7fffffff
using namespace std;
int BKDRhash(const char *s, const char* e)
{
LL x = 0;
while(s != e)
x = (x * 131 + (*s++)) % MOD;
return x;
}
int main()
{
int n, m;
while(cin >> n >> m)
{
char ch[10001], c;
getchar();
for(int i = 0; i < n; ++i) ch[i] = getchar();

LL x = BKDRhash(ch, ch + n);
LL Mod = 1, num = n - 1;
while(num--)
Mod *= 131;
set <LL> Set;
int cnt = 0;
while(c != '\n' && c != EOF)
{
if(Set.find(x) == Set.end())
{
Set.insert(x);
cnt++;
}
c = getchar();
//cout << x << endl;
x %= Mod;
x = (x * 131 + c) % MOD;
}
cout << cnt << endl;
}
return 0;
}
*/
/*
#include <cstdio>
#include <cstring>
#include <set>
#define MAXN 16000007
using namespace std;
char ch[MAXN];
bool Hash[MAXN];
int vised[26];
int main()
{
int n, m;
while(~scanf("%d%d", &n, &m))
{
memset(vised, false, sizeof(vised));
memset(Hash, false, sizeof(Hash));
scanf("%s", ch);
int len = strlen(ch), pos = 1;
for(int i = 0; i < len; ++i)
{
if(!vised[ch[i] - 'a'])
vised[ch[i] - 'a'] = pos++;
ch[i] = vised[ch[i] - 'a'];
}
int x = 0, val = 1;
for(int i = 0; i < n; ++i)
{
x = x * m + ch[i] - 1;
val *= m;
}
val /= m;
int cnt = 0;
for(int i = 0; i <= len - n; ++i)
{
if(!Hash[x])
{
Hash[x] = true;
cnt++;
}
x %= val;
x = x * m + ch[n + i] - 1;
}
printf("%d\n", cnt);
}
return 0;
}
*/
/*
#include <iostream>
#include <cstring>
using namespace std;
int BKDR(const char* s, const char* e)
{
int seek = 131, x = 0;
while(s != e)
x = x * seek + *s++;
return x;
}
int main()
{
char ch1[101], ch2[101];
cin >> ch1 >> ch2;
int a =  strlen(ch1), b = strlen(ch2);
int x = BKDR(ch2, ch2 + b);
int y = BKDR(ch1, ch1 + b);
int mod = 1, num = b - 1;
while(num--) mod *= 131;
for(int i = 0; i <= a - b; ++i)
{
if(x == y)
{
putchar('s');
break; 
}
cout << x << " " << y << endl;
y %= mod;
y = y * 131 + ch1[i + b];
}
return 0;
}*/

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
/*
9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999536689 999984
143 10
143 20
667 20
667 30
2573 30
2573 40
0 0
*/
