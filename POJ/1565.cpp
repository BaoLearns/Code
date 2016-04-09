#include <iostream>
using namespace std;
long long mut(int i)
{
    if(i > 1)
    {
        long long a = mut(i / 2);
        if(i % 2)
            return a * a * 2;
        return a * a;
    }
    return 2;
}
int main()
{
    string st;
    while(true)
    {
        cin>>st;
        if(st.length() == 1 && st[0] == '0')
            break;
        int len = st.length();
        long long sum = 0;
        int num = 1;
        for(int i = len - 1; i >= 0; --i)
        {
            sum += (st[i] - '0') * (mut(num++) - 1);
        }
        cout<<sum<<endl;
    }
    return 0;
}
