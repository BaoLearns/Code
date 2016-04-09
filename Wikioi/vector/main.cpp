#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector <string >S (100);
int main()
{
    //S.assign(10,"1");
    S.push_back("21212");
    S.push_back("3121");
    S.push_back("53121");
    S.push_back("3412155");
    S.push_back("153121");
    S.insert(S.begin()+1,"sdgds");
    S.insert(S.end(),"dsfjs");
    S.insert(S.end(),S.begin(),S.begin()+3);
    //S.pop_back();
    //S.clear();
    //sort(S.begin(),S.end());
    //vector <string > ::iterator p1= find_if(S.begin,S.end(),inital('2'));
    //cout<<S.front()<<S.back()<<endl;
    //int n=S.empty();
    //cout<<"S.empty() = "<<n<<endl;
    for(vector <string> :: iterator i = S.begin(); i != S.end(); ++i)
        cout<<*i<<' ';
    cout<<endl<<S[S.size()-1]<<endl;
    cout<<S.size()<<endl;
    return 0;
}
