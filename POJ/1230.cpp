#include <iostream>
#include <cstring>
#define MAXN 10001
using namespace std;
int col[MAXN];
int arr[MAXN][2];
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        memset(col, 0, sizeof col);
        int n, k;
        cin >> n >> k;
        for(int i = 0; i < n; ++i)
        {
            int a, b, c, d; 
            cin >> a >> b >> c >> d;
            arr[i][0] = min(a, c);
            arr[i][1] = max(a, c);
            for(int j = arr[i][0]; j <= arr[i][1]; ++j)
                col[j]++;
        }
        int cnt = 0;
        while(true)
        {
            bool flag = true;
            for(int i = 0; i < MAXN; ++i)
            {
                if(col[i] > k)
                {
                    flag = false;
                    break;
                }
            }
            //cout << "!!!" << endl;
            if(!flag)
            {
                int Max = 0, pos = 0, len;
                for(int i = 0; i < n; ++i)
                {
                    if(arr[i][0] != -1)
                    {
                        int num = 0;
                        for(int j = arr[i][0]; j <= arr[i][1]; ++j)
                        {
                            if(col[j] > k)
                                num++;
                        }
                        if(num > Max)
                        {
                            Max = num;
                            pos = i;
                            len = arr[i][1] - arr[i][0];
                        }
                        else if(num == Max && arr[i][1] - arr[i][0] > len)
                        {
                            pos = i;
                            len = arr[i][1] - arr[i][0];
                        }
                    }
                }
                //cout << Max << "   " << pos << endl;
                cnt++;
                for(int i = arr[pos][0]; i <= arr[pos][1]; ++i)
                    col[i]--;
                arr[pos][0] = arr[pos][1] = -1;
                cout << pos << endl;
            }
            else break;
        }
        cout << cnt << endl;

    }


    return 0;
}
/*
5

4 1
0 3 9 3
0 0 3 0
4 0 7 0
3 2 6 2


3 0
3 0 0 0
6 1 8 1
2 3 6 3

7 3
3 0 0 0
6 1 8 1
2 3 6 3
4 4 6 4
0 5 1 5
5 6 7 6
1 7 3 7

8 2
0 0 0 0
0 1 0 1
5 0 5 0
5 1 5 1
1 1 4 1
0 2 2 2
3 2 5 2
1 3 4 3

3 1
2 0 4 0
0 1 1 1
1 2 2 2
*/
