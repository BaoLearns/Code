#include <cstdio>
#define MAXN 1000007
int arr[MAXN];
int que[MAXN * 10];
int read()
{
    char ch;
    int v = 0, s = 1;
    while(ch = getchar(), ch == ' ' || ch == '\n' || ch == '\t');
    if(ch == '-') s = -1;
    else v = ch - '0';
    while(ch = getchar(), ch != ' ' && ch != '\n' && ch != '\t') v = v * 10 + ch - '0';
    return v * s;
}
void write(int x, char c)
{
    char ch[10], pos = 0;
    if(x < 0) putchar('-');
    x = x > 0? x: -x;
    if(!x) putchar('0');
    while(x)
    {
        ch[pos++] = x % 10;x /= 10;
    }
    while(pos)
        putchar(ch[--pos] + '0');
    putchar(c);
}
int main()
{
    int n, k;
    while(~scanf("%d%d", &n, &k))
    {
        if(n < k) k = n;
        for(int i = 0; i < n; ++i)
            arr[i] = read();
        int front = 0, rear = -1;
        que[++rear] = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(i >= k )
            {
                write(arr[que[front]], i < n? ' ': '\n');
                if(i - que[front] >= k) front++;
            }
            while(rear >= front && arr[que[rear]] > arr[i])
                rear--;
            que[++rear] = i;
        }
        front = 0, rear = -1;
        que[++rear] = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(i >= k)
            {
                write(arr[que[front]], i < n? ' ': '\n');
                if(i - que[front] >= k) front++;
            }
            while(rear >= front && arr[que[rear]] < arr[i])
                rear--;
            que[++rear] = i;
            
        }
    }
    return 0;
}
/*
8 3
1 2 -1 5 6 -7 5 3
*/
