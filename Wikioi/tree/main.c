//静态数的建立
//开链的写法
#include <stdio.h>
#include <malloc.h>
typedef struct node//重命名结构体
{
    int date;//数据域
    struct node *left;//左节点
    struct node *right;//右节点
    struct node *parent;
}tree,* ptree;//重命名未tree,ptree，ptree相当于tree *
ptree Init_tree()
{
    ptree pA=(ptree)malloc(sizeof(ptree));//构造节点A
    ptree pB=(ptree)malloc(sizeof(ptree));
    ptree pC=(ptree)malloc(sizeof(ptree));
    ptree pD=(ptree)malloc(sizeof(ptree));
    ptree pE=(ptree)malloc(sizeof(ptree));
    ptree pF=(ptree)malloc(sizeof(ptree));
    pA->date='A';//赋值节点A
    pB->date='B';
    pC->date='C';
    pD->date='D';
    pE->date='E';
    pF->date='F';
    pA->left=pB;//将A的左节点赋值未B节点的地址
    pA->right=pD;
    pA->parent=NULL;
    pB->left=pC;
    pB->right=NULL;
    pB->parent=pA;
    pC->right=pC->left=NULL;
    pC->parent=pB;
    pD->left=pE;
    pD->right=pF;
    pD->parent=pA;
    pE->left=pE->right=NULL;
    pE->parent=pD;
    pF->left=pF->right=NULL;
    pF->parent=pD;
    return pA;
}
void preTraverse_tree(ptree p)//先序遍历：先遍历根节点，再先序遍历左节点，再先序遍历右节点
{
    if(p!=NULL)//当节点存在时才遍历
    {
        printf("%c ",p->date);
        if(p->left!=NULL)preTraverse_tree(p->left);//先序遍历左节点
        if(p->right!=NULL)preTraverse_tree(p->right);//先序遍历右节点
    }
}
void inTraverse_tree(ptree p)//中序遍历：先中序遍历左节点，在访问根节点，再中序遍历右节点
{
    if(p!=NULL)
    {

        if(p->left!=NULL)inTraverse_tree(p->left);//当左节点不为空时，就中序遍历左节点
        printf("%c ",p->date);//访问数据
        if(p->right!=NULL)inTraverse_tree(p->right);//当右节点不为空时。就中序遍历右节点
    }
}
void lastTraverse_tree(ptree p)//后序遍历：先后序遍历左节点，再后序遍历右节点，再访问根节点
{
    if(p!=NULL)//当节点存在时就访问
    {

        if(p->left!=NULL)lastTraverse_tree(p->left);//当左节点不为空时，就后序遍历左节点
        if(p->right!=NULL)lastTraverse_tree(p->right);//当右节点不为空时，就后序遍历右节点
        printf("%c ",p->date);//访问数据区
    }
}
void LeftChild_tree(ptree p)//访问左孩子
{
    if(p->left!=NULL)//当存在左孩子是就访问
    {
        printf("%c ",p->left->date);
        LeftChild_tree(p->left);
    }
    /*else
        printf("遍历左孩子失败！   原因：左孩子不存在\n");*/
    return ;
}
void RightChild_tree(ptree p)//访问右孩子
{
    if(p->right!=NULL)//当存在右孩子是就访问
        printf("%c\n",p->right->date);
    else
    printf("遍历右孩子失败！   原因：右孩子不存在\n");
    return ;
}
void Parent_tree(ptree p)//遍历父节点
{
    if(p->parent!=NULL)
        printf("%c\n",p->parent->date);
    else
        printf("遍历父节点失败！   原因：父节点不存在\n");
    return ;
}
int main()
{
    ptree pT=(ptree)malloc(sizeof(tree));
    pT=Init_tree();//构造一个树
    printf("先序遍历：");
    preTraverse_tree(pT);//先序遍历
    putchar('\n');
    printf("中序遍历：");
    inTraverse_tree(pT);
    putchar('\n');
    printf("后序遍历：");
    lastTraverse_tree(pT);
    putchar('\n');
    LeftChild_tree(pT);
    putchar('\n');
    LeftChild_tree(pT->right);
    putchar('\n');
    RightChild_tree(pT->right);
    LeftChild_tree(pT->left->left);
    RightChild_tree(pT->left->left);
    RightChild_tree(pT->right->left);
    Parent_tree(pT->right->right);
    Parent_tree(pT->right->left);
    return 0;
}
