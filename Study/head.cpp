/*
 * Author : Roye_Bao
 * Time : 2015-4-4
 * Id : Royecode
 * Email:Royecode@163.com
 * Language : C / C++
 */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <string>
#include <iterator>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <cassert>
#include <ctime>
#include <climits>
#include <limits>
#define mid (l + (r - l) / 2)
#define lson (rx << 2, l, mid)
#define rson (rx << 2 | 1, mid + 1, r)
#define PI 3.1415927
#define LL long long 
#define Pii pair <int, int>
#define PB push_back
#define MP make_pair
#define IT iterator
#define EQ equal_range
#define Veci vector <int>
#define Vecll vector <LL>
#define Mapss map <string, string>
#define Mmapss multimap <string, string>
#define Mapii map <int , int>
#define Mmapii multimap <int , int>
#define Mapsi map <string, int>
#define Mapis map <int, string>
#define fr(n,m,s) for(int i = n; i <= m; i += s)
#define fr_(n,m,s) for(int i = n; i >= m; i -= s)
#define fra(it) for (auto i : it) cout << *i << " ";
#define what_case(x) cout << #x << " " << (x) << endl
#define C(x) cout << "------->" <<  (x) << endl;
#define MAX(a, b) ((a) > (b)? (a): (b))
#define MIN(a, b) ((a) > (b)> (a): (b))
#define Case(a) printf("Case #%d: ", (a))
#define MAXN 100005
#define MOD 0xf3f3f3f3f3f3f
using namespace std;
inline void read(int &x){int signe = 1, ch;x = 0;while(ch = getchar(), !isdigit(ch) && ch != '-');if(ch == '-') signe = -1;else x = ch - '0';while(ch = getchar(), isdigit(ch))x = x * 10 + ch - '0';x = x * signe;}
inline void read(LL &x){int signe = 1, ch;x = 0;while(ch = getchar(), !isdigit(ch) && ch != '-');if(ch == '-') signe = -1;else x = ch - '0';while(ch = getchar(), isdigit(ch))x = x * 10 + ch - '0';x = x * signe;}
inline void read(double &x){scanf("%lf", &x);}
inline void read(char *ch){while(*ch = getchar(), *ch == ' ' || *ch == '\n' || *ch == '\t' || *ch == EOF);while(*(++ch) = getchar(), *ch != ' ' && *ch != '\n' && *ch != '\t' && *ch != EOF);*ch = '\0';}
inline void write(int x, char c){char ch[10], pos = 0;if(x < 0) putchar('-');x = x > 0? x: -x;if(!x) putchar('0');while(x){ch[pos++] = x % 10;x /= 10;}while(pos)putchar(ch[--pos] + '0');putchar(c);}
inline void write(LL x, char c){char ch[20], pos = 0;if(x < 0) putchar('-');x = x > 0? x: -x;if(!x) putchar('0');while(x){ch[pos++] = x % 10;x /= 10;}while(pos)putchar(ch[--pos] + '0');putchar(c);}
inline void write(double x, char c){printf("%lf", x);putchar(c);}
inline void write(char ch[], char c){while(*ch !='\0') putchar(*ch++);putchar(c);}
int main(void)
{
    return 0;
}
