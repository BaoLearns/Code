#include <iostream>
#include <cstring>
#define MAXN 21
using namespace std;
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n, arr[MAXN];
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        string st;
        int l = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = l; j < arr[i]; ++j)
                st += '(';
            st += ')';
            l = arr[i];
        }
        cout << st << endl;
        int len = st.length();
        bool vised[len];
        //memset(vised, false, sizeof(vised));
        for(int i = 0; i < len; ++i)
        {
            if(st[i] == ')')
            {
                int cnt = 0;
                for(int j = i - 1; j >= 0; --j)
                {
                    if(st[j] == '(')
                    {
                        cnt++;
                        if(!vised[j])
                        {
                            vised[j] = true;
                            break;
                        }
                    }
                }
                cout << cnt << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
