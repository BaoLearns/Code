//测试时间的函数
#include <bits/stdc++.h>
using namespace std;
int main()
{
    clock_t start, end;
    start = clock();
    long long s = 0;
    for(int i = 0; i < 100000000; ++i) s += i;
    end = clock();
    double Times = 1.0 * (end - start);  
    cout << Times << endl;  
    return 0;
}
