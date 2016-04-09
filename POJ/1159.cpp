#include <iostream>
using namespace std;
int main()
{
    int n;
    string st;
    while(cin>>n>>st)
    {
        int len = st.length();
        int num = 0;
        for(int i = 0; i < n / 2; ++i)
            if(st[i] != st[n - i - 1])
                num++;
        cout<<num<<endl;
    
    }
    return 0;
}
