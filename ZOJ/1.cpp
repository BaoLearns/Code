#include <iostream>
#include <vector>
using namespace std;
vector<int> vec1, vec2;
int main() {
    int T;
    cin >> T;
    while (T--) {
        vec1.clear(), vec2.clear();
        int N;
        cin >> N;
        int num;
        cin >> num;
        vec1.push_back(num);
        for (int i = 0; i < N - 1; ++i) {
            cin >> num;
            if (num == vec1[0]) vec1.push_back(num);
            else vec2.push_back(num);
        }
        if (vec1.size() == 1) cout << vec1[0] << endl;
        else cout << vec2[0] << endl;
    }
    return 0;
}
