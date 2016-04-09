#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>

//快排（降序）
int camp( const void *a,const void *b)
{
    return *( int *) a- *( int *) b;
}

//定义一个结构体
typedef struct node
{
    //保存模拟数组的首地址
    int * pBase;
    //数组的长度
    int len;
    //数组的个数
    int cnt;
}node ;

void print();//打印菜单
void Init_arr( node *); //创建以个数组
bool IsEmpty_arr( node *);//判断是否空
bool IsFull_arr( node *);//判断是否为满
void Appead_arr( node *);//在数组的末尾增加一个值
void Insert_arr( node *);//插入一个一个值val
void Delete_arr( node *);//删除一个值
void Sort_arr( node *);//排序
void Show_arr( node *);//输出值
void Inversion_arr( node *);//倒序
void Find_arr( node *);//查找

int main()
{
    print();
    node arr;
    int m;

    while(scanf("%d", &m))
    {
        switch( m)
        {
            case 1:Init_arr(&arr);break;
            case 2:Show_arr(&arr);break;
            case 3:Insert_arr(&arr);break;
            case 4:Delete_arr(&arr);break;
            case 5:Sort_arr(&arr);break;
            case 6:Inversion_arr(&arr);break;
            case 7:Find_arr(&arr);break;
            case 8:Appead_arr(&arr);break;
            case 9:exit(-1);break;
            default:printf("输入的数据有误");break;
        }
    }
    /*int n=6;
    Init_arr(&arr,n);
    Appead_arr(&arr,1);
    Appead_arr(&arr,8);
    Appead_arr(&arr,3);
    Appead_arr(&arr,4);
    Appead_arr(&arr,5);
    Show_arr(&arr);
    Insert_arr(&arr,2,9);
    Show_arr(&arr);
    Delete_arr(&arr,9);
    Show_arr(&arr);
    Sort_arr(&arr);
    Show_arr(&arr);
    Inversion_arr(&arr);
    Show_arr(&arr);
    if(Find_arr(&arr,5)) printf("存在这个数\n");
    else printf("不存在这个数\n");
        */
    return 0;
}

//构造一个空数组
void Init_arr( node *p)
{
    int length;
    printf("输入创建模拟数组的大小：");
    scanf("%d", &length);
    p->pBase = ( int *) malloc( sizeof( int) * length);
    if( p -> pBase)
    {
        printf("数组创建成功!\n");
        p -> cnt = 0;
        p -> len = length;
    }
    else
    {
        printf("数组创建失败\n");
        exit(-1);
    }
    getchar();
    getchar();
    system("CLS");
    print();
    return ;
}

//判断数组是否已满
bool IsFull( node *p)
{
    if( p->cnt > p->len)
        return true;
    return false;
}

//输入数据
void Appead_arr( node *p)
{
    if( !p -> pBase)
    {
        printf("不存在数组不能加入元素！\n");
        printf("按Y继续，按N结束程序");
        char ch ;
        scanf("%c", &ch);
        if(ch == 'Y')
            return ;
        exit(-1);
    }
    int n;
    printf("请输入插入数据的个数：");
    scanf("%d", &n);
    int i;
    for( i = 0 ;i < n; i++)
     {
         printf("输入第%d个元素:", i + 1);
         scanf("%d", &p -> pBase[ p -> cnt++]);
     }
    putchar('\n');
    getchar();
    getchar();
    system("CLS");
    print();
    return ;
}

//遍历元素
void Show_arr(node *p)
{
    if(! p -> pBase)
    {
        printf("不存在数组不能遍历！\n");
        printf("按Y继续，按N结束程序");
        char ch;
        scanf("%c",&ch);
        if(ch == 'Y')
            return ;
        exit(-1);
    }
    if(IsEmpty_arr(p))
    {
        printf("数组为空不能遍历！\n");
        printf("按Y继续，按N结束程序");
        char ch;
        scanf("%c",&ch);
        if(ch == 'Y')
            return ;
        exit(-1);
    }
    int i;
    for( i = 0; i < p->cnt; i++)
        printf("%d ",p -> pBase[ i]);
    printf("\n");
    getchar();
    getchar();
    system("CLS");
    print();
    return ;
}

//判断是否为空数组
bool IsEmpty_arr(node *p)
{
    if( p->cnt == 0)
        return true;
    return false;
}

//插入元素
void Insert_arr( node *p)
{
    int pos,val;
    printf("请输入插入的位置和数据；");
    scanf("%d%d", &pos, &val);
    if(!p->pBase)
    {
        printf("不存在数组不能插入！\n");
        printf("按Y继续，按N结束程序");
        char ch;
        scanf("%c",&ch);
        if(ch == 'Y')
            return ;
        exit(-1);
    }
    if(IsEmpty_arr(p))
    {
        printf("数组为空不能插入！\n");
        printf("按Y继续，按N结束程序");
        char ch;
        scanf("%c",&ch);
        if(ch == 'Y')
            return ;
        exit(-1);
    }
    if( pos < 1 || pos > p->cnt + 1)
        printf("插入的位置越界\n");
    else
    {
        int i;
        for( i = p->cnt ; i >= pos-1; --i)
            p -> pBase[ i + 1] = p -> pBase[ i];
        p -> pBase[ pos] = val;
        p -> cnt++;
    }
    getchar();
    getchar();
    system("CLS");
    print();
    return ;
}

//删除元素
void Delete_arr(node *p)
{
    if( !p->pBase)
    {
        printf("不存在数组不能删除！\n");
        printf("按Y继续，按N结束程序");
        char ch;
        scanf("%c",&ch);
        if(ch == 'Y')
            return ;
        exit(-1);
    }
    if(IsEmpty_arr(p))
    {
        printf("数组为空不能查找删除！\n");
        printf("按Y继续，按N结束程序");
        char ch;
        scanf("%c",&ch);
        if(ch == 'Y')
            return ;
        exit(-1);
    }
    int val;
    printf("请输入要删除的元素；");
    scanf("%d",&val);
    int i=0,j;
    if(p->cnt > 0)
    {
        for( i = 0; i < p->cnt; ++i)
        {
            if( val == p->pBase[ i])
            {
                for( j = i; j < p->cnt-1; ++j)
                    p -> pBase[ j] = p -> pBase[ j + 1];
                p -> cnt--;
                break;
            }
        }
    }
    if(i >= p->cnt)
        printf("不存在着个元素，删除失败！\n");
    getchar();
    getchar();
    system("CLS");
    print();
    return;
}

//升序排列
void Sort_arr(node *p)
{
    if(!p -> pBase)
    {
        printf("不存在数组不能排序！\n");
        printf("按Y继续，按N结束程序");
        char ch;
        scanf("%c",&ch);
        if(ch == 'Y')
            return ;
        exit(-1);
    }
    if(IsEmpty_arr(p))
    {
        printf("数组为空不能排序！\n");
        printf("按Y继续，按N结束程序");
        char ch;
        scanf("%c",&ch);
        if(ch == 'Y')
            return ;
        exit(-1);
    }
    //调用库函数升序排序
    qsort(p->pBase,p->cnt,sizeof(int),camp);
    getchar();
    getchar();
    system("CLS");
    print();
    return ;
}

//倒置数组
void Inversion_arr(node *p)
{

    if(!p->pBase)
    {
        printf("不存在数组不能倒置！\n");
        printf("按Y继续，按N结束程序");
        char ch;
        scanf("%c",&ch);
        if(ch == 'Y')
            return ;
        exit(-1);
    }
    if(IsEmpty_arr(p))
    {
        printf("数组为空不能倒置！\n");
        printf("按Y继续，按N结束程序");
        char ch;
        scanf("%c",&ch);
        if(ch == 'Y')
            return ;
        exit(-1);
    }
    int i = 0, j = p->cnt-1, t;
    while(i < j)
    {
        t = p->pBase[ i];
        p -> pBase[ i] = p -> pBase[ j];
        p -> pBase[ j] = t;
        ++i , --j;
    }
    getchar();
    getchar();
    system("CLS");
    print();
    return ;
}

//查找元素
void Find_arr(node *p)
{
    if( p->pBase==NULL)
    {
        printf("不存在数组不能查找！\n");
        printf("按Y继续，按N结束程序");
        char ch;
        scanf("%c",&ch);
        if(ch == 'Y')
            return ;
        else
            exit(-1);
    }
    if(IsEmpty_arr(p))
    {
        printf("数组为空不能查找！\n");
        printf("按Y继续，按N结束程序");
        char ch;
        scanf("%c",&ch);
        if(ch == 'Y')
            return ;
        else
            exit(-1);
    }
    printf("请输入查找的数据：");
    int val;
    scanf("%d", &val);
    int i;
    for(i = 0; i < p->cnt; ++i)
    {
        if(val == p->pBase[ i])
            break;
    }
    if(i >= p->cnt)
        printf("不存在这个数\n");
    else
        printf("存在这个数\n");
    getchar();
    getchar();
    system("CLS");
    print();
    return ;
}

//打印菜单
void print()
{
    printf("*************************************选择菜单**********************************\n");
    printf("*                                    1.创建模拟数组                           *\n");
    printf("*                                    2.输出数组                               *\n");
    printf("*                                    3.插入元素                               *\n");
    printf("*                                    4.删除元素                               *\n");
    printf("*                                    5.排序                                   *\n");
    printf("*                                    6.倒序                                   *\n");
    printf("*                                    7.查找                                   *\n");
    printf("*                                    8.输入数据                               *\n");
    printf("*                                    9.退出                                   *\n");
    printf("*******************************************************************************\n");
    printf("请选择菜单：");
}
