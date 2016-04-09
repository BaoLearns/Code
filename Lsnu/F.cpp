/*************************************************************************      > File Name: F.cpp
    > Author: Royecode
    > Mail: Royecode@163.com 
    > Created Time: 2015年10月11日 星期日 15时53分41秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char **argv)
{
	int n; 
    cin >> n;  
    int arr[n];
	for (int i = 0; i < n; ++i) 
	   cin >> arr[i];
	sort(arr, arr + n);	
    int ans = 0;
	for (int i = 0; i < (n + 1) / 2; ++i)  
		ans += (arr[i] + 1) / 2;
    cout << ans << endl;  
    return 0;
}
