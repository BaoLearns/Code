#include <stdio.h>
#include <string.h>
struct Person
{
    char name[20];
    int cot;
}leader[3]={"Li",0,"Zhang",0,"Sun",0};
int main ()
{
    int i,j;
    char leader_name[20];
    for(i=1;i<=10;i++)
    {
        scanf("%s",leader_name);
        for(j=0;j<3;j++)
            if(strcmp(leader_name,leader[j].name)==0) leader[j].cot++;
    }
    printf("the ruster:\n");
    for(j=0;j<3;j++)
        printf("name:%5s cot:%d\n",leader[j].name,leader[j].cot);
    return 0;
}
