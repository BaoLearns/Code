#include <iostream>
using namespace std;
int main()
{
    string st1, st2;
    cin >> st1 >> st2;
    int len = st1.length();
    int cnt = 0;
    for(int i = 0; i < len; ++i)
    {
        if(st1[i] != st2[i])
        {
            if(st1[i] == 'o') st1[i] = '*';
            else st1[i] = 'o';
            if(st1[i + 1] == 'o') st1[i + 1] = '*';
            else st1[i + 1] = 'o';
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
