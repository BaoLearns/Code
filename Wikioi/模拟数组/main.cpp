#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>

//���ţ�����
int camp( const void *a,const void *b)
{
    return *( int *) a- *( int *) b;
}

//����һ���ṹ��
typedef struct node
{
    //����ģ��������׵�ַ
    int * pBase;
    //����ĳ���
    int len;
    //����ĸ���
    int cnt;
}node ;

void print();//��ӡ�˵�
void Init_arr( node *); //�����Ը�����
bool IsEmpty_arr( node *);//�ж��Ƿ��
bool IsFull_arr( node *);//�ж��Ƿ�Ϊ��
void Appead_arr( node *);//�������ĩβ����һ��ֵ
void Insert_arr( node *);//����һ��һ��ֵval
void Delete_arr( node *);//ɾ��һ��ֵ
void Sort_arr( node *);//����
void Show_arr( node *);//���ֵ
void Inversion_arr( node *);//����
void Find_arr( node *);//����

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
            default:printf("�������������");break;
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
    if(Find_arr(&arr,5)) printf("���������\n");
    else printf("�����������\n");
        */
    return 0;
}

//����һ��������
void Init_arr( node *p)
{
    int length;
    printf("���봴��ģ������Ĵ�С��");
    scanf("%d", &length);
    p->pBase = ( int *) malloc( sizeof( int) * length);
    if( p -> pBase)
    {
        printf("���鴴���ɹ�!\n");
        p -> cnt = 0;
        p -> len = length;
    }
    else
    {
        printf("���鴴��ʧ��\n");
        exit(-1);
    }
    getchar();
    getchar();
    system("CLS");
    print();
    return ;
}

//�ж������Ƿ�����
bool IsFull( node *p)
{
    if( p->cnt > p->len)
        return true;
    return false;
}

//��������
void Appead_arr( node *p)
{
    if( !p -> pBase)
    {
        printf("���������鲻�ܼ���Ԫ�أ�\n");
        printf("��Y��������N��������");
        char ch ;
        scanf("%c", &ch);
        if(ch == 'Y')
            return ;
        exit(-1);
    }
    int n;
    printf("������������ݵĸ�����");
    scanf("%d", &n);
    int i;
    for( i = 0 ;i < n; i++)
     {
         printf("�����%d��Ԫ��:", i + 1);
         scanf("%d", &p -> pBase[ p -> cnt++]);
     }
    putchar('\n');
    getchar();
    getchar();
    system("CLS");
    print();
    return ;
}

//����Ԫ��
void Show_arr(node *p)
{
    if(! p -> pBase)
    {
        printf("���������鲻�ܱ�����\n");
        printf("��Y��������N��������");
        char ch;
        scanf("%c",&ch);
        if(ch == 'Y')
            return ;
        exit(-1);
    }
    if(IsEmpty_arr(p))
    {
        printf("����Ϊ�ղ��ܱ�����\n");
        printf("��Y��������N��������");
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

//�ж��Ƿ�Ϊ������
bool IsEmpty_arr(node *p)
{
    if( p->cnt == 0)
        return true;
    return false;
}

//����Ԫ��
void Insert_arr( node *p)
{
    int pos,val;
    printf("����������λ�ú����ݣ�");
    scanf("%d%d", &pos, &val);
    if(!p->pBase)
    {
        printf("���������鲻�ܲ��룡\n");
        printf("��Y��������N��������");
        char ch;
        scanf("%c",&ch);
        if(ch == 'Y')
            return ;
        exit(-1);
    }
    if(IsEmpty_arr(p))
    {
        printf("����Ϊ�ղ��ܲ��룡\n");
        printf("��Y��������N��������");
        char ch;
        scanf("%c",&ch);
        if(ch == 'Y')
            return ;
        exit(-1);
    }
    if( pos < 1 || pos > p->cnt + 1)
        printf("�����λ��Խ��\n");
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

//ɾ��Ԫ��
void Delete_arr(node *p)
{
    if( !p->pBase)
    {
        printf("���������鲻��ɾ����\n");
        printf("��Y��������N��������");
        char ch;
        scanf("%c",&ch);
        if(ch == 'Y')
            return ;
        exit(-1);
    }
    if(IsEmpty_arr(p))
    {
        printf("����Ϊ�ղ��ܲ���ɾ����\n");
        printf("��Y��������N��������");
        char ch;
        scanf("%c",&ch);
        if(ch == 'Y')
            return ;
        exit(-1);
    }
    int val;
    printf("������Ҫɾ����Ԫ�أ�");
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
        printf("�������Ÿ�Ԫ�أ�ɾ��ʧ�ܣ�\n");
    getchar();
    getchar();
    system("CLS");
    print();
    return;
}

//��������
void Sort_arr(node *p)
{
    if(!p -> pBase)
    {
        printf("���������鲻������\n");
        printf("��Y��������N��������");
        char ch;
        scanf("%c",&ch);
        if(ch == 'Y')
            return ;
        exit(-1);
    }
    if(IsEmpty_arr(p))
    {
        printf("����Ϊ�ղ�������\n");
        printf("��Y��������N��������");
        char ch;
        scanf("%c",&ch);
        if(ch == 'Y')
            return ;
        exit(-1);
    }
    //���ÿ⺯����������
    qsort(p->pBase,p->cnt,sizeof(int),camp);
    getchar();
    getchar();
    system("CLS");
    print();
    return ;
}

//��������
void Inversion_arr(node *p)
{

    if(!p->pBase)
    {
        printf("���������鲻�ܵ��ã�\n");
        printf("��Y��������N��������");
        char ch;
        scanf("%c",&ch);
        if(ch == 'Y')
            return ;
        exit(-1);
    }
    if(IsEmpty_arr(p))
    {
        printf("����Ϊ�ղ��ܵ��ã�\n");
        printf("��Y��������N��������");
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

//����Ԫ��
void Find_arr(node *p)
{
    if( p->pBase==NULL)
    {
        printf("���������鲻�ܲ��ң�\n");
        printf("��Y��������N��������");
        char ch;
        scanf("%c",&ch);
        if(ch == 'Y')
            return ;
        else
            exit(-1);
    }
    if(IsEmpty_arr(p))
    {
        printf("����Ϊ�ղ��ܲ��ң�\n");
        printf("��Y��������N��������");
        char ch;
        scanf("%c",&ch);
        if(ch == 'Y')
            return ;
        else
            exit(-1);
    }
    printf("��������ҵ����ݣ�");
    int val;
    scanf("%d", &val);
    int i;
    for(i = 0; i < p->cnt; ++i)
    {
        if(val == p->pBase[ i])
            break;
    }
    if(i >= p->cnt)
        printf("�����������\n");
    else
        printf("���������\n");
    getchar();
    getchar();
    system("CLS");
    print();
    return ;
}

//��ӡ�˵�
void print()
{
    printf("*************************************ѡ��˵�**********************************\n");
    printf("*                                    1.����ģ������                           *\n");
    printf("*                                    2.�������                               *\n");
    printf("*                                    3.����Ԫ��                               *\n");
    printf("*                                    4.ɾ��Ԫ��                               *\n");
    printf("*                                    5.����                                   *\n");
    printf("*                                    6.����                                   *\n");
    printf("*                                    7.����                                   *\n");
    printf("*                                    8.��������                               *\n");
    printf("*                                    9.�˳�                                   *\n");
    printf("*******************************************************************************\n");
    printf("��ѡ��˵���");
}
