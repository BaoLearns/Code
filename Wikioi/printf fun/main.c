#include <stdio.h>
struct n
{
    int num;
    char name[10];
    int score[3];
}s[5];
void print(struct n s[])
{
    int i,j;
    for(i=0;i<5;i++)
    {
        printf("%d %s ",s[i].num,s[i].name);
        for(j=0;j<3;j++)
            printf("%d ",s[i].score[j]);
            printf("\n");
    }

}
int main()
{
    int i,j;
    for(i=0;i<5;i++)
    {
        scanf("%d%s",&s[i].num,s[i].name);
        for(j=0;j<3;j++)
            scanf("%d",&s[i].score[j]);
    }
    print(s);
    return 0;
}
