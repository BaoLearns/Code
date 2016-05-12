#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> arr;
bool leap(int year){
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}

void init(){
	int syear = 1753, smonth = 1, sday = 1;
	int end = 99991231;
	int week = 0;
	int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	while(true){
		int now = syear * 10000 + smonth * 100 + sday;
		if(now > end)
			break;
		if(week == 0 && (sday == 1 || sday == 11 || sday == 21))
			arr.push_back(now);
		week += 1;
		week %= 7;
		sday += 1;
		if(sday > month[smonth]){
			smonth += 1;
			sday = 1;
		}
		if(smonth > 12){
			syear += 1;
			smonth = 1;
			if(leap(syear))
				month[2] = 29;
			else
				month[2] = 28;
		}
	}
}


int main(){
	init();
	int t;
	scanf("%d", &t);
	while (t--){
		int year, month, day, n;
		scanf("%d%d%d%d", &year, &month, &day, &n);
		int v = day + month * 100 + year * 10000;
		int ans = arr[upper_bound(arr.begin(), arr.end(), v) - arr.begin() + n -2];
		printf("%d %d %d\n", ans / 10000, ans % 10000 / 100, ans % 100);
	}
	return 0;
}

