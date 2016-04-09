#include <iostream>
using namespace std;
int arr[13];
bool vised[13];
bool Equal()
{
    int v[7];
    v[1] = arr[1] + arr[3] + arr[6] + arr[8];
    v[2] = arr[1] + arr[4] + arr[7] + arr[12];
    v[3] = arr[8] + arr[9] + arr[11] + arr[12];
    v[4] = arr[2] + arr[3] + arr[4] + arr[5];
    v[5] = arr[2] + arr[6] + arr[9] + arr[10];
    v[6] = arr[5] + arr[7] + arr[10] + arr[11];
    for(int i = 2; i < 7; ++i)
            if(v[1] != v[i])
            return false;
    return true;
}
void dfs(int cnt)
{
    if(cnt == 13)
    {
        if(Equal())
        {
            for(int i = 1; i < 13; ++i)
                cout << arr[i] << " ";
            cout << endl; 
        }
        //cout << "arrived" << endl;
        return ;
    }
    if(cnt == 1 || cnt == 2 || cnt == 10)
    {
        dfs(cnt + 1);
        return;
    }
    for(int i = 1; i < 13; ++i)
    {
        if(!vised[i])
        {
            vised[i] = true;
            arr[cnt] = i;
            dfs(cnt + 1);
            vised[i] = false;
        }
    }
}
int main()
{
    arr[1] = 1;
    arr[2] = 8;
    arr[10] = 3;
    vised[1] = vised[8] = vised[3] = true;
    dfs(2);
    return 0;
}
