/*
#include <iostream>
#define m l + (r - l) / 2
#define lson rx * 2, l, m
#define rson rx * 2 + 1, m + 1, r
#define MAXN 10005
using namespace std;
int tree[MAXN], add[MAXN];
void Pushdown(int rx, int l, int r)
{
	if(add[rx])
	{
		add[rx * 2] += add[rx];
		add[rx * 2 + 1] += add[rx];
		tree[rx * 2] += (m - l + 1) * add[rx];
		tree[rx * 2 + 1] += (r - m) * add[rx];
		add[rx] = 0;
	}
}
void Bulid(int rx, int l, int r)
{
	add[rx] = 0;
	if(l == r)
	{
		cin >> tree[rx];
		return ;
	}
	Bulid(lson);
	Bulid(rson);
	tree[rx] = tree[rx * 2] + tree[rx * 2 + 1];
}
void Update_point(int rx, int l, int r, int pos, int v)
{
	if(l > pos || r < pos) return;
	if(l == r)
	{
		tree[rx] = v;
		return ;
	}
	Update_point(lson, pos, v);
	Update_point(rson, pos, v);
	tree[rx] = tree[rx * 2] + tree[rx * 2 + 1];
}
void Update_section(int rx, int l, int r, int L, int R, int v)
{
	if(R < l || L > r) return;
	if(L <= l && r <= R)
	{
		tree[rx] += (r - l + 1) * v;
		add[rx] += v;
		return ;
	}
	Update_section(lson, L, R, v);
	Update_section(rson, L, R, v);
	tree[rx] = tree[rx * 2] + tree[rx * 2 + 1];
}

int Query(int rx, int l, int r, int L, int R)
{
	if(R < l || L > r) return 0;
	Pushdown(rx, l, r);
	if(L <= l && r <= R) return tree[rx];
	return Query(lson, L, R) + Query(rson, L, R);
}
int main()
{
	int n, q;
	cin >> n >> q;
	Bulid(1, 1, n);
	while(q--)
	{
		int op;
		cin >> op;
		if(op == 1)
		{
			int pos, v;
			cin >> pos >> v;
			Update_point(1, 1, n, pos, v);
		}
		else if(op == 2)
		{
			int L, R, v;
			cin >> L >> R >> v;
			Update_section(1, 1, n, L, R, v);
		}
		else
		{
			int L, R;
			cin >> L >> R;
			cout << Query(1, 1, n, L, R) << endl;
		}
	}
	return 0;
}
*/
/*

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
struct node
{
	node *next[26];
	int cnt;
	node()
	{
		for(int i = 0; i < 26; ++i)
			next[i] = NULL;
		cnt = 0;
	}
};
void insert(node *root, char ch[], int pos)
{
	if(ch[pos] == '\0') return;
	if(root -> next[ch[pos] - 'a'] == NULL)
	{
		node *temp = new node;
		root -> next[ch[pos] - 'a'] = temp;
	}
	root -> next[ch[pos] - 'a'] -> cnt++;
	insert(root -> next[ch[pos] - 'a'], ch, pos + 1);
}
int query(node *root, char ch[], int pos)
{
	if(root -> next[ch[pos] - 'a'] == NULL) return 0;
	if(ch[pos + 1] == '\0') return root -> next[ch[pos] - 'a'] -> cnt;
	return query(root -> next[ch[pos] - 'a'], ch, pos + 1);
}
int main()
{
	node *root = new node;
	char word[100];
	while(true)
	{
		gets(word);
		if(strlen(word) == 0) break;
		insert(root, word, 0);
	}
	while(~scanf("%s", word))
		printf("%d\n", query(root, word, 0));
	return 0;
}
*/
/*
#include <iostream>
#define m l + (r - l) / 2
#define lson rx * 2, l, m
#define rson rx * 2 + 1, m + 1, r
#define MAXN 105
using namespace std;
int tree[MAXN*4], add[MAXN*4];//开4倍的空间

//下放
void pushdown(int rx, int l, int r)
{
	if(add[rx] != 0)
	{
		add[rx * 2] += add[rx];
		add[rx * 2 + 1] += add[rx];
		tree[rx * 2] += (m - l + 1) * add[rx];
		tree[rx * 2 + 1] += (r - m) * add[rx];
		add[rx] = 0;
	}
}

//建树
void bulid(int rx, int l, int r)
{
	if(l == r)
	{
		cin >> tree[rx];
		return ;
	}
	bulid(lson);
	bulid(rson);
	tree[rx] = tree[rx * 2] + tree[rx * 2 + 1];
}

//更新区间
void update(int rx, int l, int r, int L, int R, int v)
{
	if(R < l || L > r) return;
	if(L <= l && r <= R)
	{
		tree[rx] += (r - l + 1) * v;
		add[rx] += v;
		return ;
	}
	update(lson, L, R, v);
	update(rson, L, R, v);
	tree[rx] = tree[rx * 2] + tree[rx * 2 + 1];
}

//询问区间
int query(int rx, int l, int r, int L, int R)
{
	if(R < l || L > r) return 0;
	pushdown(rx, l, r);
	if(L <= l && r <= R) return tree[rx];
	return query(lson, L, R) + query(rson, L, R);
}

int main()
{
	int n, q;
	cin >> n >> q;
	bulid(1, 1, n);
	while(q--)
	{
		int op; //询问类型1.更新区间2.查询区间
		cin >> op;
		if(op == 1)
		{
			int L, R, v;
			cin >> L >> R >> v;
			update(1, 1, n, L, R, v);
		}
		else
		{
			int L, R;
			cin >> L >> R;
			cout << query(1, 1, n, L, R) << endl;
		}
	}
	return 0;
}
*/
/*
#include <iostream>
using namespace std;
const int MAXN = 40000;//筛4w的素数是远远够的
bool used[MAXN];
int prim[MAXN];//存放素数
int SIZE = 0;//素数的个数
void is_prim()//埃氏素筛法
{
	for(int i = 2; i * i < MAXN; ++i)
	{
		if(!used[i])
		for(int j = 2 * i; j < MAXN; j += i) used[j] = true;
	}
	for(int i = 2; i < MAXN; ++i)
		if(!used[i]) prim[SIZE++] = i;
}
int main()
{
	is_prim();
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		for(int i = 0; i < SIZE && n > 1; ++i)
		{
			while(n > 1 && n % prim[i] == 0)//当n大于1并且n能够除尽prim[i]
			{
				n /= prim[i];
				cout << prim[i] << " ";
			}
		}
		if(n > 1) cout << n;//此时说明n是个素数，并且是大于4w的素数
		cout << endl;
	}
	return 0;
}*/

#include <iostream>

using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	cout << a + b << endl;
	return 0;
}
