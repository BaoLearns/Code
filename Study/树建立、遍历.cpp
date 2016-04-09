#include <cstdio>
#include <cstdlib>
#include <malloc.h>
#include <iostream>
using namespace std;

typedef char elem;

typedef struct node
{
    elem data;
    struct node* LChild;
    struct node* RChild;
}Tnode, *PTnode;

void Ceart(PTnode &Root)
{
    elem ch;
    scanf("%c", &ch);
    if(ch != '#')
    {
        Root = (PTnode)malloc(sizeof(Tnode));
        if(!Root) exit(-1);
        Root->data = ch;
        Root->LChild = Root->RChild = NULL;
        Ceart(Root -> LChild);
        Ceart(Root -> RChild);
    }
}

void PreTreav(PTnode Root)
{
    if(Root)
    {
        printf("%c ", Root->data);
        PreTreav(Root -> LChild);
        PreTreav(Root -> RChild);
    }
}

void InTreav(PTnode Root)
{
    if(Root)
    {
        InTreav(Root -> LChild);
        printf("%c ", Root->data);
        InTreav(Root -> RChild);
    }
}

void EnTreav(PTnode Root)
{
    if(Root)
    {
        EnTreav(Root -> LChild);
        EnTreav(Root -> RChild);
        printf("%c ", Root->data);
    }
}
int main()
{
    PTnode Root;
    Ceart(Root);
    PreTreav(Root);
    putchar('\n');
    InTreav(Root);
    putchar('\n');
    EnTreav(Root);
    putchar('\n');
    return 0;
}

//ab#d##c#e##






/*
#include<iostream>  
using namespace std;  
  
typedef struct node  
{  
    struct node *leftChild;  
    struct node *rightChild;  
    char data;  
}BiTreeNode, *BiTree;  
  
void createBiTree(BiTree &T)  
{  
    char c;  
    cin >> c;  
    if('#' == c)  
        T = NULL;  
    else  
    {  
        T = new BiTreeNode;  
        T->data = c;  
        createBiTree(T->leftChild);  
        createBiTree(T->rightChild);  
    }  
}  

void PreTreav(BiTree Root)
{
    if(Root)
    {
        printf("%c ", Root->data);
        PreTreav(Root -> leftChild);
        PreTreav(Root -> rightChild);
    }
}
int main()  
{  
    BiTree T;  
    createBiTree(T);  
    PreTreav(T);
    return 0;  
}
*/
