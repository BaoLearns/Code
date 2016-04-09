/*
 * 单词的全排列
 * 输入一个字符串，求解这个字符串的全排列
 * 
*/
#include <cstdio>
#include <cstring>
char arr[20];
void find(int *hash,int len, int m)
{
    if(len == m)
    {
        printf("%s\n", arr);
        return ;
    }
    bool flag = true;
    for(int i = 65; i < 123; ++i)
    {
        if(i > 91 && flag)
        {
            i = 97;
            flag = false;
        }
        if(hash[i])        {
            arr[m] = char(i);
            hash[i]--;
            find(hash, len, m + 1);
            hash[i]++;
        }
    }

}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        char st[20];
        scanf("%s", st);
        int hash[200];
        memset( hash, 0, sizeof( hash));
        int len = strlen( st);
        for( int i = 0; i < len; ++i)
            hash[( int) st[i]]++;
        for( int i = 0; i < 20; ++i)
            arr[i] = '\0';
        find(hash, len, 0);
    }
    return 0;
}

