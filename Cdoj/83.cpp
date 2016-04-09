#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#define vii vector <int>
using namespace std;
int main()
{
    int T;
    cin >> T;
    getchar();
    for(int I = 1; I <= T; ++I)
    {
        string st;
        getline(cin, st);
        vii vec;
        for(int i = 0; i < st.length(); i += 2)
            vec.push_back((int)(st[i] - '0'));
        sort(vec.begin(), vec.end());
        printf("Case #%d:\n", I);
        do
        {
            for(int i = 0; i < vec.size(); ++i)
            {
                cout << vec[i];
                if(i != vec.size() - 1) cout << " ";
            }
            cout << endl;
        }while(next_permutation(vec.begin(), vec.end()));
    }
    return 0;
}
