//����һ��������ģ��ѭ������
//���� Roye
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int rear=0,front=0;//��ʼ�������±��ֵ
int num=0;//��¼Ԫ�صĸ���
void En_queue(int *p)//���һ��Ԫ��
{
    printf("������ӵ�ֵ��");
    scanf("%d",p+rear);
    rear=(rear+1)%6;//��r��ֵ����5ʱr��ֵ��ת��0����ʵ����ѭ��
    num++;//��ӣ�Ԫ�ص��ܸ�����һ
}
void De_queue(int *p)//����
{
    printf("���Ե�Ԫ���ǣ�%d\n",p[front]);
    front=(front+1)%6;
    num--;//������Ԫ�أ�Ԫ�صĸ����ͼ�һ
}
int main()
{
    int s[6];
    int chi;
    while(scanf("%d",&chi))
    {
        if(chi==1)//ѡ����ӻ�����ӣ�1��ʾ��ӣ�������ʾ����
        {
            if (num!=6)//�ж��Ƿ�Ϊ��
                En_queue(s);
            else
                printf("�����Ѿ����ˣ����ܲ��룡\n");
        }
        else
        {
            if(num!=0)
                De_queue(s);
            else
                printf("����Ϊ�ղ���ɾ��\n");

        }
    }
    return 0;
}
