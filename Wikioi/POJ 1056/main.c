#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define max 1000100
typedef struct tiretree
{
    int cnt;
    struct tiretree *ch[2];
}Dictree,*PDictree;

PDictree root;
int flag;
void Init_tree()
{
    int i;
    root=(PDictree)malloc(sizeof(Dictree));
    for(i=0;i<2;++i)
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
        if(p->ch[word[i]-'0']==NULL)
        {
            PDictree New_word=(PDictree)malloc(sizeof(Dictree));
            int j;
            for(j=0;j<2;++j)
                New_word->ch[j]=NULL;
            New_word->cnt=0;
            p->ch[word[i]-'0']=New_word;
            p=p->ch[word[i]-'0'];
        }
        else
            p=p->ch[word[i]-'0'];
        //if(i==len-1)
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
        if(p->ch[word[i]-'0']==NULL)
            return 0;
        p=p->ch[word[i]-'0'];
    }
    return p->cnt;
}
int main()
{

    Init_tree();
    char word[50];
    flag=0;
    int num=0;
    while(1)
    {
        scanf("%s",word);
        if(strlen(word)==1)
        {
            flag>0?printf("Set %d is immediately decodable\n",++num):printf("Set %d is not immediately decodable\n",++num);
            flag=0;
            Init_tree();
            //num=0;
            continue;
        }

        if(!flag)
        {
            Insert_tree(word);
            Find_tree(word);
        }
    }
    return 0;
}
