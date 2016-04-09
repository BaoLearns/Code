/*
    用map实现排序二叉树

*/
#include <iostream>
#include <map>
using namespace std;
int main()
{
    //声明m，int为键，const char*为值
    map <int ,const char *> m;
    //在容器中放值
    //pair容器
    m.insert(make_pair(1,"one"));
    m.insert(make_pair(3,"three"));
    m.insert(make_pair(4,"four"));
    m.insert(make_pair(2,"two"));

    m.insert(make_pair(5,"five"));
    m.insert(make_pair(10,"ten"));
    //制造一个迭代器ite
    //iterator迭代器
    map <int ,const char *>::iterator ite;
    //查找5这个店
    ite=m.find(5);
    cout<<ite->first<<endl;
    cout<<ite->second<<endl;
    //查看4是否为叶子
    ite=m.find(4);
    if(ite==m.end())
        cout<<"YES";
    else
        cout<<"NO";
    cout<<endl;
    //删除10
    m.erase(10);
    //遍历整个树
    for(ite=m.begin();ite!=m.end();++ite)
        cout<<ite->first<<' '<<ite->second<<endl;
    return 0;
}
