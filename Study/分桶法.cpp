#include <iostream>
#include <vector>
#include <cmath>
#define maxn 100004
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector <int> vec1, vec2;
    int d = floor((double)sqrt((double)n));
    int Min = maxn;
    for(int i = 0; i < n; ++i)
    {
        int e;
        cin >> e;
        vec1.push_back(e);
        Min = min(Min, e);
        if(i % d == (d - 1) || i == n - 1)
        {
            vec2.push_back(Min);
            Min = maxn;
        }
    }
    for(auto it : vec2)
        cout << it << endl;
    return 0;
}
