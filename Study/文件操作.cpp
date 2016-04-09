#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
    FILE *f;
    if((f = fopen("a.in", "r")) == NULL)
    {
        cout << "Wrong" << endl;
        exit(0);
    }
    char ch;
    while(!feof(f))
    {
        ch = fgetc(f);
        cout << ch << endl;
        //fseek(f, 2L, 1);
    }
    fclose(f);
    return 0;
}
