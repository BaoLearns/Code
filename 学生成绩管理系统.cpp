#include<stdio.h>
#include<conio.h>
#include <windows.h>
#include<string.h>
#define MAX 20
struct student
{
	char number[8];//学号
	char name[8];//姓名
	char sex[2];//性别
	int yuwen;//语文
	int shuxue;//数学
	int yingyu;//英语
	float sum;//总成绩
	float ave;//平均成绩
}score[MAX+1],sc;
int num=0;

void creat()//录入
{
	int i,n;
	printf("请输入要录入数据的个数:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("请输入第%d条记录。\n",i+1);
		scanf("%s%s%s%d%d%d",score[i].number,score[i].name,score[i].sex,&score[i].yuwen,&score[i].shuxue,&score[i].yingyu);
		num++;
	}
	printf("按任意键继续...\n");
	getch();
}

void print()//显示
{
	int i;
	for(i=0;i<num;i++)
		printf("%s %s %s %d %d %d %.2f %.2f\n",score[i].number,score[i].name,score[i].sex,score[i].yuwen,score[i].shuxue,score[i].yingyu,score[i].sum,score[i].ave);
	printf("输出完毕。\n");
	printf("按任意键继续...\n");
	getch();
}

void choose()//查找
{
	int i;
	char s[8];
	printf("请输入要查找的学号或姓名。\n");
	getchar();
	scanf("%s",s);
	for(i=0;i<num;i++)
	{
		if((strcmp(s,score[i].number)==0) || (strcmp(s,score[i].name)==0))
		   printf("%s %s %s %d %d %d %.2f %.2f\n",score[i].number,score[i].name,score[i].sex,score[i].yuwen,score[i].shuxue,score[i].yingyu,score[i].sum,score[i].ave);

	}
	printf("按任意键继续...\n");
	getch();
}

void sort()//排序
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
	printf("排序完成,y显示结果,n不显示结果.\n");
	char s;
	scanf("%s",&s);
	if(s=='y')
	{
	   for(i=0;i<num;i++)
	   	  printf("%s %s %s %d %d %d %f %f\n",score[i].number,score[i].name,score[i].sex,score[i].yuwen,score[i].shuxue,score[i].yingyu,score[i].sum,score[i].ave);

	}
	printf("输出完毕。\n");
	printf("按任意键继续...\n");
	getch();
}

void tongji()//统计
{
	int i;
	for(i=0;i<num;i++)
	{
		score[i].sum=float(score[i].yuwen+score[i].shuxue+score[i].yingyu);
		score[i].ave=score[i].sum/3;
	}
	printf("按任意键继续...\n");
	getch();
}

void del()//删除
{
	int i,j;
	char s[8];
	printf("请输入要删除的记录的学号:\n");
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
	printf("删除完毕,y显示结果n不显示结果.\n");
	char c;
	scanf("%s",&c);
	if(c=='y')
	{
	   for(i=0;i<num;i++)
	   	  printf("%s %s %s %d %d %d %.2f %.2f\n",score[i].number,score[i].name,score[i].sex,score[i].yuwen,score[i].shuxue,score[i].yingyu,score[i].sum,score[i].ave);

	}
	printf("输出完毕.\n");
	printf("按任意键继续...\n");
	getch();
}

void add()//插入
{
	printf("选择你要插入的位置:\n");
	int i,n;
	scanf("%d",&n);
	scanf("%s%s%s%d%d%d",sc.number,sc.name,sc.sex,&sc.yuwen,&sc.shuxue,&sc.yingyu);
	num++;
	for(i=num;i>=n;i--)
		score[i]=score[i-1];
	score[i]=sc;
	printf("插入完毕,y显示结果n不显示结果.\n");
	char c;
	scanf("%s",&c);
	if(c=='y')
	{
	   for(i=0;i<num;i++)
	   	  printf("%s %s %s %d %d %d %.2f %.2f\n",score[i].number,score[i].name,score[i].sex,score[i].yuwen,score[i].shuxue,score[i].yingyu,score[i].sum,score[i].ave);

	}
	printf("输出完毕.\n");
	printf("按任意键继续...\n");
	getch();
}

int main()
{
	int n;
kaishi:
	printf("******************************************************************************\n");
	printf("*                                                                            *\n");
	printf("*       ----------------------------------------------------------           *\n");
	printf("*       |         请选择操作类型:                                |           *\n");
	printf("*       |         1.一次性完成若干条记录的输入.                  |           *\n");
	printf("*       |         2.显示输出全部信息.                            |           *\n");
	printf("*       |         3.输入学号或姓名查找并显示结果.                |           *\n");
	printf("*       |         4.按平均成绩排序.                              |           *\n");
	printf("*       |         5.插入一条记录.                                |           *\n");
	printf("*       |         6.输入记录号并删除该记录.                      |           *\n");
	printf("*       |         7.按各科成绩统计平均成绩.                      |           *\n");
	printf("*       |         8.退出.                                        |           *\n");
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
	   default: printf("输入错误,请重新输入.\n");
	}
	system("cls");
	goto kaishi;
	return 0;
}
