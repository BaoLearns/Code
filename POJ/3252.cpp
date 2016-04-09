#include <iostream>
#include <queue>
using namespace std;

class Integer{
private:
	int _num;
	//getLength()������ȡ_num����
	int getLength(){
	}
public:
	//Integer�๹�캯��
	Integer(int num){
		_num = num;
	}
	//��ת_num
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

