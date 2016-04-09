#include <iostream>
#include <cmath>
#define LL long long
#define INF 100000000000007
using namespace std;
int main()
{/*
    LL cnt = 0, sum = 0, pos = 1;
    while (true) {
        sum += pos;
        pos++;
        double a = 1, b = 2 * pos + 1, c = -2 * sum;
        if (b * b - 4 * a * c >= 0) {
            double ans = (-b + sqrt(b * b - 4 * a * c)) / 2;
            if ((int)ans == ans && ans >= 0) {
                printf("num[%d][0] = %lld, num[%d][1] = %lld;\n", cnt, pos, cnt, pos + (int)ans);
                cnt++;
            }
        }
        if (cnt >= 10) break;
    }
    */
    LL cnt = 0, s = 6;
    while(cnt < 1)
    {
        LL val = 2 * s * s;
        LL start = 1, end = INF;
        while(end - start > 1)
        {
            LL mid = start + (end - start) / 2;
            LL v = mid * mid + mid;
            if(v == val)
            {
                printf("%10d%10d\n", s, mid);
                cnt++;
                break;
            
            }
            if(v > val) end = mid;
            else start = mid;
            cout << start << " " << end << endl;
        }
        s++;
    }
    int num[10][2];
    num[0][0] = 6, num[0][1] = 8;
    num[1][0] = 35, num[1][1] = 49;
    num[2][0] = 204, num[2][1] = 288;
    num[3][0] = 1189, num[3][1] = 1681;
    num[4][0] = 6930, num[4][1] = 9800;
    num[5][0] = 40391, num[5][1] = 57121;
    num[6][0] = 235416, num[6][1] = 332928;
    num[7][0] = 1372105, num[7][1] = 1940449;
    num[8][0] = 7997214, num[8][1] = 11309768;
    num[9][0] = 46611179, num[9][1] = 65918161;
    for(int i = 0; i < 10; ++i)
        printf("%10d%10d\n", num[i][0], num[i][1]);
    return 0;
}
