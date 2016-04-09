#include <bits\stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    printf("0\n");
    for(int i = 1; i < (1 << n); ++i)
    {
        vector <int> vec;
        for(int j = 0; j < n; ++j)
        {
            if((i >> j) & 1)
                vec.push_back(j + 1);
        }
        for(vector <int> :: iterator it = vec.begin(); it != vec.end(); ++it)
            printf("%d ", *it);
        putchar('\n');
    }
    return 0;
}
