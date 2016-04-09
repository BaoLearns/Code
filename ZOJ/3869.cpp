#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        int cnt[1001];
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; ++i)
        {
            int e;
            cin >> e;
            cnt[e]++;
        }
        int Maxtime = 0, Max = -1, Mintime = 0, Min = -1;
        for(int i = 0; i < 1001; ++i)
        {
            if(cnt[i])
            {
                if(Maxtime <= cnt[i])
                {
                    if(Mintime <= Maxtime)
                    {
                        Min = Max;
                        Mintime = Maxtime;
                    }
                    Max = i;
                    Maxtime = cnt[i];
                }
            }
        }
        if(Mintime == Maxtime)
            cout << "Nobody" << endl;
        else
            cout << Max << endl;
        //cout << Mintime << "  " << Maxtime << endl;
    }
    return 0;
}
