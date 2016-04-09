#include <bits/stdc++.h>
using namespace std;
int main()
{
    /*const string st("I love C++ language!");
    string st1(st, 2, 4);
    cout << st1 << endl;
    string st2 = st1;
    st2.append(" the girl");
    cout << st2 << endl;
    string st3 = st2;
    st3.assign(st);
    cout << st3 << endl;
    string st4 = st3;
    st4.erase(2, 5);
    cout << st4 << endl;
    string st5 = st4;
    st5.insert(2, st3.substr(2,5));
    cout << st5 << endl;
    string st6 = st5;
    st5.replace(2, 4, "like");
    cout << st5 << endl;
    string A("I love C++");
    cout << A.substr(2, 3) << endl;
    //freopen("test.txt", "r", stdin);*/
    string st("I love c plus plus");
    const char* ch = st.c_str();
    cout << ch << endl;
    string st1 = st.data();
    cout << st1 << endl;
    char* p = new char[100];
    st.copy(p, 4, 0);
    cout << p << endl;
    cout << st.max_size() << endl;
    vector <int> vec;
    cout << vec.max_size() << endl;
    return 0;
}
