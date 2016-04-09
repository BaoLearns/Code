/*#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <locale>

using namespace std;

int main(){
    locale china("chs");
    wcin.imbue(china);
    wcout.imbue(china);
    ifstream input("in.txt");
    input.imbue(china);
    wstring st;
    wchar_t wd = L‘。’;
    if(input.fail()){
        cerr << "No in.txt" << endl;
        exit(-1);
    }
    while(getline(input, st, wd)){
        wcout << st << endl;
    }
    input.close();
    return 0;
}
*/
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    char c[10]="今天\0";
    cout<<c<<endl;
    for(int i=0;i<10;++i)
        cout<<int(c[i])<<endl;
    char ch[3]={-67,-15,0};
    cout<<ch<<endl;
    char ch1[200] = "今天是个好天气！";
    cout << ch1 << endl;
    for(int i = 0; i < 16; ++i)
        cout << ch1[i] << ch1[i+1];
    return 0;
}
