#include <stdio.h>
struct pr
{
    char number[20];
    char name[20];
    float score;
}xinxi[4]={"01","zhang",90,"02","zhu",85,"03","bao",95,"04","tang",75};
int main()
{
    struct pr t;
    int i,j;
    for(i=0;i<4;i++)
        for(j=i+1;j<4;j++)
        if(xinxi[i].score<xinxi[j].score) t=xinxi[i],xinxi[i]=xinxi[j],xinxi[j]=t;
    for(i=0;i<4;i++)
    printf("number:%2s  name:%5s  score:%lf\n",xinxi[i].number,xinxi[i].name,xinxi[i].score);
    return 0;
}
