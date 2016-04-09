#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#define IT vector <int> :: iterator
using namespace std;
vector <int> vec;
map <int, int> Map;
set <int> Set;
int main()
{
    int P;
    while(cin >> P)
    {
        vec.clear();
        Map.clear();
        Set.clear();
        for(int i = 0; i < P; ++i)
        {
            int e;
            scanf("%d", &e);
            vec.push_back(e);
            Set.insert(e);
        }
        int Size1 = Set.size(), Size2 = 0;
        IT Begin = vec.begin(), End = vec.begin();
        int ans = P;
        while(true)
        {   
            while(Size2 < Size1 && End != vec.end())
            {
                if(Map[*End]++ == 0) Size2++;
                End++;
            }
            if(Size1 != Size2)
                break;
            int t = End - Begin;
            ans = min(ans , t);
            //cout << ans << endl;
            if(--Map[*Begin] == 0)
                Size2--;
            Begin++;
        }
        cout << ans << endl;
    }
    return 0;
}
/*
8
1 2 1 2 1 1 3 1
5
1 2 1 2 1
*/
