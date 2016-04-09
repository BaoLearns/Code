#include <iostream>
#include <vector>
using namespace std;
vector <int> vec;
int main()
{
    int n;
    while(cin >> n, n)
    {
        vec.clear();
        for(int i = 0; i < n; ++i)
        {
            int e;
            cin >> e;
            vec.push_back(e);
        }
        int cnt = 0;
        while(true)
        {
            bool flag = false;
            //for(int i = 0; i < n; ++i)
              //  cout << vec[i] << " ";
            //cout << endl;
            for(int i = 1; i < n; ++i)
                if(vec[0] != vec[i])
                {
                    flag = true;
                    break;
                }
            if(!flag) break;
            cnt++;
            int temp = vec[n - 1] / 2;
            for(int i = n - 1; i > 0; --i) {
                int t = vec[i - 1] / 2;
                if (temp & 1) t++;
                vec[i] += t;
                vec[i- 1] -= t;
            }
            if (temp & 1) temp++;
            vec[0] += temp;
            vec[n - 1] -= temp;
            for(int i = 0; i < n; ++i)
                if(vec[i] & 1) vec[i] += 1;
        }
        cout << cnt << " " << vec[0] << endl;
    }
    return 0;
}
