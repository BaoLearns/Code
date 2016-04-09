#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string str;
    int k;
    cin >> str >> k;
    int len = str.length();
    int pos = 0;
    while (k && pos < len)
    {
        int mx = 0, mx_pos = pos;
        for (int i = pos; i < len && (i - pos) < k; ++i)
            if (str[i] - '0' > mx)
            {
                mx = str[i] - '0';
                mx_pos = i;
            }
        for (int i = mx_pos; i > pos; --i)
        {
            char temp = str[i];
            str[i] = str[i - 1];
            str[i - 1] = temp;
            k--;
        }
        pos++;
    }
    cout << str << endl;
    return 0;
}
