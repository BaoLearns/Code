
#include <stdio.h>
int main()
{
    printf("不重复选择：\n");
    char *a[5]={"red","yellow","blue","white","black"};
    int i,j,k,num=0;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(i==j) break;
            for(k=0;k<5;k++)
            {
                if(j==k ) break;
                if(i!=j && j!=k && i!=k)
                printf("%-2d %-6s %-6s %-6s\n",++num,a[i],a[j],a[k]);
            }
        }
    }

    printf("可重复选择");
    printf("\n");
    char *b[5]={"red","yellow","blue","white","black"};
    int i1,j1,k1,num1=0;
    for(i1=0;i1<5;i1++)
    {
        for(j1=0;j1<5;j1++)
        {
            for(k1=0;k1<5;k1++)
                if(i1!=j1 && j1!=k1 && i1!=k1)
                printf("%-2d %-6s %-6s %-6s\n",++num1,b[i1],b[j1],b[k1]);
        }
    }
    return 0;
}
