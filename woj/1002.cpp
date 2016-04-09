#include <iostream>
using namespace std;
int main()
{
    string st, St;
    int cnt = 0;
    cin >> st;
    St = st;
    while(cin >> st)
    {
        if('0' <= st[0] && st[0] <= '9')
        {
            cout << St << " ";
            cout << cnt << endl;
            cnt = 0;
        }
        else
            cnt++;
    }
    cout << St << " ";
    cout << cnt << endl;
    return 0;
}
