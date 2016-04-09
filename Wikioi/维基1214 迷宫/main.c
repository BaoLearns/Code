#include <stdio.h>
struct stack
{
    int x;
    int y;
}stack[ 100];
int main()
{
    int m,n;
    scanf("%d",&m);
    char maze[17][17];
    while(m--)
    {
        int top = -1;
        int dx=1,dy=1;
        stack[ top].x = stack[ ++top].y = 1;
        int i,j;
        for(i=0;i<17;++i)
            for(j=0;j<17;++j)
                maze[i][j]='#';
        scanf("%d",&n);
        for(i=0;i<=n;++i)
            gets(maze[i]+1);
        while(1)
        {
            if(stack[top].x == n && stack[top].y == n)
            {
                printf("YES\n");
                break;
            }
            if(top<0)
            {
                printf("NO\n");
                break;
            }

            if(maze[dx][dy+1] =='.' || maze[dx][dy+1]=='e')
            {
                ++dy;
                maze[ dx][ dy] = 2;
                stack[ ++top].x = dx;
                stack[ top].y = dy;
                continue;
            }
            if(maze[dx+1][dy] =='.'||maze[dx+1][dy]=='e')
            {
                ++dx;
                maze[ dx][ dy] = 2;
                stack[ ++top].x = dx;
                stack[ top].y = dy;
                continue;
            }
            if(maze[dx][dy-1] =='.'||maze[dx][dy-1]=='e')
            {
                --dy;
                maze[ dx][ dy] = 2;
                stack[ ++top].x = dx;
                stack[ top].y = dy;
                continue;
            }
            if(maze[dx-1][dy] =='.'||maze[dx-1][dy]=='e')
            {
                --dx;
                maze[ dx][ dy] = 2;
                stack[ ++top].x = dx;
                stack[ top].y = dy;
                continue;
            }
        --top;
        dx=stack[top].x;
        dy=stack[top].y;
        }
    }
    return 0;
}
