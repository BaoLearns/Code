#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;
int solve()
{
    map <char, int> Map;   //定义运算符的优先级
    Map['('] = 0;
    Map['+'] = Map['-'] = 1;
    Map['*'] = Map['/'] = 2;
    string st1;
    cin >> st1;
    int len1 = st1.length();
    stack <char> Stack1;  //存储中缀表达式的运算符
    string st2;           //存储后缀表达式
    //将中缀表达式转换为后缀表达式
    for(int i = 0; i < len1; ++i)
    {
        if(st1[i] == ' ') continue;
        if(st1[i] >= '0' && st1[i] <= '9')   //1.处理连续的数字，并输出到后缀表达式
        {
            int j = i;
            while(j < len1 && st1[j] >= '0' && st1[j] <= '9')
            {
                st2 += st1[j];
                j++;
            }
            st2 += ' ';
            i = j - 1;
        }
        else if(Stack1.empty()) Stack1.push(st1[i]); //2.若栈空，将运算符压栈
        else if(st1[i] == '(') Stack1.push(st1[i]);  //3.若遇'('运算符，压栈
        else if(st1[i] == ')')                       //4.若遇')'运算符，出栈直到'('，并将出栈的运算符输出至后缀表达式
        {
            while(Stack1.top() != '(')
            {
                st2 += Stack1.top();
                st2 += ' ';
                Stack1.pop();
            }
            Stack1.pop();
        }
        else    //5.遇到其他运算符：加减乘除,弹出所有优先级大于或者等于该运算符的栈顶元素并将出栈的运算符输出至后缀表达式，然后将该运算符入栈
        {
            while(!Stack1.empty() && Map[Stack1.top()] >= Map[st1[i]])
            {
                st2 += Stack1.top();
                st2 += ' ';
                Stack1.pop();
            }
            Stack1.push(st1[i]);
        }
    }                                        
    while(!Stack1.empty())      //6.将栈中所有元素输出至后缀表达式 
    {
        if(Stack1.top() != '(' && Stack1.top() != ')')
        {
            st2 += Stack1.top();
            st2 += ' ';
        }
        Stack1.pop();
    }
    int len2 = st2.length();
    stack <int> Stack2; //存储运算数
    //运算后缀表达式
    for(int i = 0; i < len2; i += 2) 
    {
        if(st2[i] >= '0' && st2[i] <= '9') //1.将后缀表达式连续的数字转换为一个数字，并压栈
        {
            int j = i, v = 0;
            while(j < len2 && st2[j] >= '0' && st2[j] <= '9')
            {
                v = v * 10 + st2[j] - '0';
                j++;
            }
            i = j - 1;
            Stack2.push(v);
        }
        else //2.取出两个运算数，做运算，并将结果压栈
        {
            int a = Stack2.top(); Stack2.pop();
            int b = Stack2.top(); Stack2.pop();
            int c;
            if(st2[i] == '+') c = b + a;
            else if(st2[i] == '-') c = b - a;
            else if(st2[i] == '*') c = b * a;
            else c = b / a;
            Stack2.push(c);
        }
    }
    return Stack2.top();
}
int main()
{
    int val = solve();
    cout << val;
    return 0;
}

/*
input:
(1+2)*((8-2)/(7-4))
output:
6
*/    
