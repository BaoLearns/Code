#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
bool cmp(const char a, const char b)
{
    if(a <= 'Z' && b <= 'Z') return a < b;
    else if(a >= 'a' && b >= 'a') return a < b;
    else if(a <= 'Z' && b >= 'a') return a < (b - 31);
    else if(a >= 'a' && b <= 'Z') return (a - 31) <= b;
    //else return false;
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        char ch[20];
        scanf("%s", ch);
        int len = strlen(ch);
        sort(ch, ch + len, cmp);
        do
        {
            puts(ch);
        }while(next_permutation(ch, ch + len, cmp));
    }
    return 0;
}
