#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
struct node
{
    int cnt;
    struct node* next[26];
};
void check(node* root)
{
    if(root == NULL) exit(-1);
}
void Init(node* &root)
{
    root = new node;
    check(root);
    root -> cnt = 0;
    for(int i = 0; i < 26; ++i)
        root -> next[i] = NULL;
}
void Insert(node *root, string st, int len)
{
    if(st.length() == len)
        root -> cnt++;
    else if(root -> next[st[len] - 'a'] == NULL)
    {
        node* New;
        Init(New);
        root -> next[st[len] - 'a'] = New;
        Insert(New, st, len + 1);
    }
    else
        Insert(root -> next[st[len] - 'a'], st, len + 1);

}
bool Query(node* root, string st, int len)
{
    if(st.length() == len) return root -> cnt > 0;
    if(!root -> next[st[len] - 'a']) return false;
    return Query(root -> next[st[len] - 'a'], st, len + 1); 
}
int main()
{
    node* root;
    Init(root);
    int n; cin >> n;
    while(n--)
    {
        string st; cin >> st;
        Insert(root, st, 0);
    }
    int m; cin >> m;
    while(m--)
    {
        string st; cin >> st;
        puts(Query(root, st, 0)? "YES": "NO");
    }
    return 0;
}
