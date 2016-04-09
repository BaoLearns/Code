#include <iostream>
#include <cstdio>
#include <stdlib.h>
#define size 3
using namespace std;
struct node
{
    char name[10];
    int num;
    int age;
    char add[15];
}inf[size];
int main()
{
    printf("%d\n",sizeof(node));
    printf("name  num  age garden \n");
    /*for(int i = 0; i < size; ++i)
        scanf("%s%d%d%s",inf[i].name,&inf[i].num,&inf[i].age,inf[i].add);
    for(int i = 0; i < size; ++i)
        printf("%s%d%d%s\n",inf[i].name,inf[i].num,inf[i].age,inf[i].add);*/
    FILE * ft;
    if((ft=fopen("file.dat","rb"))==NULL)

       printf("eroor\n");
    /*for(int i = 0; i < size; ++i)
        {
            if(fwrite((&inf[i]),sizeof(struct node),1,ft)!=1)
                {
                    printf("eroor\n");
                    exit(-1);
                }
                fputs("\n",ft);
        }*/
    for( int i = 0; i < size; ++i)
    {
        fread(&inf[i],sizeof(struct node),1,ft);
        printf("%-10s%5d%5d%15s\n",inf[i].name,inf[i].num,inf[i].age,inf[i].add);
    }

    fclose(ft);
    return 0;
}
