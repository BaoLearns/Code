//排序二叉树
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//定义结构体
typedef struct node
{
    //data存储数据
    int data;
    //左孩子
    struct node *left;
    //右孩子
    struct node *right;
}Node,* PNode;//重民命Node，PNode

int num[10]={4,2,1,0,3,8,6,7,10,9};

//插入节点的值
void Insert(PNode root,int data)
{
    //构造p节点
    PNode p=(PNode )malloc(sizeof(Node));
    p->data=data;
    //左孩子，右孩子赋值未空
    p->left=p->right=NULL;
    //如果跟节点的左孩子未空并且插入的数据比根数据小，则让root节点赋值未p节点
    if((root)->left==NULL && (root)->data > data)
    {
        (root)->left=p;
        return ;
    }
    //如果跟节点的右孩子未空并且插入的数据比根数据大，则让root节点赋值未p节点
    if((root)->right==NULL && (root)->data <= data )
    {
        (root)->right=p;
        return ;
    }
    //如果左右孩子都不为空，且插入的数据比root节点的值大，则递归插入root节点的右孩子
    if((root)->data <= data)
        Insert((root)->right,data);
    //如果左右孩子都不为空，且插入的数据比root节点的值小，则递归插入root节点的左孩子
    else
        Insert((root)->left,data);
}

//创建节点
void Creat(PNode root,int n)
{
    int i;
    for(i=1;i<n;++i)
        Insert(root,num[i]);
}

//中序遍历
void Inorder(PNode root)
{
    if(root->left!=NULL)
        Inorder(root->left);
    printf("%d ",root->data);
    if(root->right!=NULL)
        Inorder(root->right);
}

//删除节点
void Delete(PNode root,int val)
{
    PNode p=root;
    //PNode q=root;
    PNode father=p;
    //查找要删除的值在那个位置
    while(p->data!=val)
    {
        father=p;
        p=(p->data)>val?p->left:p->right;
        /*if(p->left==NULL && p->right == NULL)
            return ;*/
    }
    /*if(p == father)
    {
        PNode son=p->right;
        while(son->left!=NULL)
        {

            son=son->left;
        }
        son->left=p->left;
        //father->left=p->right;
        p->left=NULL;

        p=p->right;
        //p->left=NULL;
        free(father);
        return ;
    }*/
    //如果要删除的值没有左孩子右孩子，则可以直接删除此节点
    if(p->left==NULL && p->right==NULL)
    {
        if(father->left==p)
            father->left=NULL;
        else
            father->right=NULL;
        free(p);
        return ;
    }
    //如果要删除的节点有左孩子，没有右孩子。并判断要删除的节点是其父节点的左孩子还是右孩子，
    if(p->left!=NULL && p->right==NULL)
    {
        //如果要删除的节点是其父节点的左孩子，则直接将父节点的左孩子等于p节点的左孩子
        if(father->left==p)
            father->left=p->left;
        //如果要删除的节点是其父节点的右孩子，则直接将父节点的左孩子等于p节点的右孩子
        else
            father->right=p->left;
        free(p);
        return ;
    }
    //如果要删除的节点有右孩子，没有左孩子。并判断要删除的节点是其父节点的左孩子还是右孩子，
    if(p->left==NULL && p->right!=NULL)
    {
        //如果要删除的节点是其父节点的左孩子，则直接将父节点的左孩子等于p节点的右孩子
        if(father->left==p)
            father->left=p->right;
        //如果要删除的节点是其父节点的右孩子，则直接将父节点的左孩子等于p节点的右孩子
        else
            father->right=p->right;
        free(p);
        return ;
    }
    //father=p->right;
    //最后一种情况就是要删除的p节点有左右孩子
    //找后继节点，后继节点就是此节点的右孩子的最左边的孩子
    PNode son=p->right;
    while(son->left!=NULL)
    {

        son=son->left;
    }
    son->left=p->left;
    father->left=p->right;
    free(p);
    return ;
}
int main()
{
    //单独处理跟节点
    Node root;
    root.left=root.right=NULL;
    root.data=num[0];
    Creat(&root,10);
    int e;
    Inorder(&root);
    putchar('\n');
    while(scanf("%d",&e))
    {
        if(root.data==e)
        {
            PNode p=root.right;
            while(p->left!=NULL)
            {

                p=p->left;
            }
            p->left=root.left;


            root.data=root.right->data;
            root.left=root.right->left;
            root.right=root.right->right;
            continue;

        }
        Delete(&root,e);
        Inorder(&root);
        putchar('\n');
    }

    putchar('\n');
    return 0;
}

