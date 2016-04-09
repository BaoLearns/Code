#include <iostream>
using namespace std;
char st[1000001];
int main()
{
    int n;
    while(cin >> n)
    {
        for(int i = 0; i < n; ++i)
        cin>> st[i];
    int L = 0, R = n - 1;
    int num = 0;
    while(L <= R)
    {
        if(st[L] < st[R])
        {
            cout << st[L];
            L++;
        }
        else if(st[L] > st[R])
        {
            cout << st[R];
            R--;
        }
        else
        {
            int l = L, r = R;
            while(st[l] == st[r] && l <= r)
                l++,r--;
            if(st[l] < st[r])
            {
                cout << st[L];
                L++;
            }
            else
            {
                cout << st[R];
                R--;
            }
        }
        num++;
        if(num % 80 == 0) cout << endl;
    }}
    return 0;
}
