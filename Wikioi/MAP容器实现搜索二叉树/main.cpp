/*
    ��mapʵ�����������

*/
#include <iostream>
#include <map>
using namespace std;
int main()
{
    //����m��intΪ����const char*Ϊֵ
    map <int ,const char *> m;
    //�������з�ֵ
    //pair����
    m.insert(make_pair(1,"one"));
    m.insert(make_pair(3,"three"));
    m.insert(make_pair(4,"four"));
    m.insert(make_pair(2,"two"));

    m.insert(make_pair(5,"five"));
    m.insert(make_pair(10,"ten"));
    //����һ��������ite
    //iterator������
    map <int ,const char *>::iterator ite;
    //����5�����
    ite=m.find(5);
    cout<<ite->first<<endl;
    cout<<ite->second<<endl;
    //�鿴4�Ƿ�ΪҶ��
    ite=m.find(4);
    if(ite==m.end())
        cout<<"YES";
    else
        cout<<"NO";
    cout<<endl;
    //ɾ��10
    m.erase(10);
    //����������
    for(ite=m.begin();ite!=m.end();++ite)
        cout<<ite->first<<' '<<ite->second<<endl;
    return 0;
}
