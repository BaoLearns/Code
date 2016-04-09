#include <iostream>
using namespace std;
int ans = 0;
void dfs(int num, int step)
{
    if(num > 39) return;
    if(num == 39)
    {
        if(step % 2 == 0)
            ans++;
        //cout << ans << endl;
        return;
    }
    dfs(num + 1, step + 1);
    dfs(num + 2, step + 1);
}
int main()
{
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}
