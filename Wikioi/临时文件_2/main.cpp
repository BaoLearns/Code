/*#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <list>
using namespace std;
int main()
{
	vector <string> str;
	str.push_back("dsjfk");
	str.push_back("dsfklsjdgk");
	//cout<<str.front();
	vector <int > num;
	num.push_back(1);
	num.push_back(2);
	for( vector<int>::iterator i =num.begin(); i != num.end(); ++i)
		cout<<"i = "<<*i<<' ';
	int e=num.front();
	cout<<num.back()<<endl;
	string s;
	s="I love C++";
	e=s.size();
	cout<<e<<endl;
	s=s.substr(1,6);
	cout<<s.size()<<endl;
	//s.repalce(0, 5,"12345");
	printf("%s\n",s.c_str());
	//getline(cin,s);
	list <int> L;
	L.push_back(12);
	L.push_front(1);
	L.push_front(2);
	L.push_back(0);
	L.insert(2,10000);
	for(list <int > ::iterator j = L.begin(); j != L.end(); ++j)
		cout<<*j<<' ';

	return 0;
}
*/
//用迭代器统计字符串里的某个字符
/*
#include <cstdio>
#include <cstdlib>
#include <malloc.h>
#define List_size 100
#define List_size_add 10
typedef struct node
{
    int *base;
    int listsize;
    int length;
}List;

void Init_list( List *L)
{
    L->base=(int *)malloc(List_size * sizeof(int ));
    if(!L->base)
        exit(0);
    L->length = 0;
    L->listsize = List_size;
}
void unio_list(List *New, List *L1, List *L2)
{
    for(int i = 0; i < L1->length; ++i)
    {
        New->base[i] = L1->base[i];
        New->length++;
    }
    int k = New->length;
    for(int i = k; i - k < L2->length; ++i)
    {
        bool flag = true;
        for(int j = 0; j < k; ++j)
        {
            if(New->base[j] == L2->base[i - k])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            New->base[i] = L2->base[i - k];
            New->length++;
        }
    }
}
int main()
{
    List *L1, *L2;
    Init_list( L1);
    Init_list( L2);
    int m = 0;
    for( int i = 0; i < 10; ++i)
    {
        int e;
        scanf("%d", &e);
        L1->base[ m++] = e;
        L1->length++;
    }
    m = 0;
    for( int i = 0; i < 10; ++i)
    {
        int e;
        scanf("%d", &e);
        L2->base[ m++] = e;
        L2->length++;
    }
    List *Newlist;
    Init_list(Newlist);
    unio_list( Newlist, L1, L2);
    return 0;
}
*/
//快速幂
//输入x，i
//求x的i次方
/*#include <cstdio>
long long muilt(int x, int i)
{
	//当i > 1时就一直递归求解
	if(i > 1)
	{
		//当i > 1时就可以将此时x的i次方分为两部分
		long long a = muilt(x, i / 2);
		//当次方i为偶数时，就返回i / 2 * i / 2
		return i % 2 == 0? a * a:a * a * x;
	}
	//直到要求的次方i等于1的时候
	else
		return x;
}
int main()
{
	int x,i;
	while(~scanf("%d%d", &x, &i))
	printf("%lld\n", muilt(x,i));
	return 0;
}
*/
/*
//线段树
#include <cstdio>
#define lson l, m, rx * 2
#define rson m + 1, r, rx * 2 + 1
#define maxn 1000010
int arr[maxn];
int tree[maxn * 4];
int add[maxn * 4];
void Push_up(int rx)
{
	tree[rx] = tree[rx * 2] + tree[rx * 2 + 1];
}
void Push_down(int rx,int m)
{

	if(add[rx])
	{
		add[rx * 2] += add[rx];
		add[rx * 2 + 1] += add[rx];
		tree[rx * 2] +=add[rx] * (m- m/2);
		tree[rx * 2 + 1] += add[rx] * (m / 2);
		add[rx] = 0;
	}
}
void bulid(int l,int r, int rx)
{
	add[rx] = 0;
	if(l == r)
	{
		scanf("%d", &tree[rx]);
		return ;
	}
	int m = (l + r)/ 2;
	bulid(lson);
	bulid(rson);
	Push_up(rx);
}
void updata(int L, int R, int val, int l, int r, int rx)
{
	if(L <= l && r <= R)
	{
		tree[rx] += val * (r - l + 1);
		add[rx]+=val;
		return;
	}
	int m = ( l  + r)/ 2;
	if( L >= m)
		updata( L, R, val, rson);
	if( R < m)
		updata( L, R, val, lson);
	Push_up(rx);
}
long long query(int L, int R, int l, int r, int rx)
{
	if(L <= l && r <= R)
		return tree[rx];
	Push_down(rx, r - l + 1);
	int m = ( l + r)/ 2;
	long long ans=0;
	if(L >= m)
		ans+=query( L, R, rson);
	if( R < m)
		ans+=query( L, R, lson);
	//else
		//ans+=query( L, m, lson) + query( m + 1, R, rson);
	return ans;
}

int main()
{
	int n;
	scanf("%d", &n);
	bulid( 1, 1, n);
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; ++i)
	{
		int op, x, y, z;
		scanf("%d", &op);
		if(op == 1)
		{
			scanf("%d%d%d", &x, &y, &z);
			updata(x, y, z, 1, 1, n);
		}
		else
		{
			scanf("%d%d", &x, &y);
			printf("%lld", query(x, y , 1, 1, n));
		}

	}
	return 0;
}
*/
/*
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
int main()
{
	priority_queue <int > Q;
	int n;
	scanf("%d", &n);
	for( int i = 0; i < n; ++i)
	{
		int e;
		scanf("%d", &e);
		Q.push(e);
	}
    while(!Q.empty())
    {
        printf("%d ",Q.top());
        Q.pop();
    }
    Q.
    putchar('\n');
	return 0;
}
*/
#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
#define INF 10000010
char maze[105][105];
int n,m;
int d[105][105];
int Kx,Ky,Tx,Ty;
struct Key
{
    int x, y;
}Key[10];
typedef pair <int , int > P;
queue <P> Q;
int dir[4][2]={0,1,1,0,-1,0,0,-1};
int bfs(int sx,int sy,int ex, int ey)
{
    for(int i = 0; i < n; ++i)
        for( int j = 0; j < n; ++j)
            d[i][j]=INF;
    Q.push(P(sx, sy));
    while(Q.size())
    {
        P e=Q.front();
        Q.pop();
        if(e.first==ex && e.second==ey)
            break;
        for(int i=0;i<4;++i)
        {
            int dx=e.first + dir[i][0],dy=e.second + dir[i][1];
            if(0<=dx && dx < n && 0<=dy && dy < n && maze[dx][dy]!='#')
            {
                if(maze[dx][dy] == 'S')
                    d[dx][dy]++,maze[dx][dy]='.';
                Q.push(P(dx,dy));
                d[dx][dy]=d[e.first][e.second] + 1;
            }
        }

    }
    return d[ex][ey];
}
int main()
{
    while(true)
    {
        scanf("%d%d", &n, &m);
        if( n == 0 && m == 0)
            break;
        for(int i = 0; i <= n; ++i)
        {
            gets(maze[i]);
            for(int j = 0; j < n; ++j)
            {
                if(maze[i][j] == 'K')
                    Kx=i,Ky=j;
                if(maze[i][j] == 'T')
                    Tx=i, Ty=j;
                if(maze[i][j] >= 49 && maze[i][j] <= 58)
                    Key[maze[i][j]].x=i, Key[maze[i][j]].y=j;
            }
        }
		int ans;
        if( m == 0)
            ans=bfs(Kx, Ky, Tx, Ty);
        else
        {
            ans=bfs(Kx,Ky,Key[1].x, Key[1].y);
            maze[Tx][Ty]='#';
            for(int i = 1; i < m; ++i)
                ans+=bfs(Key[i].x, Key[i].y,Key[i + 1].x, Key[i + 1].y);
            maze[Tx][Ty]='T';
            ans+=bfs(Key[m].x,Key[m].y,Tx, Ty);
        }
        if(ans >= INF)
            printf("impossible\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
