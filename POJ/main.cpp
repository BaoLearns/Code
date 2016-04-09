#include <iostream>
#include <typeinfo>
using namespace std;
class List
{
public:
    int val;
    List* next;
};
int main()
{
    int a = 1, b = 424;
    a |= b;
    b ^= a;
    a ^= b;
    cout << a << " " << b << endl;
    int n;
    cin >> n;
    string st;
    cout << typeid(st).name() << endl;
    List* head = new List;
    List* q = new List; // malloc()
    head = q;
    for(int i = 0; i < n; ++i)
    {
        int e;
        cin >> e;
        List* p = new List;
        p -> val = e;
        p -> next = NULL;
        q -> next = p;
        q = p;
    }
    head = head -> next;
    while(head != NULL)
    {
        cout << head -> val << endl;
        head = head -> next;
    }
    return 0;
}
