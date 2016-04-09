/*
 *输入一个一元一次方程，求解
 *例如：
 *输入：20x+10=10
 *输出：x=1.000;
 *要求输出保留3位小数
 *
 *
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    string st;//用于存放串
    cin>>st;
    char vi;//用于记录输入的是什么变量
    int f = 0;//存放变量的和
    int dpos;//记录等号的位置
    for(int i = 0; i < st.size(); ++i)
    {
        if(st[i] == '=')//找出等号的位置 
        {
            dpos = i;
            break;
        }
    }
    for(int i = 0; i < st.size(); ++i)//求解变量系数前的和
    {
        if(st[i] >= 'a' && st[i] <= 'z')
        {
            vi = st[i];
            int j;
            if(i == 0)//a在开头
            {
                f += 1;
                st[i] = '!';
            }
            else
            {
                int sum = 0;
                for(j = i - 1; st[j] >= '0' && st[j] <= '9' && j >= 0; --j)//求解变量的系数
                    sum += (st[j] - 48) * (int)pow((double)10,i - j - 1) ;
                if(j >= dpos) sum = -sum;//如果变量在等号的右边，则将系数取反
                if(j >= 0 &&st[j] == '-')//如果变量的符号为-，则和相减
                    f -= sum;
                else                      // 否则相加
                    f += sum;
                for(int k = j; k <= i; ++k)//扫描过了，赋值为!
                    st[k] = '!';
                printf("____________________%d\n",sum);
            }
        }
        
    }
    int s = 0;//存放常量和
    for(int i = 0; i < st.size(); ++i)//求解常量和
    {
        if(st[i] != '!')
        {
            int j = i, sum = 0;
            while(st[j] < '0' || st[j] > '9') j++;//过滤到数字
            int k = j,times = 0;
            while(st[k] >= '0' && st[k] <= '9' && k < st.size()) {times++;k++;}
            for(; st[j] >= '0' && st[j] <= '9' && st[j] != '!' && j < st.size(); ++j)//求解这一常量的和
                    sum += (st[j] - 48) * (int )pow(double(10),--times);
            if(i < dpos) sum = -sum;//如果常量在等号左边，则取反
            if(st[i] == '-') {printf("&&&&&&&&&&&&&&&&&&&&&&\n");s -= sum;}
            else s += sum;
            printf("------------------------%c\n",st[i]);
            printf("*********%d      %d\n",sum,s);
            i = j;
        }
        
    }
    printf("%d %d\n",s, f);
    printf("%c = %.3lf\n", vi,s * 1.0 / f);
    return 0;
}
/*
 * 100+5x-6x=10
 * x=90.000
 *
 * 1000+5c-100c=5c+100-200
 * c=11
*/
