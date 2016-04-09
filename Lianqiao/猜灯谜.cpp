#include <iostream>
using namespace std;
void f(char* from, char* to)
{
    char* p_from = from;
    char* p_to = to;
    printf("%s\n", p_from); 
    while(*p_from==' ' || *p_from=='\t' || *p_from=='\n') p_from++; 
    do{
        if(*p_from==' ' || *p_from=='\t' || *p_from=='\n'){ 
            do{p_from++;}
            while(*p_from==' ' || *p_from=='\t' || *p_from=='\n');
            if(*p_from != '\0') *p_to++ = ' '; //Ìî¿ÕÎ»
        }
    }while(*p_to++ = *p_from++);
    //cout << p_to << endl;
}


int main()
{
    /*
       cout << 953 * 953 << endl;
       for(int a = 0; a < 10; ++a)
       for(int b = 0; b < 10; ++b)
       for(int c = 0; c < 10; ++c)
       for(int d = 0; d < 10; ++d)
       for(int e = 0; e < 10; ++e)
       for(int f = 0; f < 10; ++f)
       {
       if(a != b && a != c && a != d && a != e && a != d && b != c && b != d && b != e && b != f && c != d && c != e && c != f && d != e && d != f && e != f && (a * 100 + b * 10 + c) * (a * 100 + b * 10 + c) == a * 100000 + d * 10000 + e * 1000 + f * 100 + d * 10 + b)
       {
       cout << a << b << c << d << e << f << endl;
       return 0;
       }
       }
       */
    char from[100] = "af   sdggg         ";
    char to[100];
    f(from, to);
    cout << to << endl;
    return 0;
}
