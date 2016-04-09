#include <iostream>
#include <string.h>
#define maxn 200030
using namespace std;
int n, k;
bool vised[maxn];
typedef struct node
{
    int x, step;
}node;
node que[maxn];
void bfs()
{
    int front = 0, rear = 0;
    que[rear].x = n;
    que[rear++].step = 0;
    vised[n] = true;
    while(front < rear && rear < maxn)
    {
        node e = que[front++];
        if(e.x == k)
        {
            cout << e.step << endl;
            return;
        }
        if(e.x <= 100010 && !vised[e.x + 1])
        {
            que[rear].x = e.x + 1;
            que[rear++].step = e.step + 1;
            vised[e.x + 1] = true;
        }
        if(e.x - 1 >= 0 && !vised[e.x - 1])
        {
            que[rear].x = e.x - 1;
            que[rear++].step = e.step + 1;
            vised[e.x - 1] = true;
        }
        if(e.x <= 100010 && !vised[e.x * 2])
        {
            que[rear].x = e.x * 2;
            que[rear++].step = e.step + 1;
            vised[e.x * 2] = true;
        }
    }
}
int main()
{
    while(cin >> n >> k)
    {
        memset(vised, false, sizeof(vised));
        bfs();
    }
    return 0;
}
