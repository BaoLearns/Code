#include<stdio.h>
#include<conio.h>
#include <windows.h>
#include<string.h>
#define MAX 20
struct student
{
	char number[8];//ѧ��
	char name[8];//����
	char sex[2];//�Ա�
	int yuwen;//����
	int shuxue;//��ѧ
	int yingyu;//Ӣ��
	float sum;//�ܳɼ�
	float ave;//ƽ���ɼ�
}score[MAX+1],sc;
int num=0;

void creat()//¼��
{
	int i,n;
	printf("������Ҫ¼�����ݵĸ���:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("�������%d����¼��\n",i+1);
		scanf("%s%s%s%d%d%d",score[i].number,score[i].name,score[i].sex,&score[i].yuwen,&score[i].shuxue,&score[i].yingyu);
		num++;
	}
	printf("�����������...\n");
	getch();
}

void print()//��ʾ
{
	int i;
	for(i=0;i<num;i++)
		printf("%s %s %s %d %d %d %.2f %.2f\n",score[i].number,score[i].name,score[i].sex,score[i].yuwen,score[i].shuxue,score[i].yingyu,score[i].sum,score[i].ave);
	printf("�����ϡ�\n");
	printf("�����������...\n");
	getch();
}

void choose()//����
{
	int i;
	char s[8];
	printf("������Ҫ���ҵ�ѧ�Ż�������\n");
	getchar();
	scanf("%s",s);
	for(i=0;i<num;i++)
	{
		if((strcmp(s,score[i].number)==0) || (strcmp(s,score[i].name)==0))
		   printf("%s %s %s %d %d %d %.2f %.2f\n",score[i].number,score[i].name,score[i].sex,score[i].yuwen,score[i].shuxue,score[i].yingyu,score[i].sum,score[i].ave);

	}
	printf("�����������...\n");
	getch();
}

void sort()//����
{
	int i,j;
	for(i=0;i<num-1;i++)
	{
		for(j=0;j<num;j++)
		{
			if(score[j].ave<score[j+1].ave)
			{
				sc=score[j];
				score[j]=score[j+1];
				score[j+1]=sc;
			}
		}
	}
	printf("�������,y��ʾ���,n����ʾ���.\n");
	char s;
	scanf("%s",&s);
	if(s=='y')
	{
	   for(i=0;i<num;i++)
	   	  printf("%s %s %s %d %d %d %f %f\n",score[i].number,score[i].name,score[i].sex,score[i].yuwen,score[i].shuxue,score[i].yingyu,score[i].sum,score[i].ave);

	}
	printf("�����ϡ�\n");
	printf("�����������...\n");
	getch();
}

void tongji()//ͳ��
{
	int i;
	for(i=0;i<num;i++)
	{
		score[i].sum=float(score[i].yuwen+score[i].shuxue+score[i].yingyu);
		score[i].ave=score[i].sum/3;
	}
	printf("�����������...\n");
	getch();
}

void del()//ɾ��
{
	int i,j;
	char s[8];
	printf("������Ҫɾ���ļ�¼��ѧ��:\n");
	scanf("%s",s);
	for(i=0;i<num;i++)
	{
		if(strcmp(s,score[i].number)==0)
		{
			for(j=i;j<num;j++)
				score[j]=score[j+1];
				num--;
		}
	}
	printf("ɾ�����,y��ʾ���n����ʾ���.\n");
	char c;
	scanf("%s",&c);
	if(c=='y')
	{
	   for(i=0;i<num;i++)
	   	  printf("%s %s %s %d %d %d %.2f %.2f\n",score[i].number,score[i].name,score[i].sex,score[i].yuwen,score[i].shuxue,score[i].yingyu,score[i].sum,score[i].ave);

	}
	printf("������.\n");
	printf("�����������...\n");
	getch();
}

void add()//����
{
	printf("ѡ����Ҫ�����λ��:\n");
	int i,n;
	scanf("%d",&n);
	scanf("%s%s%s%d%d%d",sc.number,sc.name,sc.sex,&sc.yuwen,&sc.shuxue,&sc.yingyu);
	num++;
	for(i=num;i>=n;i--)
		score[i]=score[i-1];
	score[i]=sc;
	printf("�������,y��ʾ���n����ʾ���.\n");
	char c;
	scanf("%s",&c);
	if(c=='y')
	{
	   for(i=0;i<num;i++)
	   	  printf("%s %s %s %d %d %d %.2f %.2f\n",score[i].number,score[i].name,score[i].sex,score[i].yuwen,score[i].shuxue,score[i].yingyu,score[i].sum,score[i].ave);

	}
	printf("������.\n");
	printf("�����������...\n");
	getch();
}

int main()
{
	int n;
kaishi:
	printf("******************************************************************************\n");
	printf("*                                                                            *\n");
	printf("*       ----------------------------------------------------------           *\n");
	printf("*       |         ��ѡ���������:                                |           *\n");
	printf("*       |         1.һ���������������¼������.                  |           *\n");
	printf("*       |         2.��ʾ���ȫ����Ϣ.                            |           *\n");
	printf("*       |         3.����ѧ�Ż��������Ҳ���ʾ���.                |           *\n");
	printf("*       |         4.��ƽ���ɼ�����.                              |           *\n");
	printf("*       |         5.����һ����¼.                                |           *\n");
	printf("*       |         6.�����¼�Ų�ɾ���ü�¼.                      |           *\n");
	printf("*       |         7.�����Ƴɼ�ͳ��ƽ���ɼ�.                      |           *\n");
	printf("*       |         8.�˳�.                                        |           *\n");
	printf("*       ----------------------------------------------------------           *\n");
	printf("*                                                                            *\n");
	printf("******************************************************************************\n");
	scanf("%d",&n);
	switch(n)
	{
	   case 1: creat();break;
	   case 2: print();break;
	   case 3: choose();break;
	   case 4: sort();break;
	   case 5: add();break;
	   case 6: del();break;
	   case 7: tongji();break;
	   case 8: return 0;
	   default: printf("�������,����������.\n");
	}
	system("cls");
	goto kaishi;
	return 0;
}
