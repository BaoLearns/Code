#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void print()
{
    system("cls");
    printf("********************************************************************************");
    printf("*                            ������ Roye                                       *");
    printf("*                            ѡ��˵�                                          *");
    printf("*                            ����1��ʾ�˳�ϵͳ��                               *");
    printf("*                            ����2��ʾ��������Ǯ����                           *");
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
            printf("������˿͸����");
            scanf("%d",&n);
            printf("������˿�ʵ�����ѽ�");
            scanf("%d",&m);
            s=n-m;
            printf("Ӧ����Ǯ��%d\n\n",s);

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
            printf("\n����:10*1+5*1=15���������Ǯ�ֱ�����ֵ10Ԫ��1�ţ���ֵ5Ԫ��1�ţ�������Ǯ15Ԫ\n\n");
        }
        else
        {
            printf("��������д�\n");
        }
        printf("\n\n���������������");
        getchar();
        getchar();
        print();
    }
	return 0;
}
