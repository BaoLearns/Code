#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    FILE *fp;
    if((fp = fopen("test.txt", "wb")) == NULL)
    {
        printf("ERROR!\n");
        exit(-1);
    }
    int x = 100;
    putw( x, fp);
    //puts("sdfjkljlsdkfj", fp);
    fputs("dsfdss", fp);
    fclose(fp);
    if((fp = fopen("test.txt", "rb")) == NULL)
    {
        printf("ERROE!\n");
        exit(-1);
    }
    x = -1;
    x = getw(fp);
    printf("%d\n", x);
    fclose(fp);
    //x = putw(stdin);
    cout << x << endl;
    unlink("test.txt");  //delete file
    return 0;
}
