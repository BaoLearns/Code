/*#include <iostream>
using namespace std;
int A[2][2];
int B[2][2];
int C[2][2];
void mul(int A[2][2], int B[2][2], int m)
{
    //int** C;
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
            C[i][j] = 0;
    for(int i = 0; i < 2; ++i)
        for(int k = 0; k < 2; ++k)
            for(int j = 0; j < 2; ++j)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % m;
   //return C; 
}
void Pow(int A[2][2], int n, int m)
{
    //int B[2][2];
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
            B[i][j] = 1;
    while(n)
    {
        if(n & 1) B = C;
        A = C;
        n >>= 1;
    }
    //return B;
}
int main()
{
    A[0][0] = 1;
    A[0][1] = 1;
    A[1][0] = 1;
    A[1][1] = 0;
    int n, m;
    cin >> n >> m;
    //A = Pow(A, n, m);
    cout << A[1][0] << endl;
    return 0;
}
*/

/*
#include <cstdio>
#include <vector>
#define vec vector <LL>
#define mat vector <vec>
#define LL long long
using namespace std;
mat mul(mat A, mat B, LL q)
{
    mat C(A.size(), vec(B[0].size()));
    for(int i = 0; i < A.size(); ++i)
        for(int k = 0; k < B.size(); ++k)
            for(int j = 0; j < B[0].size(); ++j)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % q;
    return C;
}
mat Pow(mat A, LL n, LL q)
{
    mat B(A.size(), vec(A.size()));
    for(int i = 0; i < A.size(); ++i)
        B[i][i] = 1;
    while(n)
    {
        if(n & 1) B = mul(A, B, q);
        A = mul(A, A, q);
        n >>= 1;
    }
    return B;

}
int main()
{
    LL n;
    while(~scanf("%lld", &n) && n != -1)
    {
        mat A(2, vec(2));
        A[0][0] = 1;
        A[0][1] = 1;
        A[1][0] = 1;
        A[1][1] = 0;
        A = Pow(A, n, 10000);
        printf("%lld\n", A[1][0]);//cout << A[1][0] << endl;       
    }
    return 0;
}
*/

#include <cstdio>
using namespace std;
struct Node
{
    
}
int main()
{
    return 0;
}
