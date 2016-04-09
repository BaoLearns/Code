/*
    begin()          返回指向map头部的迭代器
    clear(）         删除所有元素
    count()          返回指定元素出现的次数
    empty()          如果map为空则返回true
    end()            返回指向map末尾的迭代器
    equal_range()    返回特殊条目的迭代器对
    erase()          删除一个元素
    find()           查找一个元素
    get_allocator()  返回map的配置器
    insert()         插入元素
    key_comp()       返回比较元素key的函数
    lower_bound()    返回键值>=给定元素的第一个位置
    max_size()       返回可以容纳的最大元素个数
    rbegin()         返回一个指向map尾部的逆向迭代器
    rend()           返回一个指向map头部的逆向迭代器
    size()           返回map中元素的个数
    swap()            交换两个map
    upper_bound()     返回键值>给定元素的第一个位置
    value_comp()      返回比较元素value的函数
*/
/*
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main()
{
    map <int , int> M;
    map <int , int> :: iterator It;
    cout << (M.empty() ? "Yes" : "No") << endl;
    cout << M.max_size() << endl;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        //M.insert(pair<int, int> (a, b));
        M[a] = b;
    }
    M.erase(1);
    for(map <int , int>::iterator it = M.begin(); it != M.end(); ++it)
        cout << it->first << ' ' << it->second << endl;
    cout << M.count(1) << endl;
    It = M.find(2);
    cout << It -> first << "  " << It -> second << endl;
    cout << (M.empty() ? "Yes" : "No") << endl;
    cout << M.max_size() << endl;
    return 0;
}
*/
/*
//统计单词个数，用Map实现
#include <bits/stdc++.h>
using namespace std;
int main()
{
    map <string, int> M;
    string st;
    while(cin >> st)
        M[st]++;
    for(map <string, int> :: iterator it = M.begin(); it != M.end(); ++it)
        cout << it -> first << " " << it -> second << endl;
    return 0;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string st;
    map <string, string> Map;
    while(cin >> st)
        Map[st];
    for(map <string, string> :: iterator it = Map.begin(); it != Map.end(); ++it)
    cout << it -> first << " " << it -> second << endl;
        cout << Map.size() << endl;
    return 0;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;
int main()
{
    multimap <string, string> Mumap;
    string st1, st2;
    int n = 1;
    while(cin >> st1 >> st2)
    {
        if(n++ == 5) break; 
        Mumap.insert(make_pair(st1, st2));
    }
    cin >> st1;

    int count = Mumap.count(st1);
    multimap <string, string> :: iterator iter  = Mumap.find(st1);
    while(count)
    {
        cout << iter -> second << endl;
        iter++;
        count--;
    }

    for(multimap <string, string> :: iterator beg = Mumap.lower_bound(st1), en = Mumap.upper_bound(st1); beg != en; ++beg)
        cout << beg -> second << endl;
    
    pair <multimap <string , string> :: iterator, multimap <string, string> :: iterator> P = Mumap.equal_range(st1);
    while(P.first != P.second)
    {
        cout << P.first -> second << endl;
        P.first++;
    }

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    multimap <int, int> Map;
    Map.insert(make_pair(1, 2));
    Map.insert(pair <int, int>(1, 3));
    auto end = Map.end();
    for(multimap<int, int>::iterator beg = Map.lower_bound(1), end = Map.upper_bound(1); beg != end; ++beg)
        cout << beg -> first << " " << beg -> second << endl;
    int count = Map.count(1);
    auto it = Map.find(1);
    while(count--)
    {
        cout << it -> first << " " << it -> second << endl;
        it++;
    }
    for(auto beg = Map.equal_range(1).first, end = Map.equal_range(1).second; beg != end; ++beg)
        cout << beg -> first << " " << beg -> second << endl;
    return 0;
}
