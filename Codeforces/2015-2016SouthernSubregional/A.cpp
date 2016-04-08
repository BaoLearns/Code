#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

const string MAIL = "@bmail.com";
bool ok(string &st)
{
	if(st.length() > 10 && st.substr(st.length() - 10) == MAIL) return true;
	return false;
}
void to_lower(string &st)
{
	int len = st.length();
	for(int i = 0; i < len; ++i)
		if(st[i] >= 'A' && st[i] <= 'Z') st[i] += 32;
}
void delete_plus_point(string &st)
{
	int len = st.length();
	string t("");
	bool f = false, f1 = false;
	for(int i = 0; i < len; ++i)
	{
		if(st[i] == '+')
		{
			f = true;
			for(int j = i + 1; j < len; ++j)
			{
				if(st[j] == '@') f = false;
				if(!f) t += st[j];
			}
			break;
		}
		else if(st[i] == '.')
		{
			if(f1) t += st[i];
		}
		else
		{
			if(st[i] == '@') f1 = true;
			t += st[i];
		}

	}
	st = t;
}
int main(int argc, char **argv)
{
	int n;
	cin >> n;
	string st[n];
	map <string, vector <string> > Map;
	for(int i = 0; i < n; ++i)
	{
		cin >> st[i];
		string t = st[i];
		to_lower(t);
		if(ok(t))
			delete_plus_point(t);
		Map[t].push_back(st[i]);
	}
	cout << Map.size() << endl;
	for(map <string, vector<string> >::iterator it = Map.begin(); it != Map.end(); ++it)
	{
		cout << it -> second.size() << " ";
		//cout << it -> first << endl;
		for(int i = 0; i < it -> second.size(); ++i)
			cout << it -> second[i] << " ";
		cout << endl;

	}
	return 0;
}
