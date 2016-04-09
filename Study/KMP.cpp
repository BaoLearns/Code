/*#include <iostream>
#include <cstring>
#define MAXN 10007
using namespace std;
int next[MAXN];
void get_next(char t[], int next[])
{
    int j = 0, k = -1;
    next[0] = -1;
    while(t[j + 1] !='\0')
    {
        if(k == -1 || t[j] == t[k])
        {
            ++j,++k;
            if(t[j] != t[k]) next[j] = k;
            else next[j] = next[k];
        }
        else k = next[k];
    }
}
int Index_KMP(char s[], char t[])
{
    int i = 0, j = 0;
    while(s[i] != '\0' && t[j] != '\0')
    {
        if(j == -1 || s[i] == t[j]) ++i, ++j;
        else j = next[j];
    }
    if(t[j] == '\0') return i - j;
    return 0;
}
int main()
{
    char s[MAXN], t[MAXN];
    scanf("%s%s", s, t);
    get_next(t, next);
    for(int i = 0;  i < strlen(t); ++i)
        cout << next[i] << " ";
    putchar('\n');
    int m = Index_KMP(s, t);
    cout << m << endl;
    return 0;
}
*/
/*
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
void NEXT(const string &T, vector <int> &next)
{
    //按模式串生成vector,next(T.size())
    next[0] = -1;
    for(int i = 1;i < T.size(); i++){
        int j = next[i-1];
        while(T[i] != T[j+1] && j >= 0)
            j = next[j];//递推计算
        if(T[i] == T[j+1]) next[i] = j + 1;
        else next[i] = 0;//
    }
}
string::size_type COUNT_KMP(const string &S, const string &T)
{
    //利用模式串T的next函数求T在主串S中的个数count的KMP算法
    //其中T非空，
    vector <int> next(T.size());
    for(int i = 0; i < T.size(); ++i)
        cout << next[i] << " ";
    cout << endl;
    NEXT(T,next);
    string::size_type index, count = 0;
    for(index = 0; index < S.size(); ++index){
        int pos = 0;
        string::size_type iter = index;
        while(pos < T.size() && iter < S.size()){
            if(S[iter] == T[pos]){
            ++iter;
            ++pos;
            }
            else{
                if(pos == 0) ++iter;
                else pos = next[pos - 1] + 1;
            }
        }//whileend
        if(pos == T.size() && (iter - index) == T.size()) ++count;
    }//forend
    return count;
}
int main(int argc, char* argv[])
{
    string S, T;
    cin >> S >> T;
    string::size_type count = COUNT_KMP(S,T);
    cout << count << endl;
    return 0;
}
*/
/*
#include <iostream>
#include <vector>
#define MAXN 10007
using namespace std;
vector <int> next(1007);
void get_next(string t)
{
    int len = t.size();
    for()
}
int main()
{
    string s, t;
    cin >> s >> t;
    return 0;
}*/

#include <iostream>
#include <cstring>
#define MAXN 1007
using namespace std;
char next[MAXN];
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
            if(p[j] != p[k]) next[j] = k;
            else next[j] = next[k];
        }
        else
            k = next[k];
    }
}
int KMP(const char s[], const char p[])
{
    int i = 0, j = 0, lens = strlen(s), lenp = strlen(p);
    while(i < lens && j < lenp)
    {
        if(j == -1 || s[i] == p[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    return j == lenp? i - j: -1;
}
int main()
{
    const char s[10] = "ABCD0ABCF";
    const char p[10] = "ABCF";
    get_next(p);
    cout << KMP(s, p) << endl;
    return 0;
}
