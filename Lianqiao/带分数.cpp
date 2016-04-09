#include <iostream>
using namespace std;
bool hash[10];
int ans = 0;
void dfs(int n, int num, int arr[])
{
    if(num == 9)
    {
        for(int pos1 = 1; pos1 < 7; ++pos1) // 加号的位置 
        {
            int val1 = 0, val2 = 0, val3 = 0;
            for(int i = 0; i < pos1; ++i) //加号左边的值
                 val1 = val1 * 10 + arr[i];
            for(int pos2 = pos1 + 1; pos2 < 9; ++pos2) //除号的位置
            {
                val2 = val3 = 0;
                for(int i = pos1; i < pos2; ++i)
                    val2 = val2 * 10 + arr[i];

                for(int i = pos2; i < 9; ++i)
                    val3 = val3 * 10 + arr[i];
                if(val3 != 0 && val2 % val3 == 0 && val1 + val2 / val3 == n)
                    ans++;
                //printf("%d %d %d\n", val1, val2, val3);
            }
        }
        return ;
    }
    for(int i = 1; i < 10; ++i)
    {
        if(!hash[i])
        {
            hash[i] = true;
            arr[num] = i;
            dfs(n, num + 1, arr);
            hash[i] = false;
        }
    }
}
int main()
{
    //freopen("test.txt", "w", stdout);
    int n, arr[10];
    cin >> n;
    dfs(n, 0, arr);
    cout << ans << endl;
    return 0;
}
