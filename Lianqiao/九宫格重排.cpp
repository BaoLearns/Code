#include <iostream>
#include <queue>
#include <set>
#include <string>
#define P pair <string, int>
using namespace std;
inline string Makechang(string st, int pos1, int pos2)
{
    char c = st[pos1];
    st[pos1] = st[pos2];
    st[pos2] = c;
    return st;
}
void bfs(string start, string end)
{
    string st;
    P e;
    int pos;
    queue <P> que;
    set <string> vised;
    que.push(P(start, 0));
    while(!que.empty())
    {
        e = que.front();
        que.pop();
        if(e.first == end)
        {
            cout << e.second << endl;
            return ;
        }
        if(vised.find(e.first) != vised.end())
            continue;
        vised.insert(e.first);
        for(int i = 0; i < 9; ++i)
            if(e.first[i] == '.')
            {
                pos = i;
                break;
            }
        if(pos - 3 >= 0)  //ио
        {
            st = Makechang(e.first, pos, pos - 3);
            que.push(P(st, e.second + 1));
            //vised.insert(st);
        }
        if(pos + 3 < 9) //об
        {
            st = Makechang(e.first, pos, pos + 3);
            que.push(P(st, e.second + 1));
            //vised.insert(st);
        }
        if(pos != 0 && pos != 3 && pos != 6) //вС
        {
            st = Makechang(e.first, pos, pos - 1);
            que.push(P(st, e.second + 1));
            //vised.insert(st);
        }
        if(pos != 2 && pos != 5 && pos != 8) //ср
        {
            st = Makechang(e.first, pos, pos + 1);
            que.push(P(st, e.second + 1));
            //vised.insert(st);
        }
        //cout << "iiiiiii" << endl;
    }
    cout << -1 << endl;
}
int main()
{
    string start, end;
    cin >> start >> end;
    bfs(start, end);
}

