#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, s, t;
        cin >> n >> s >> t;
        int ans = -1;
        if(abs(n - s) == 1)
            ans = 1;
        if(abs(n - s) == n - 1)
            ans = 0;
        cout << ans << endl;
    }
    return 0;
}
