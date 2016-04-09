#include <iostream>
using namespace std;
int main()
{
    int sum = 0, start = 1;
    for(int i = 1; ; i += 2)
    {
        sum += i;
        while(sum > 111 * 111 * 111)
        {
            sum -= start;
            start += 2;
        }
        if(sum == 111 * 111 * 111) break;
    }
    cout << start << endl;
    return 0;
}
