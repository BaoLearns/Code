#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
//�ֵ����ṹ��
typedef struct tiretree
{
    int cnt;
    struct tiretree *ch[26];
}Dictree,*PDictree;
int max=0;
//�ֵ����ĸ��ڵ�
PDictree root;
//��ʼ���ֵ����ĸ��ڵ��26��ָ��ȫδ��
void Init_tree()
{
    int i;
    root=(PDictree)malloc(sizeof(Dictree));
    for(i=0;i<26;++i)
        root->ch[i]=NULL;
    root->cnt=0;
    return ;
}
//���뵥��
void Insert_tree(char *word)
{
    PDictree p=root;
    int len=strlen(word);
    int i;
    for(i=0;i<len;++i)
    {
        //�����������ĸ��������ô�͹���һ���µĽڵ�
        if(p->ch[word[i]-'a']==NULL)
        {
            PDictree New_word=(PDictree)malloc(sizeof(Dictree));
            int j;
            for(j=0;j<26;++j)
                New_word->ch[j]=NULL;
            New_word->cnt=0;
            p->ch[word[i]-'a']=New_word;
            p=p->ch[word[i]-'a'];
        }
        //��������pָ��ָ����һ���ڵ�
        else
            p=p->ch[word[i]-'a'];
        //��һ�����ʵ����һ����ĸ���Ϊ1
        if(i==len-1)
            p->cnt=1;
    }
    return ;
}
//������������һ����1�ĸ���
void Find_tree(PDictree r,int num)
{
    PDictree p=r;
    int i;
    for(i=0;i<26;++i)
    {
        if(p->ch[i]!=NULL)
        {
            //�����1����ôͳ��һ�ĸ���
            if(p->cnt==1)
                ++num;
            Find_tree(p->ch[i],num);
        }
    }
    max=max>num?max:num;
}
int main()
{

    Init_tree();
    int n;
    char word[51];
    scanf("%d\n",&n);
    while(n--)
    {
        scanf("%s",word);
        Insert_tree(word);
    }
    Find_tree(root,0);
    printf("%d\n",max+1);
    return 0;
}
