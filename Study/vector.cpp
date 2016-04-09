#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    vector <int> vec;
    vec.reserve(9);
    for(int i = 0; i < 10; ++i) vec.push_back(i + 1);
    cout << vec.size() << endl;
    cout << vec.max_size() << endl;
    cout << vec.capacity() << endl;
    for(auto it = vec.rbegin(); it != vec.rend(); ++it)
        cout << *it << endl;
    vec.insert(vec.begin() + 1, 5, 101);
    vec.pop_back(   );
    for(auto it : vec)
        cout << it << endl;   
    bool alpha;
    cout << std::boolalpha << (&vec[10] == &vec[0] + 10) << endl;
    vector <string> vecs;
    vecs.reserve(5);
    vecs.push_back("Hello old are you?");
    copy(vecs.begin(), vecs.end(), ostream_iterator<string>(cout, ""));
    cout << "!@" << endl;
    return 0;
}
