#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x[10], *p = x;
    cout << sizeof(x) / sizeof(*x) << endl;
    cout << sizeof(p) / sizeof(*p) << endl;
    cout << sizeof(p) << endl; 
    return 0;
}
