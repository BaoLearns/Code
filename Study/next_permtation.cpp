#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int main()
{
    char ch[100];
    cin >> ch;
    int len = strlen(ch);
    do
    {
        for(int i = 0; i < len; ++i)
            putchar(ch[i]);
        cout << endl;
    }while(next_permutation(ch, ch + len));
    return 0;
}
