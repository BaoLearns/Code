/*
 * Author : Roye_Bao
 * Id : Royecode
 * Email:Royecode@163.com
 * Language : C / C++
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <string>
#include <queue>
#include <stack>
#include <iterator>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <cassert>
#include <ctime>
#include <climits>
#include <limits>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mid l + (r - l) / 2
#define lson rx << 2, l, mid
#define rson rx << 2 | 1, mid + 1, r
#define Pii pair <int, int>
#define PI 3.1415927
#define LL long long 
#define PB push_back
#define MP make_pair
#define IT iterator
#define EQ equal_range
#define Vi vector <int>
#define Vll vector <LL>
#define Mss map <string, string>
#define Mmss multimap <string, string>
#define Mii map <int , int>
#define Mmii multimap <int , int>
#define Msi map <string, int>
#define Mis map <int, string>
#define fi(n,m,s) for(int i = n; i <= m; i += s)
#define fj(n,m,s) for(int j = n; j <= m; j += s)
#define fi_(n,m,s) for(int i = n; i >= m; i -= s)
#define fj_(n,m,s) for(int j = n; j >= m; j -= s)
#define fra(it) for (auto i : it) cout << *i << " ";
#define what_case(x) cout << #x << " " << (x) << endl;
#define C(x) cout << "------->" <<  x << endl;
#define Case(I) printf("Case #%d:\n", I)
#define MAXN 100007
#define MOD 0xf3f3f3f3f3f3f
using namespace std;
inline void read(int &x){int signe = 1, ch;x = 0;while(ch = getchar(), !isdigit(ch) && ch != '-');if(ch == '-') signe = -1;else x = ch - '0';while(ch = getchar(), isdigit(ch))x = x * 10 + ch - '0';x = x * signe;}
inline void read(LL &x){int signe = 1, ch;x = 0;while(ch = getchar(), !isdigit(ch) && ch != '-');if(ch == '-') signe = -1;else x = ch - '0';while(ch = getchar(), isdigit(ch))x = x * 10 + ch - '0';x = x * signe;}
inline void read(double &x){scanf("%lf", &x);}
inline void read(char &ch){while(ch = getchar(), ch == ' ' || ch == '\n' || ch == EOF);}
inline void read(char *ch){while(*ch = getchar(), *ch == ' ' || *ch == '\n' || *ch == '\t' || *ch == EOF);while(*(++ch) = getchar(), *ch != ' ' && *ch != '\n' && *ch != '\t' && *ch != EOF);*ch = '\0';}
inline void write(int x, char c){char ch[10], pos = 0;if(x < 0) putchar('-');x = x > 0? x: -x;if(!x) putchar('0');while(x){ch[pos++] = x % 10;x /= 10;}while(pos)putchar(ch[--pos] + '0');putchar(c);}
inline void write(LL x, char c){char ch[20], pos = 0;if(x < 0) putchar('-');x = x > 0? x: -x;if(!x) putchar('0');while(x){ch[pos++] = x % 10;x /= 10;}while(pos)putchar(ch[--pos] + '0');putchar(c);}
inline void write(const double x, char c){printf("%lf", x);putchar(c);}
inline void write(const char ch, char c){putchar(ch);putchar(c);}
inline void write(const char ch[], char c){while(*ch !='\0') putchar(*ch++);putchar(c);}
int main()
{
    std::ios::sync_with_stdio(false);
    return 0;
}
