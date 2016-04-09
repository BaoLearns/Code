//用class，输出10个数中最大的值
#include <iostream>
using namespace std;
class Arr_max
{
private:
    int arr[10];
    int max;
public:
    void Arr_max_set()
    {
        for(int i=0;i<10;++i)
            cin>>arr[i];
    }
    void Arr_max_find()
    {
        max=arr[0];
        for(int i=1;i<10;++i)
            if(max<arr[i]) max=arr[i];
    }
    void Arr_max_show()
    {
        cout<<max;
    }
};
int main()
{
    Arr_max S;
    S.Arr_max_set();
    S.Arr_max_find();
    S.Arr_max_show();

    return 0;
}
