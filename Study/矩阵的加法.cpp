#include <iostream>
#include <cstring>
using namespace std;
#define INITSIZE 100
typedef struct 
{
    int i, j, val;
}mat3;
typedef struct 
{
    mat3 data[INITSIZE];
    int mu, nu, tu;
}Mat3;

void InputMat3(Mat3 &M)
{
    cin>>M.mu>>M.nu>>M.tu;
    for(int i = 1; i <= M.tu; ++i)
        cin>>M.data[i].i>>M.data[i].j>>M.data[i].val;
}

void OutputMat3(Mat3 M)
{
    cout<<"Row is "<<M.mu<<",Col is "<<M.nu<<", Numbers is "<<M.tu<<endl;
    int a[M.mu][M.nu];
    for(int i = 1; i <= M.mu; ++i)
        for(int j = 1; j <= M.nu; ++j)
            a[i][j] = 0;
    for(int i = 1; i <= M.tu; ++i)
        a[M.data[i].i][M.data[i].j] = M.data[i].val;
    for(int i = 1; i <= M.mu; ++i)
    {
        for(int j = 1; j <= M.nu; ++j)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }
}

void AddMat3(Mat3 M, Mat3 N, Mat3 &T)
{
    if(M.mu != N.mu || M.nu != N.nu)
        return ;
    T.mu = M.mu;
    T.nu = M.nu;
    T.tu = 0;
    int PosM = 1, PosN = 1;
    while(PosM <= M.tu && PosN <= N.tu)
    {
        if(M.data[PosM].i < N.data[PosN].i ||( M.data[PosM].i == N.data[PosN].i && M.data[PosM].j < N.data[PosN].j ))
        {
            T.data[++T.tu].i = M.data[PosM].i;
            T.data[T.tu].j = M.data[PosM].j;
            T.data[T.tu]. val = M.data[PosM].val;
            PosM++;
        }
        else if(M.data[PosM].i == N.data[PosN].i && M.data[PosM].j == N.data[PosN].j)
        {
            
            T.data[++T.tu].i = M.data[PosM].i;
            T.data[T.tu].j = M.data[PosM].j;
            T.data[T.tu]. val = M.data[PosM].val + N.data[PosN].val;
            PosM++;
            PosN++;
        
        }
        else
        {
            
            T.data[++T.tu].i = N.data[PosN].i;
            T.data[T.tu].j = N.data[PosN].j;
            T.data[T.tu]. val = N.data[PosN].val;
            PosN++;
        }
    
    
    }
    while(PosM <= M.tu)
    {
        
            T.data[++T.tu].i = M.data[PosM].i;
            T.data[T.tu].j = M.data[PosM].j;
            T.data[T.tu]. val = M.data[PosM].val;
            PosM++;
    }
    
    while(PosN <= N.tu)
    {
        
            T.data[++T.tu].i = N.data[PosN].i;
            T.data[T.tu].j = N.data[PosN].j;
            T.data[T.tu]. val = N.data[PosN].val;
            PosN++;
    }

}
int main()
{
    Mat3 A, B, C;
    InputMat3(A);
    InputMat3(B);
    AddMat3(A, B, C);
    OutputMat3(C);
    return 0;
}
