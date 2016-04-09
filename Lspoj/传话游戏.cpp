#include <iostream>
#include <string>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int I = 1; I <= T; ++I)
    {
        int n, m;
        cin>>n>>m;
        pair<string, string> P[105];
        for(int i = 0; i < m; ++i)
        {
            string s1, s2;
            cin>>s1>>s2;
            P[i].first = s1;
            P[i].second = s2;
        }
        string st, ans;
        getl
        while(getline(st,'\n'))
        {
            cout<<"sdfaaaaaaaaaaaaaaaaaaaaaaa"<<st<<endl;
            if(st.empty()) break;
            if(n)
            {
                while(true)
                {
                    bool flag = true;
                    for(int i = 0; i < m; ++i)
                    {
                         
                        if(P[i].first == st)
                        {
                            n--;
                            st = P[i].second;
                            flag = false;
                        }
                    }  
                    if(flag)
                        break;
                }
                ans += st;
                
            }
            else
                ans += st;
            st.clear();
        }
        cout<<ans<<endl;
    }
    return 0;
}
