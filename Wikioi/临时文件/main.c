#include <stdio.h>
int main()
{
    FILE *f;
    if((f=fopen("E:\\Dosk-top\\file.txt","r+"))==NULL)
       printf("222\n");
    char s[100];
    scanf("%s",s);
    int i;
    for(i=0;s[i]!='\n';++i)
        fputc(s[i],f);
    fclose(f);
    return 0;
}
