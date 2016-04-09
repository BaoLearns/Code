#include <iostream>
#define maxn 1001
using namespace std;

struct node 
{
    int data, parent, Lchild, Rchild;
}Hu[maxn];

bool Hufman()
{
    int n;
    cin >> n;
    int m = 2 * n - 1;
    for(int i = 1; i <= n; ++i)
    {
        Hu[i].data = 0;
        Hu[i].parent = Hu[i].Lchild = Hu[i].Rchild = 0;
    }
    for(int i = 1; i <= n; ++i)
        cin >> Hu[i].data;
    for(int i = n + 1; i <= m; ++i)
    {
        int Max1 = 10000000, Max2 = 10000000;
        int pos1 = 1, pos2 = 1;
        for(int j = 1; j < i; ++j)
        {
            if(!Hu[j].parent)
            {
                if(Hu[j].data < Max1)
                {
                    Max2 = Max1;
                    Max1 = Hu[j].data;
                    pos2 = pos1;
                    pos1 = j;
                }
                else if(Hu[j].data < Max2)
                {
                    Max2 = Hu[j].data;
                    pos2 = j;
                }
            }
        }
        Hu[i].data = Max1 + Max2;
        Hu[i].Lchild = pos2;
        Hu[i].Rchild = pos1;
        Hu[pos1].parent = Hu[pos2].parent = i;
    }
    for(int i = 1; i <= m; ++i)
        cout << Hu[i].data << endl;
    int sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        int times = 0;
        int j = i;
        while(Hu[j].parent)
        {
            times++;
            j = Hu[j].parent;

        }
        sum += times * Hu[i].data;
    }
    cout << "WPL is " << sum << endl;
}
int main()
{
    Hufman();
    return 0;
}
/*
5
2 9 7 12 6


*/
