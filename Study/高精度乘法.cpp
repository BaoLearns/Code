/*#include <iostream>
#include <cstring>
#define maxn 1005
using namespace std;
void solve(char *a, char *b, int la, int lb)
{
    int sum[maxn];
    memset(sum, 0, sizeof(sum));
    for(int i = 0; i < la; ++i)
    {
        for(int j = 0; j < lb; ++j)
        {
            sum[i + j] += a[i] * b[j];
        }
    }
    for(int i = 0; i < maxn; ++i)
        if(sum[i] >= 10)
        {
            sum[i + 1] += sum[i] / 10;
            sum[i] %= 10;
        } 
    int pos;
    for(pos = maxn - 1; sum[pos] == 0 && pos >= 0; --pos);
    while(pos >= 0)
        printf("%d", sum[pos--]);
    cout << endl;
}
int main()
{
    char a[maxn] = {0}, b[maxn] = {0};
    char temp1[maxn], temp2[maxn];
    cin >> temp1 >> temp2;
    int la = strlen(temp1), lb = strlen(temp2);
    for(int i = la - 1; i >= 0; --i)
        a[la - 1 - i] = temp1[i] - '0';
    for(int i = lb - 1; i >= 0; --i)
        b[lb - 1 - i] = temp2[i] - '0';
    solve(a, b, la, lb);
    return 0;
}

*/

#include <iostream>
using namespace std;
int C[10], ans = 0;
void solve(int row)
{
    if(row == 9) 
    {
        ans++;
        return ;
    }
    for(int i = 1; i <= 8; ++i)
        if(!C[i])
        {
            C[i] = i;
            solve(row + 1);
            C[i] = 0;
        }
}
int main()
{
    solve(1);
    cout << ans << endl;
    return 0;
}
