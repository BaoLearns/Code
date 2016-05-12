#include <iostream>
#include <cstdio>

#include <queue>

using namespace std;

const int MAXN = 100007;

//节点
typedef struct node{
	node(int _req, int _need){
		req = _req;
		need = _need;
	}
	//任务到达的时间,需要执行的时间
	int req;
	int need;
	//重载<
	friend bool operator <(const node &a, const node &b){
		if(a.need != b.need)
			return a.need > b.need;
		return a.req >= b.req;
	}
}node;

int main(){
	//申明变量与输入
	int n;
	int request_time[MAXN];
	int need_time[MAXN];
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &request_time[i]);
	}
	for(int i = 0; i < n; ++i){
		scanf("%d", &need_time[i]);
	}
	
	//优先队列
	priority_queue<node> que;
	//当前时间
	int curr = 0;
	//下标
	int p = 0;
	//等待的总时间
	int total = 0;
	
	for(int i = 0 ; i < n; ++i){
		//将到达时间小于当前时间的加入优先队列
		while(p < n && request_time[p] <= curr){
			que.push(node(request_time[p], need_time[p]));
			p += 1;
		}
		//取出需要执行时间最少的任务
		node q = que.top();
		que.pop();
		printf("request_time%d | need_time%d\n", q.req, q.need);
		//计算此作业等待的时间
		total += curr - q.req;
		//计算当前时间
		curr += q.need;
	}
	//answer
	printf("%lf\n", total * 1.0 / n);
	
	//DONE
	return 0;
}
