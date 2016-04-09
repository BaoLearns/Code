#include <cstdio>
#define maxn 100010
int arr[maxn],t=0;
struct tree
{
    int right,left,vis;
    long long sum;
}tree[maxn*4];
void bulid(int id,int l, int r)
{
    tree[id].left=l,tree[id].right=r,tree[id].vis=0;
    if(l==r)
        tree[id].sum=arr[l];
    else
    {
        int mid=(l+r)/2;
        bulid(id*2,l,mid);
        bulid(id*2+1,mid+1,r);
        tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
    }
}
int  show(int id,int l, int r)
{
    if(tree[id].vis==1)
    {
        tree[id].sum+=(tree[id].right-tree[id].left+1)*t;
        tree[id*2].vis=tree[2*id+1].vis=1;
    }
    if(tree[id].left==l && tree[id].right==r)
        return tree[id].sum;
    else
    {
        int mid=(tree[id].left+tree[id].right)/2;
        if(l>mid)
            show(id*2+1,l,r);
        else if(r<=mid)
            show(id*2,l,r);
        else
        return show(id*2,l,mid)+show(id*2+1,mid+1,r);

    }
}
void add(int id,int l,int r,int val)
{
    if(tree[id].left>=l && tree[id].right<= r)
    {
        tree[id].sum+=(tree[id].right-tree[id].left+1)*val;
        tree[id*2].vis=tree[id*2+1].vis=1;
    }
    else
    {
        int mid=(tree[id].left+tree[id].right)/2;
        if(l>mid)
            add(id*2+1,l,r,val);
        else if(r<=mid)
            add(id*2,l,r,val);
        else
        {
            add(id*2,l,mid,val);
            add(id*2+1,mid+1,r,val);
        }
        tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
    }

}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; ++i)
        scanf("%d",arr+i);
    bulid(1,1,n);
    for(int i = 0; i < m; ++i)
    {
        int x,y,z;
        scanf("%d",&x);
        if(x==0)
        {
            scanf("%d%d",&y,&z);
            printf("%d\n",show(1,y,z));
        }
        else
        {
            scanf("%d%d%d",&y,&z,&t);
            add(1,y,z,t);
        }
    }
    return 0;
}
