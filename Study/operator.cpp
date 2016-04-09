/*#include <bits/stdc++.h>
using namespace std;
class my
{
private:
    double x, y;
public:
    my(){}
    my(double x1, double y1)
    {
        x = x1;
        y = y1;
    }
    my operator + (my &a)
    {
        my c;
        c.x = x - a.x;
        c.y = y - a.y;
        return c;
    }
    void display()
    {
        cout << x << " " << y << endl;
    }
    bool operator > (my &a)
    {
        return y < a.y;
    }
};
int main()
{
    my a(1.0, 9.3), b(1.5, 5.2);
    my c = a + b;
    c.display();
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x, y;
    bool operator < (const node &a)
    {
        return y > a.y;
    }
}arr[100];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i].x >> arr[i].y;
    sort(arr, arr + n);
    for(int i = 0; i < n; ++i)
        cout << arr[i].x << "   " << arr[i].y << endl;
     return 0;
}






