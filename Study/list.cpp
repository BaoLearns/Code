#include <iostream>
#include <list>
using namespace std;
int main()
{
    list <int> List;
    for(int i = 0; i <= 15; ++i)
        List.push_back(i + 1);
    List.insert(List.begin(), 100);
    List.push_front(-1);    
    List.remove(15);
    for(auto it = List.begin(); it != List.end(); ++it)
        cout << *it << endl;
    list <int> :: reverse_iterator it;
    return 0;
}
