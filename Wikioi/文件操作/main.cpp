#include 0<cstdio>
#include <cstdlib>
int main()
{
    FILE* fp;
    if((fp = fopen("E://Dosk-top//file.txt","w"))== NULL)
    {
        printf("open the file falie;\n");
        exit(0);
    }
    freopen("file_w.txt","r",stdin);
    //char c;
    //while(~scanf("%d", &c))
        //fwrite(&c,sizeof(char),1,fp);
    /*while(!feof(fp))
    {
        fread(&c,sizeof(char),1,fp);
        printf("%c",c);
    }
    */

    //freopen("file_w.txt","w",stdout);
    /*int n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i)
    {
        gets(c[i]);
        for(int j = 0; j < n; ++j)
        {
            if(c[i][j] == '3')
                printf("%c",3);
            else
                printf("%c",c[i][j]);
        }
        putchar('\n');
    }
    //for(int i = 0; i < n; ++i)
        //printf("%s\n",c[i]);
        */
    char c[100][100];
    for(int i = 0; i < 4; ++i)
        gets(c[i]);
    for(int i = 0; i < 4; ++i)
        printf("%s\n",c[i]);
    fclose(fp);
    return 0;
}
