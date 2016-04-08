/*************************************************************************
    > File Name: delAaddB.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2016年02月03日 星期三 21时14分44秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1e5;

char *deleteAcopyB(char *st){
	int old_Length = strlen(st);//原字符串长度
	int deleteA_Length = 0; //删除'a'后的长度
	int number = 0; //'b'的个数
	for(int i = 0; i < old_Length; ++i){//删除'a'字符
		if(st[i] != 'a') st[deleteA_Length++] = st[i];
		if(st[i] == 'b') number++;//统计'b'的个数
	}
	int new_Length = deleteA_Length + number;//新字符串长度
	st[new_Length] = '\0';
	for(int i = deleteA_Length - 1, j = new_Length - 1; i >= 0; --i){//复制'b'字符
		st[j--] = st[i];
		if(st[i] == 'b') st[j--] = st[i];
	}
	return st;
}

int main(int argc, char **argv){
	char st[MAXN];
	while(cin >> st){
		cout << deleteAcopyB(st) << endl;
	}
    return 0;
}
