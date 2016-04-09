/*
  线段树

*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    //保存当前节点的左孩子的坐标，和右孩子的坐标
    int left,right;
    //max记录区间的最大值，sum记录区间的和
    int max,sum;
}tire[100];

//建立线段树
//id是当前树的坐标，l是区间的左坐标，r是区间的右坐标
void bulid(int id,int l,int r)
{
    tire[id].left=l; tire[id].right=r;
    //如果树节点的左坐标和右坐标相等，就说明不用往下建树了，树节点的最大值和和都是l或者r
    if(tire[id].left==tire[id].right)
        tire[id].max=tire[id].sum=l;
    //否则的话就需要建树
    else
    {
        int mid=(l+r)/2;
        //建立当前区间左边一半的线段树
        bulid(2*id,l,mid);
        //建立当前区间右边一半的线段树
        bulid(2*id+1,mid+1,r);
        //当前树节点的最大值，就是它的取左右孩子的最大值
        tire[id].max=tire[2*id].max>tire[2*id+1].max?tire[2*id].max:tire[2*id+1].max;
        //当前树节点的和值，就是它左树和有树之和
        tire[id].sum=tire[2*id].sum+tire[2*id+1].sum;
    }
}
//更新线段树
//id表示当前树的下标，pos表示要更新值得下表，val就是更新的值
void updata(int id,int pos ,int val)
{
    //如果当前树节点的左孩子等于右孩子，则修改max和sum
    if(tire[id].left==tire[id].right)
        tire[id].max=tire[id].sum=val;
    else
    {
        int mid=(tire[id].left+tire[id].right)/2;
        //如果要更新的位置在中间的左边，则只更新左边
        if(pos<=mid)
            updata(2*id,pos,val);
        //同理更新右边
        else
            updata(2*id+1,pos,val);
        tire[id].max=tire[2*id].max>tire[2*id+1].max?tire[2*id].max:tire[2*id+1].max;
        tire[id].sum=tire[2*id].sum+tire[2*id+1].sum;
    }
}
//查询线段树
//id表示当前树节点的下标，l是表示当前树区间的左端点的值，r表示当前树区间的右端点的值
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
