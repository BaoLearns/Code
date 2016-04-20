/*
    title: find maximum subarray
    date: 2016-04-18
    author: oliver bao
    description: given a interge array, find maximum successive subarray.
*/
#include <iostream>
#include <cstdio>

using namespace std;

int INF = -100000007;

int max_left, max_right, left_sum, right_sum;
int ans_left, ans_right, ans_sum;
int SUM;

void find_max_crossing_subarray(int *Array, int low, int mid, int high){
	//cout << "----" << low << " " << mid << " " << high << endl;
    left_sum = INF, SUM = 0;
	for(int index = mid; index >= low; index--){
        SUM += Array[index];
        if( SUM > left_sum){
            left_sum = SUM;
            max_left = index;
		}
	}
    right_sum = INF, SUM = 0;
    for( int index  = mid + 1; index <= high; index++){
        SUM += Array[index];
        if(SUM > right_sum){
            right_sum = SUM;
            max_right = index;
		}
	}
	ans_left = max_left;
	ans_right = max_right;
	ans_sum = left_sum + right_sum;
}
void find_maximum_subarray(int *Array, int low, int high){
	if(low == high){
		ans_left = low;
		ans_right = high;
		ans_sum = Array[low];
		return;
	}
    int mid = low + (high - low) / 2;
	find_maximum_subarray(Array, low, mid);
    int left_low = ans_left, left_high = ans_right, left_sum = ans_sum;
	find_maximum_subarray(Array, mid + 1, high);
    int right_low = ans_left, right_high = ans_right, right_sum = ans_sum;
	find_max_crossing_subarray(Array, low, mid, high);
    int cross_low = ans_left, cross_high = ans_right, cross_sum = ans_sum;
    if( left_sum >= right_sum && left_sum >=  cross_sum){
        ans_left = left_low;
		ans_right = left_high;
	   	ans_sum = left_sum;
	}
	else if( right_sum >= left_sum && right_sum >=  cross_sum){
        ans_left = right_low;
		ans_right = right_high;
		ans_sum = right_sum;
	}
	else if( cross_sum >= left_sum && cross_sum >=  right_sum){
		ans_left = cross_low;
		ans_right = cross_high;
		ans_sum = cross_sum;
	}
}
int main(){
	while(true){
		int k;
		cin >> k;
		if(k == 0)
			break;
		int Array[k];
		bool f = true;
		for(int i = 0; i < k; ++i){
			scanf("%d", &Array[i]);	
			if(Array[i] >= 0)
				f = false;
		}
		find_maximum_subarray(Array, 0, k - 1);
		if(f) 
			cout << 0 << " " << Array[0] << " " << Array[k - 1] << endl;
		else
			cout << ans_sum << " " << Array[ans_left] << " " << Array[ans_right] << endl;	
	}
	return 0;
}





