#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
//字典树结构体
typedef struct tiretree
{
    int cnt;
    struct tiretree *ch[26];
}Dictree,*PDictree;
int max=0;
//字典树的根节点
PDictree root;
//初始化字典树的根节点的26个指针全未空
void Init_tree()
{
    int i;
    root=(PDictree)malloc(sizeof(Dictree));
    for(i=0;i<26;++i)
        root->ch[i]=NULL;
    root->cnt=0;
    return ;
}
//插入单词
void Insert_tree(char *word)
{
    PDictree p=root;
    int len=strlen(word);
    int i;
    for(i=0;i<len;++i)
    {
        //如果想插入的字母不存在那么就构造一个新的节点
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
        //若存在则将p指针指向下一个节点
        else
            p=p->ch[word[i]-'a'];
        //将一个单词的最后一个字母标记为1
        if(i==len-1)
            p->cnt=1;
    }
    return ;
}
//查找整棵树中一条链1的个数
void Find_tree(PDictree r,int num)
{
    PDictree p=r;
    int i;
    for(i=0;i<26;++i)
    {
        if(p->ch[i]!=NULL)
        {
            //如果有1，那么统计一的个数
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
