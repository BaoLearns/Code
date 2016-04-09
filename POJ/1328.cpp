#include <iostream>
#include <cmath>
#include <algorithm>
#define maxn 1001
using namespace std;
typedef struct 
{
    int x, y;
}P;
P arr[maxn];
bool cmp(P p1, P p2)
{
    return p1.x < p2.x;
}
double Dis(int  d, int  val)
{
    return sqrt((double)(d * d - val * val));
}
int main()
{
    int n, d;
    int Times = 0;
    while( cin >> n >> d && (n != 0 || d != 0))
    {
        ++Times;
        bool flag = true;
        for(int i = 0; i < n; ++i)
        {
            cin >> arr[i].x >> arr[i].y;
            if(arr[i].y > d)
                flag = false;
        }
        if(!flag)
        {
            cout << "Case " << Times << ": " << -1 << endl;
            continue;
        }
        sort(arr, arr + n, cmp);
        double S = Dis(d, arr[0].y);
        double L = arr[0].x - S;
        double R = arr[0].x + S;
        int ans = 1;
        for(int i = 1; i < n; ++i)
        {
            S = Dis(d, arr[i].y);
            if(arr[i].x - S <= R)
            {
                L = max(arr[i].x - S, L);
                R = min(arr[i].x + S, R);
            } 
            else
            {
                ans++;
                L = arr[i].x - S;
                R = arr[i].x + S;
            }
        }
        cout << "Case " << Times << ": " << ans << endl;
    }
    return 0;
}
