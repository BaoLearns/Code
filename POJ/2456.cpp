#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 2000000000
using namespace std;
vector <int> arr;
int N, C;    
bool Success(int v)
{
    int l = 0, r = 1, cnt = 0;
    while(r < N)
    {
        r = l + 1;
        while(r < N && arr[r] - arr[l] < v)
            r++;
        cnt++;
        l = r;
    }
    return C <= cnt;
}
int main()
{
    while(scanf("%d%d", &N, &C) != EOF)
    {
        //arr.resize(N, 0);
        arr.clear();
        int e;
        for(int i = 0; i < N; ++i)
        {
            scanf("%d", &e);
            arr.push_back(e);
        }
        sort(arr.begin(), arr.end());
        int start = 0, end = INF;
        while(end - start > 1)
        {
            int mid = start + (end - start) / 2;
            if(Success(mid)) start = mid;
            else end = mid;
        }
        printf("%d\n", start);
    }
    return 0;
}
