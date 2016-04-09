#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string st;
    string ch1 = "``", ch2 = "''", ch3 = "`";
    bool flag1 = true, flag2 = true;
    while(getline(cin, st))
    {
        int len = st.size();
        for(int i = 0; i < len; ++i)
        {
            if(st[i] == '"')
            {
                cout << (flag1? ch1: ch2);
                flag1 = !flag1;
            }
            else if(st[i] == '\'')
            {
                if(flag2)
                    cout << ch3;
                else cout << st[i];
                flag2 = !flag2;
            }
            else cout << st[i];
        }
        cout << endl;
    }
    return 0;
}
