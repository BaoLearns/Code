#include <iostream>
#include <queue>
using namespace std;

class Integer{
private:
	int _num;
	//getLength()函数获取_num长度
	int getLength(){
	}
public:
	//Integer类构造函数
	Integer(int num){
		_num = num;
	}
	//反转_num
	int inversed(){
		queue <int> S;
		int m = _num;
		while (m)
		{
			S.push(m % 10);
			m /= 10;
		}
		while (!S.empty())
		{
			m = m * 10 + S.front();
			S.pop();
		}
		return m;
	}
};

int main() {
	int n;
	cin >> n;
	Integer integer(n);
	cout << integer.inversed() << endl;
}

