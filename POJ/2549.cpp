#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{   
    int n;
    while(cin >> n, n)
    {
        vector <int> vec1, vec2;
        for(int i = 0; i < n; ++i)
        {
            int e;
            cin >> e;
            vec1.push_back(e);
        }
        sort(vec1.begin(), vec1.end());
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
                vec2.push_back(vec1[i] + vec1[j]);
        }
        sort(vec2.begin(), vec2.end());
        bool flag = true;
        int ans = -536870912;
        for(int i = n - 1; i >= 0; --i)
        {
            for(int j = i - 1; j >= 0; --j)
            {
                int s = vec1[i] - vec1[j];
                int val = *lower_bound(vec2.begin(), vec2.end(), s);
                //cout << "!!!! " << val << " " << s << endl;
                if(s == val)
                {
                    flag = false;
                    ans = max(ans, vec1[i]);
                } 
            }
        }
        if(flag || n < 4) cout << "no solution" << endl;
        else cout << ans << endl;
    }
    return 0;
}
/*
10
2 5 2 9 5 1 2 7 1 1
*/
