#include <iostream>
#include <cstring>
#define maxn 55
using namespace std;
int arr[maxn];
void Calcfact(int N)
{
    memset(arr, 0, sizeof(arr));
    arr[50] = 1;
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 0; j <= 50; ++j)
            arr[j] *= i;
        for(int j = 50; j >= 0; --j)
        {
            if(arr[j] > 9)
            {
                arr[j - 1] += arr[j] / 10;
                arr[j] %= 10;
            }
        }
    }
    int pos = 0;
    while(arr[pos] == 0)
        pos++;
    while(pos <= 50)
        cout << arr[pos++];
    cout << endl;
}
int main()
{
    int N;
    while(cin >> N)
        Calcfact(N); //¼ÆËãNµÄ½×³Ë
    return 0;
}
