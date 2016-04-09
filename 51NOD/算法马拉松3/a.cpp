#include <iostream>
#include <map>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        map <int, int> Map;
        for(int i = 0; i < n; ++i)
        {
            int e;
            cin >> e;
            Map[e]++;
        }
        bool flag = true;
        for(map <int, int>::iterator it = Map.begin(); it != Map.end(); ++it)
            if(it->second != 2)
            {
                flag = false;
                break;
            }
        puts(flag?"Good job!!": "What a pity!");
    }
    return 0;
}
