/*
  �߶���

*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    //���浱ǰ�ڵ�����ӵ����꣬���Һ��ӵ�����
    int left,right;
    //max��¼��������ֵ��sum��¼����ĺ�
    int max,sum;
}tire[100];

//�����߶���
//id�ǵ�ǰ�������꣬l������������꣬r�������������
void bulid(int id,int l,int r)
{
    tire[id].left=l; tire[id].right=r;
    //������ڵ�����������������ȣ���˵���������½����ˣ����ڵ�����ֵ�ͺͶ���l����r
    if(tire[id].left==tire[id].right)
        tire[id].max=tire[id].sum=l;
    //����Ļ�����Ҫ����
    else
    {
        int mid=(l+r)/2;
        //������ǰ�������һ����߶���
        bulid(2*id,l,mid);
        //������ǰ�����ұ�һ����߶���
        bulid(2*id+1,mid+1,r);
        //��ǰ���ڵ�����ֵ����������ȡ���Һ��ӵ����ֵ
        tire[id].max=tire[2*id].max>tire[2*id+1].max?tire[2*id].max:tire[2*id+1].max;
        //��ǰ���ڵ�ĺ�ֵ������������������֮��
        tire[id].sum=tire[2*id].sum+tire[2*id+1].sum;
    }
}
//�����߶���
//id��ʾ��ǰ�����±꣬pos��ʾҪ����ֵ���±�val���Ǹ��µ�ֵ
void updata(int id,int pos ,int val)
{
    //�����ǰ���ڵ�����ӵ����Һ��ӣ����޸�max��sum
    if(tire[id].left==tire[id].right)
        tire[id].max=tire[id].sum=val;
    else
    {
        int mid=(tire[id].left+tire[id].right)/2;
        //���Ҫ���µ�λ�����м����ߣ���ֻ�������
        if(pos<=mid)
            updata(2*id,pos,val);
        //ͬ������ұ�
        else
            updata(2*id+1,pos,val);
        tire[id].max=tire[2*id].max>tire[2*id+1].max?tire[2*id].max:tire[2*id+1].max;
        tire[id].sum=tire[2*id].sum+tire[2*id+1].sum;
    }
}
//��ѯ�߶���
//id��ʾ��ǰ���ڵ���±꣬l�Ǳ�ʾ��ǰ���������˵��ֵ��r��ʾ��ǰ��������Ҷ˵��ֵ
int query(int id,int l,int r)
{
    if(tire[id].left==l && tire[id].right==r)
        return tire[id].sum;
    int mid=(tire[id].left+tire[id].right)/2;
    if(r<=mid)
        query(2*id,l,r);
    else if(l>mid)
        query(2*id+1,l,r);
    else
        return query(2*id,l,mid)+query(2*id+1,mid+1,r);
}
int main()
{
    bulid(1,1,5);
    updata(1,4,100);
    int e=query(1,1,5);
    printf("%d\n",e);
    return 0;
}
