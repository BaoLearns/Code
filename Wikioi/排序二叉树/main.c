//���������
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//����ṹ��
typedef struct node
{
    //data�洢����
    int data;
    //����
    struct node *left;
    //�Һ���
    struct node *right;
}Node,* PNode;//������Node��PNode

int num[10]={4,2,1,0,3,8,6,7,10,9};

//����ڵ��ֵ
void Insert(PNode root,int data)
{
    //����p�ڵ�
    PNode p=(PNode )malloc(sizeof(Node));
    p->data=data;
    //���ӣ��Һ��Ӹ�ֵδ��
    p->left=p->right=NULL;
    //������ڵ������δ�ղ��Ҳ�������ݱȸ�����С������root�ڵ㸳ֵδp�ڵ�
    if((root)->left==NULL && (root)->data > data)
    {
        (root)->left=p;
        return ;
    }
    //������ڵ���Һ���δ�ղ��Ҳ�������ݱȸ����ݴ�����root�ڵ㸳ֵδp�ڵ�
    if((root)->right==NULL && (root)->data <= data )
    {
        (root)->right=p;
        return ;
    }
    //������Һ��Ӷ���Ϊ�գ��Ҳ�������ݱ�root�ڵ��ֵ����ݹ����root�ڵ���Һ���
    if((root)->data <= data)
        Insert((root)->right,data);
    //������Һ��Ӷ���Ϊ�գ��Ҳ�������ݱ�root�ڵ��ֵС����ݹ����root�ڵ������
    else
        Insert((root)->left,data);
}

//�����ڵ�
void Creat(PNode root,int n)
{
    int i;
    for(i=1;i<n;++i)
        Insert(root,num[i]);
}

//�������
void Inorder(PNode root)
{
    if(root->left!=NULL)
        Inorder(root->left);
    printf("%d ",root->data);
    if(root->right!=NULL)
        Inorder(root->right);
}

//ɾ���ڵ�
void Delete(PNode root,int val)
{
    PNode p=root;
    //PNode q=root;
    PNode father=p;
    //����Ҫɾ����ֵ���Ǹ�λ��
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
    //���Ҫɾ����ֵû�������Һ��ӣ������ֱ��ɾ���˽ڵ�
    if(p->left==NULL && p->right==NULL)
    {
        if(father->left==p)
            father->left=NULL;
        else
            father->right=NULL;
        free(p);
        return ;
    }
    //���Ҫɾ���Ľڵ������ӣ�û���Һ��ӡ����ж�Ҫɾ���Ľڵ����丸�ڵ�����ӻ����Һ��ӣ�
    if(p->left!=NULL && p->right==NULL)
    {
        //���Ҫɾ���Ľڵ����丸�ڵ�����ӣ���ֱ�ӽ����ڵ�����ӵ���p�ڵ������
        if(father->left==p)
            father->left=p->left;
        //���Ҫɾ���Ľڵ����丸�ڵ���Һ��ӣ���ֱ�ӽ����ڵ�����ӵ���p�ڵ���Һ���
        else
            father->right=p->left;
        free(p);
        return ;
    }
    //���Ҫɾ���Ľڵ����Һ��ӣ�û�����ӡ����ж�Ҫɾ���Ľڵ����丸�ڵ�����ӻ����Һ��ӣ�
    if(p->left==NULL && p->right!=NULL)
    {
        //���Ҫɾ���Ľڵ����丸�ڵ�����ӣ���ֱ�ӽ����ڵ�����ӵ���p�ڵ���Һ���
        if(father->left==p)
            father->left=p->right;
        //���Ҫɾ���Ľڵ����丸�ڵ���Һ��ӣ���ֱ�ӽ����ڵ�����ӵ���p�ڵ���Һ���
        else
            father->right=p->right;
        free(p);
        return ;
    }
    //father=p->right;
    //���һ���������Ҫɾ����p�ڵ������Һ���
    //�Һ�̽ڵ㣬��̽ڵ���Ǵ˽ڵ���Һ��ӵ�����ߵĺ���
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
    //����������ڵ�
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

