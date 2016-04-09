#include <iostream>
using namespace std;
#define INITSIZE 100   //初始化数组的大小

typedef struct
{
    //i，j是val的坐标
    int i, j;
    double val;
}mat3;

typedef struct 
{
    int mu, nu, tu; //mu是矩阵的行大小，nu是矩阵的列大小，tu是矩阵有几个有效元素
    mat3 data[INITSIZE + 1];
}Mat3;

//输入函数
void InputMat3(Mat3 &m)
{
    cout<<"Enter number mu, nu, tu:";
    cin>>m.mu>>m.nu>>m.tu;
    for(int k = 1; k <= m.tu; ++k)
    {
        cout<<"The "<<k<<"th number:";
        int x, y;
        double z;
        cin>>x>>y>>z;
        if(x > m.mu || x < 1 || y > m.nu || y < 1)
        {
            cout<<"Enter wrong!\n";
            m.tu--;
            continue;
        }
        m.data[k].i = x;
        m.data[k].j= y ;
        m.data[k].val = z;
    }
}

//输出函数
void OutputMat3(Mat3 m)
{
    cout<<"col "<<m.mu<<",row "<<m.nu<<",tu "<<m.tu<<endl;
    for(int k = 1; k <= m.tu; ++k)
        cout<<m.data[k].i<<' '<<m.data[k].j<<' '<<m.data[k].val<<endl;
}

//转置函数
void TreavMat3(Mat3 a, Mat3 &b)
{
    b.mu = a.nu;
    b.nu = a.mu;
    b.tu = a.tu;
    if(b.tu)
    {
        int pos = 1;
        for(int i = 1; i <= a.nu; ++i)
        {
            for(int j = 1; j <= a.tu; ++j)
            {
                if(a.data[j].j == i )
                {
                    b.data[pos].i = a.data[j].j;
                    b.data[pos].j = a.data[j].i;
                    b.data[pos].val = a.data[j].val;
                    pos++;
                }
            }
        }
    }
    
}
int main()
{
    Mat3 a, b;
    InputMat3(a);
    OutputMat3(a);
    cout<<"\n\n\n\n";
    TreavMat3(a, b);
    OutputMat3(b);
    return 0;
}
/*
5 6 5
1 2 1
1 3 2
2 1 3
3 6 4.2
5 2 5.0
*/
