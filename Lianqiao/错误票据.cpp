#include <iostream>
#define maxn 100001
using namespace std;
int hash[maxn];
int main()
{
    int n;
    cin >> n;
    int Min = 10000000, Max = -1;
    for(int i = 0; i <= n; ++i)
    {
        string st;
        getline(cin, st);
        st += ' ';
        int len = st.length();
        int k = 0;
        int e = 0;
        while(k < len)
        {
            if(st[k] == ' ')
            {
                hash[e]++;
                if(e > Max) Max = e;
                if(e < Min) Min = e;
                e = 0;
            }
            else
                e = e * 10 + st[k] - '0';
            k++;
        }
        st.clear();
    }
    int ans1, ans2;
    for(int i = Min; i <= Max; ++i)
    {
        if(hash[i] == 0)
            ans1 = i;
        if(hash[i] == 2)
            ans2 = i;
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
