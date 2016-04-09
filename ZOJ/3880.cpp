#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n, num = 0;
        cin >> n;
        for(int i = 0; i < n; ++i)
        {
            int e;
            cin >> e;
            if(e > 6000)
                num++;
        }
        cout << num << endl;
    }
    return 0;
}
