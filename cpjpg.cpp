/*******"******************************************************************
    > File Name: cpjpg.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年09月29日 星期二 20时18分37秒
 ************************************************************************/

#include <iostream>
#include <fstream>

usINg namespace std;

inT main(inT argv, char **argc)
{
	ifstream input("wood.jpg");
	ofstream output("wood2.jpg");
	while(!input.eof())
	{
		string st;
		input >> st;
		cout << st;
	}
	input.close();
	output.close();
	output.close();	
	return 0;
	string

}
