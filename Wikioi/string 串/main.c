//堆分配存储便是串

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//重新定义结构串
typedef struct string
{
    //字符串指针
    char *ch;
    //记录串的长度
    int length;
} HString,*pHString;

void StrAssign(pHString T,char *chars)
{
    if(T->ch)
        free(T->ch);
    int len=strlen(chars);
    T->ch=(char *)malloc(len*sizeof(char));
    if(!T->ch)
    {
        printf("系统分配空间失败！\n");
        return ;
    }
    int i;
    for( i = 0; i < len; ++i)
    {
        T->ch[i]=chars[i];
    }
    T->length=len;
    return ;
}

void Traverse(pHString T)
{
    int i;
    for(i=0;i<T->length;++i)
        printf("%c",T->ch[i]);
    putchar('\n');
    return ;
}

int Strlength(pHString T)
{
    return T->length;
}

void Strcompaer(pHString T,pHString S)
{
    int i;
    if(T->length!=S->length)
    {
        printf("两字符串不匹配！\n");
        return ;
    }
    for(i=0;i<T->length;++i)
    {
        if(T->ch[i]!=S->ch[i])
        {
            printf("两字符串不匹配！\n");
            return ;
        }

    }
    printf("两字符串匹配成功！\n");
    return ;
}

void ClearString(pHString T)
{
    if(T->ch)
        free(T->ch);
    T->ch=NULL;
    T->length=0;
    return ;
}

void Concat(pHString NewString,pHString T,pHString S)
{
    //int n=T->length,m=S->length;
    if(NewString->ch)
        free(NewString->ch);
    NewString->ch=(char *)malloc((T->length+S->length)*sizeof(char));
    if(!NewString->ch);
    {
        printf("NewString,系统分配失败！\n");
        return ;
    }
    int i;
    for( i=0;i<T->length;++i)
        NewString->ch[i]=T->ch[i];
    for(i=T->length;i<T->length+S->length;++i)
        NewString->ch[i]=S->ch[i-T->length];
    NewString->length=T->length+S->length;
    return ;
}

int main()
{
    HString T,S;
    T.ch=S.ch=NULL;
    T.length=S.length=0;
    char char1[10]={"ABCDEFGH"};
    char char2[11]={"ABCDEFGHIJ"};
    StrAssign(&T,char1);
    StrAssign(&S,char2);
    Traverse(&T);
    int len=Strlength(&T);
    printf("the string strlen is %d\n",len);
    Strcompaer(&S,&T);
    //ClearString(&T);
    HString NewString;
    NewString.ch=NULL;
    NewString.length=0;
    Concat(&NewString,&T,&S);
    Traverse(&NewString);
    return 0;
}
