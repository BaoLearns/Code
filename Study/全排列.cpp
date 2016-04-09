/*
 * 全排列
 * 输入n，表示n个shu
 * 输入这n个数
 * 输出者n个数的全排列
*/

#include <cstdio>
#include <cstdlib>
int hash[11];
//find（n，a，m），n表示这个全排列有n位，a表示当前的大小，m表示当前有几位
void find(int n, int a, int m)
{
    if(m == n)
    {
        printf("%d\n",a);
        return;
    }
    for(int i = 0; i < 10; ++i)
    {
        if(hash[i])
        {
            hash[i]--;
            find(n, a * 10 + i, m + 1);
            hash[i]++;
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        int e;
        scanf("%d", &e);
        hash[e]++;
    }
    find(n, 0, 0);
    return 0;
}


