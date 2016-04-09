#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct tree
{
    int date;
    struct tree *leftchild;
    struct tree *rightchild;
}tree,* ptree;
ptree Init_tree()
{
    ptree pt=(ptree)malloc(sizeof(tree));
    pt->leftchild=(ptree)malloc(sizeof(tree));
    pt->rightchild=(ptree)malloc(sizeof(tree));
    pt->leftchild=pt->rightchild=NULL;
    //t->leftchild=leftchild;
    //t->rightchild=rightchild;
    return pt;
}
void Creat_tree(ptree t,int val)
{
    ptree newtree=(ptree)malloc(sizeof(tree));
    newtree->date=val;
    t=newtree;
    newtree->leftchild=(ptree)malloc(sizeof(tree));
    newtree->rightchild=(ptree)malloc(sizeof(tree));
    newtree->leftchild=newtree->rightchild=NULL;
}
void PreTraverse(ptree t)
{
    if(t!=NULL)
    {
        printf("%d ",t->date);
        if(t->leftchild!=NULL) PreTraverse(t->leftchild);
        if(t->rightchild!=NULL) PreTraverse(t->rightchild);
    }
    return ;
}
int main()
{
    ptree t;
    t=Init_tree();
    Creat_tree(t->leftchild,1);
    Creat_tree(t->rightchild,2);
    Creat_tree(t->rightchild->leftchild,3);
    PreTraverse(t);
    return 0;
}
