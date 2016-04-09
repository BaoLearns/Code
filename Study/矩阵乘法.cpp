#include <iostream>
#include <cstring>
using namespace std;
#define MAXSIZE 100 //初始化TSMatrix的大小
typedef int elemp;
typedef struct        // 矩阵的三元组Triple
{
	int i, j;        
	elemp e;          // i，j是非0元素e的行列下标
}Triple;

typedef struct                   //矩阵TSMatrix
{
	Triple data[MAXSIZE + 1];    // 三元组数组,data[0]不用，即下标从1开始
	int mu, nu, tu;     // 矩阵的行数，列数，非0元素的个数，行号，列号都从1开始
}TSMatrix;


//创建输入矩阵
void InputTSMatrix(TSMatrix &M)
{
    cout<<"Enter TSMatrix row, col, num!\n";
    cin>>M.mu>>M.nu>>M.tu;
    for(int i = 1; i <= M.tu; ++i)
        cin>>M.data[i].i>>M.data[i].j>>M.data[i].e;
}

//输出矩阵
void OutputTSMatrix(TSMatrix M)
{
    //cout<<"****************************\n\n";
    cout<<"TSMatrix row "<<M.mu<<",col "<<M.nu<<",num "<<M.tu<<endl;
    for(int i = 1; i <= M.tu; ++i)
        cout<<M.data[i].i<<' '<<M.data[i].j<<' '<<M.data[i].e<<endl;
    //cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n";
}

//时间复杂度O（M.tu * max（M.nu， N.tu）），两重循环完成
bool MultiMatrix(TSMatrix M, TSMatrix N, TSMatrix &Q)  // M矩阵乘上N矩阵得Q矩阵
{
	if(M.nu != N.mu) return false;                     // 判断是否可以相乘
	Q.mu = M.mu;
	Q.nu = N.nu;
	Q.tu = 0;
	int row, k, col;    //row是M矩阵行号变量，k是用于M矩阵三元组的下标，col临时变量
	elemp ctemp[MAXSIZE + 1];      //临时数组，用于存放压缩的值
	memset(ctemp, 0, sizeof(ctemp));                   //将ctemp数组初始化为0
	if(M.tu * N.tu)                          // 两非0矩阵才进行矩阵乘法
	{
		k = 1, row = 1;       //k从M.data[]的第一个开始扫描，行号从1开始扫描
		while(k <= M.tu)     //k 从M矩阵的第一个元素扫描到M.mu，即1到 M.tu
		{
			if(M.data[k].i != row)               //如果当前元素的i值与row不同，就说明上一次M矩阵行号为row - 1已经扫描完成，就应该将ctemp数组非0的值赋给Q矩阵
			{
				for(col = 1; col <= Q.nu; ++col)  //将ctemp数组非0元素赋值给Q矩阵
				{
					if(ctemp[col])                     // 判断是否为0
					{
						if(++Q.tu > MAXSIZE) return false;  //判断Q矩阵的非0元素个数是否大于三元组的容量，即Q矩阵是否还能存下
						Q.data[Q.tu].i = row;
						Q.data[Q.tu].j = col;
                        Q.data[Q.tu].e = ctemp[col];
					}
				}
                memset(ctemp , 0, sizeof(ctemp));
                row++;         //此行扫描完毕，扫描下一行
			}
            else          //M当前元素的行号等于我们要扫描的行坐标，即M.data[k].i == row,就应该在N矩阵扫描每一个元素找行号等于M矩阵当前元素的列号
            {         
                for(col = 1; col <= N.tu; ++col)
                {
                    if(M.data[k].j == N.data[col].i )
                        ctemp[N.data[col].j] += M.data[k].e * N.data[col].e;
                }
                k++;
            }
		}
        //当所有M矩阵元素扫描完成之后，最后一次ctemp数组的值还没被赋值到Q矩阵中去，所以还得将最后一次ctemp数组中非0值赋值到Q矩阵
        for(col = 1; col <= Q.nu; ++col)
		{
				if(ctemp[col])
				{
					if(++Q.tu > MAXSIZE)  return false;
					Q.data[Q.tu].i = row;
					Q.data[Q.tu].j = col;
                    Q.data[Q.tu].e = ctemp[col];
				}
		}
	}
	return true;
}
/*
void MultiMatrix(TSMatrix M, TSMatrix N, TSMatrix &T)
{
    if(M.nu != N.mu) return;
    T.mu = M.mu;
    T.nu = N.nu;
    T.tu = 0;
    int Mnum = 1;
    int ctemp[INITSIZE];
    for(int Mrow = 1; Mrow <= M.mu; ++Mrow)
    {
        memset(ctemp, 0, sizeof(ctemp));
        while(M.data[Mnum].i == Mrow && Mnum <= M.tu)
        {
            
            for(int Nnum = 1; Nnum <= N.tu; ++Nnum)
            {
                if(M.data[Mnum].j == N.data[Nnum].i)
                    ctemp[N.data[Nnum].j] += M.data[Mnum].val * N.data[Nnum].val;
            }
            Mnum++;
        }
        for(int col = 1; col <= N.nu; ++col)
        {
            if(ctemp[col])
            {
                if(++T.tu > INITSIZE) return ;
                T.data[T.tu].i = Mrow;
                T.data[T.tu].j = col;
                T.data[T.tu].val = ctemp[col];
            }
        }
    }
}
*/
int main()
{
    TSMatrix A, B, C;
    InputTSMatrix(A);
    //OutputTSMatrix(A);
    InputTSMatrix(B);
    //OutputTSMatrix(B);
    MultiMatrix(A, B, C);
    cout<<"\n\nA * B = C:"<<endl;
    OutputTSMatrix(C);
    return 0;
}
/*
3 2 4
1 1 1
2 1 3
2 2 4
3 2 2
2 3 4
1 1 2
1 3 3
2 1 1
2 2 1

3 3 7
1 1 2
1 3 3
2 1 10
2 2 4
2 3 9
3 1 2
3 2 2
*/
