#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int t;
    cin >> t;
    getchar();
    while(t--)
    {
        string st;
        getline(cin, st);
        //cout << st << endl;
        string st1;
        for(int i = 0; i < st.length(); ++i)
        {
            if(('a' <= st[i] && st[i] <= 'z') || ('A' <= st[i] && st[i] <= 'Z'))
                st1 += st[i];
        }
        st = st1;
        //cout << st << endl;
        bool flag = false;
        int len = st.length();
        for(int i = 1; i <= (len - 2) / 3; ++i) //ABABA
        {
            int len1 = (len - 3 * i) / 2;
            //cout << i << " " << len1 << endl;
            string A = st.substr(0, i), B = st.substr(i, len1);
            string C = st.substr(len1 + i, i), D = st.substr(len1 + i * 2, len1), E = st.substr(len1 * 2 + i * 2, i);
            //cout << A << " " << B << " " << C << " " << D << " " << E << endl;
            if(A != B && A == C && A == E && C == E && B == D && A.size() && B.size() && A.size() + B.size() + C.size() + D.size() + E.size() == len)
            {
                flag = true;
                break;
            }
        }
        for(int i = 1; i <= (len - 4) / 3 && !flag; ++i)//ABABCAB
        {
            for(int j = 1; j <= (len - 3 * i - 1) / 3 && !flag; ++j)
            {
                int len1 = len - 3 * i - 3 * j;
                //cout << i << " " << j << " " << len1 << endl;
                string A = st.substr(0, i), B = st.substr(i, j), C = st.substr(i + j, i), D = st.substr(2 * i + j, j), E = st.substr(2 * i + 2 * j, len1);
                string F = st.substr(2 * i + 2 * j + len1, i), G = st.substr(3 * i + 2 * j + len1, j);
                //cout << A << " " << B << " " << C << " " << D << " " << E << " " << F << " " << G << endl;
                if(A != B && A != E && B != E && A == C && A == F && C == F && B == D && B == G && D == G && A.size() + B.size() + C.size() + D.size() + E.size() + F.size() + G.size() == len)
                {
                    flag = true;
                    break;
                }
            }
        }
        puts(flag? "Yes": "No");
    }
    return 0;
}
