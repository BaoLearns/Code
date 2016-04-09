/*#include <bits/stdc++.h>
using namespace std;
string  st = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLNMOPQRSTUVWXYZ0123456789`~!@#$%^&*()-_+=[]{}\\|;:\"',<.>/?";
bool solve(string In, int w, string &ans)
{
    if(w == In.length()) return true;
    int len = st.length();
    for(int i = 0; i < len; ++i)
    {
        if(In[w] == st[i])
        {
            ans += st[i];
            solve(In, w + 1, ans);    
        }
    }
}
int main()
{
    string In;
    while(cin >> In)
    {
        string ans;
        if(solve(In, 0, ans))
            cout << ans << endl;
    }
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
vector <string> vec{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
bool flag = false;
void solve(string In, string ans)
{
    if(flag) return;
    if(ans.length() == 8)
    {
        if(In == ans)
            flag = true;
        return;
    }
    for(vector <int> :: iterator it = vec.begin(); it != vec.end(); ++it)
    {   
        
    }

}
int main()
{
    string In;
    while(cin >> In)
    {
        solve(In);
    }
    return 0;
}
