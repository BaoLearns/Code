#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void print()
{
    system("cls");
    printf("********************************************************************************");
    printf("*                            制作者 Roye                                       *");
    printf("*                            选择菜单                                          *");
    printf("*                            输入1表示退出系统！                               *");
    printf("*                            输入2表示进入找零钱程序                           *");
    printf("********************************************************************************");

}
int main()
{
	int n,m,s;
	char op;
    print();
	while(scanf("%c",&op))
    {
        if(op=='1')
        {
            system("cls");
            getchar();
            getchar();
            exit(-1);
        }
        if(op=='2')
        {
            printf("请输入顾客付款金额：");
            scanf("%d",&n);
            printf("请输入顾客实际消费金额：");
            scanf("%d",&m);
            s=n-m;
            printf("应找零钱：%d\n\n",s);

            if(s/100!=0)
            {
                printf("100*%d+",s/100);
                s=s%100;
            }
            if(s/50!=0)
            {
                printf("50*%d+",s/50);
                s=s%50;
            }
            if(s/20!=0)
            {
                printf("20*%d+",s/20);
                s=s%20;
            }
            if(s/10!=0)
            {
                printf("10*%d+",s/10);
                s=s%10;
            }
            if(s/5!=0)
            {
                printf("5*%d+",s/5);
                s=s%5;
            }
            if(s/1!=0)
                printf("1*%d+",s/1);
            printf("\b");
            printf("=%d",n-m);
            printf("\n解释:10*1+5*1=15，即找零的钱分别是面值10元的1张，面值5元的1张，共找零钱15元\n\n");
        }
        else
        {
            printf("你输入的有错！\n");
        }
        printf("\n\n按任意键继续程序：");
        getchar();
        getchar();
        print();
    }
	return 0;
}
