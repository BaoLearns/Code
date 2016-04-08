/*************************************************************************
    > File Name: Heap.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月14日 星期三 22时32分48秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Heap
{
public:
	Heap()
	{
		num = NULL;
		size = 0;
	}
	Heap(int _size)
	{
		num = new int[_size];
		if(!num) exit(-1);
		size = 0;
	}
	void push_down()
	{
		for(int i = 1, j = i * 2; j <= size; i = j, j = i * 2)
		{
			if(j + 1 <= size && num[j] < num[j + 1]) j++;
			if(num[i] < num[j]) swap(num[i], num[j]);
			else break;
		}
	}
	void push_up()
	{
		for(int i = size, j = size / 2; j > 0; i = j, j = i / 2)
		{
			if(num[i] > num[j]) swap(num[i], num[j]);
			else break;
		}
	}
	void insert(int x)
	{
		size++;
		num[size] = x;
		push_up();
	}
	int delete_()
	{
		int x = num[1];
		swap(num[1], num[size]);
		size--;
		push_down();
		return x;
	}
private:
	int *num;
	int size;
};
int main(int argc, char **argv)
{
	Heap heap(10);
	srand(time(NULL));
	for(int i = 0; i < 10; ++i)
	{
		int x = rand() % 100;
		heap.insert(x);
		cout << x << " ";
	}
	cout << endl;
	for(int i = 0; i < 10; ++i)
		cout << heap.delete_() << " ";
	cout << endl;
    return 0;
}
