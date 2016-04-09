#include <iostream>
#define maxn 200005
using namespace std;
int hash[maxn];
int main()
{
    int n, m, k;
    string a, b;
    cin >> n >> m >> k >> a >> b;
    for(int i = 0; i < n; ++i)
    {
        int num = 0;
        for(int j = 0; j < m && i + j < n; ++j)
            if(a[i + j] == b[j])
                num++;
        hash[num]++;
    }
    while(k--)
    {
        int x;
        cin >> x;
        cout << hash[x] << endl;
    }
    return 0;
}
