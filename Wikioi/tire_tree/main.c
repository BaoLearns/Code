#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
typedef struct tiretree
{
    int cnt;
    struct tiretree *ch[26];
}Dictree,*PDictree;

PDictree root;

void Init_tree()
{
    int i;
    root=(PDictree)malloc(sizeof(Dictree));
    for(i=0;i<26;++i)
        root->ch[i]=NULL;
    root->cnt=0;
    return ;
}

void Insert_tree(char *word)
{
    PDictree p=root;
    int len=strlen(word);
    int i;
    for(i=0;i<len;++i)
    {
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
        else
            p=p->ch[word[i]-'a'];

        if(i==len-1)
            p->cnt++;
    }
    return ;
}

int Find_tree(char *word)
{
    PDictree p=root;
    int len=strlen(word);
    int i;
    for(i=0;i<len;++i)
    {
        if(p->ch[word[i]-'a']==NULL)
            return 0;
        p=p->ch[word[i]-'a'];
    }
    return p->cnt;
}
int main()
{

    Init_tree();
    int n;
    char word[50];
    scanf("%d\n",&n);
    while(n--)
    {
        scanf("%s",word);
        Insert_tree(word);
    }
    scanf("%d\n",&n);
    while(n--)
    {
        scanf("%s",word);
        printf("%d\n",Find_tree(word));
    }
    return 0;
}
