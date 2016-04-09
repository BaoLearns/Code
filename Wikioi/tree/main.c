//��̬���Ľ���
//������д��
#include <stdio.h>
#include <malloc.h>
typedef struct node//�������ṹ��
{
    int date;//������
    struct node *left;//��ڵ�
    struct node *right;//�ҽڵ�
    struct node *parent;
}tree,* ptree;//������δtree,ptree��ptree�൱��tree *
ptree Init_tree()
{
    ptree pA=(ptree)malloc(sizeof(ptree));//����ڵ�A
    ptree pB=(ptree)malloc(sizeof(ptree));
    ptree pC=(ptree)malloc(sizeof(ptree));
    ptree pD=(ptree)malloc(sizeof(ptree));
    ptree pE=(ptree)malloc(sizeof(ptree));
    ptree pF=(ptree)malloc(sizeof(ptree));
    pA->date='A';//��ֵ�ڵ�A
    pB->date='B';
    pC->date='C';
    pD->date='D';
    pE->date='E';
    pF->date='F';
    pA->left=pB;//��A����ڵ㸳ֵδB�ڵ�ĵ�ַ
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
void preTraverse_tree(ptree p)//����������ȱ������ڵ㣬�����������ڵ㣬����������ҽڵ�
{
    if(p!=NULL)//���ڵ����ʱ�ű���
    {
        printf("%c ",p->date);
        if(p->left!=NULL)preTraverse_tree(p->left);//���������ڵ�
        if(p->right!=NULL)preTraverse_tree(p->right);//��������ҽڵ�
    }
}
void inTraverse_tree(ptree p)//��������������������ڵ㣬�ڷ��ʸ��ڵ㣬����������ҽڵ�
{
    if(p!=NULL)
    {

        if(p->left!=NULL)inTraverse_tree(p->left);//����ڵ㲻Ϊ��ʱ�������������ڵ�
        printf("%c ",p->date);//��������
        if(p->right!=NULL)inTraverse_tree(p->right);//���ҽڵ㲻Ϊ��ʱ������������ҽڵ�
    }
}
void lastTraverse_tree(ptree p)//����������Ⱥ��������ڵ㣬�ٺ�������ҽڵ㣬�ٷ��ʸ��ڵ�
{
    if(p!=NULL)//���ڵ����ʱ�ͷ���
    {

        if(p->left!=NULL)lastTraverse_tree(p->left);//����ڵ㲻Ϊ��ʱ���ͺ��������ڵ�
        if(p->right!=NULL)lastTraverse_tree(p->right);//���ҽڵ㲻Ϊ��ʱ���ͺ�������ҽڵ�
        printf("%c ",p->date);//����������
    }
}
void LeftChild_tree(ptree p)//��������
{
    if(p->left!=NULL)//�����������Ǿͷ���
    {
        printf("%c ",p->left->date);
        LeftChild_tree(p->left);
    }
    /*else
        printf("��������ʧ�ܣ�   ԭ�����Ӳ�����\n");*/
    return ;
}
void RightChild_tree(ptree p)//�����Һ���
{
    if(p->right!=NULL)//�������Һ����Ǿͷ���
        printf("%c\n",p->right->date);
    else
    printf("�����Һ���ʧ�ܣ�   ԭ���Һ��Ӳ�����\n");
    return ;
}
void Parent_tree(ptree p)//�������ڵ�
{
    if(p->parent!=NULL)
        printf("%c\n",p->parent->date);
    else
        printf("�������ڵ�ʧ�ܣ�   ԭ�򣺸��ڵ㲻����\n");
    return ;
}
int main()
{
    ptree pT=(ptree)malloc(sizeof(tree));
    pT=Init_tree();//����һ����
    printf("���������");
    preTraverse_tree(pT);//�������
    putchar('\n');
    printf("���������");
    inTraverse_tree(pT);
    putchar('\n');
    printf("���������");
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
