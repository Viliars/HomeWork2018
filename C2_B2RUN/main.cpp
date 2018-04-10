#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	string s;
	cin>>s;
	vector<int> a(s.size());
	for (int j = 1, l = 0, r = 0; j < s.size(); j++)
	{
		int p = j > r ? j : j + min(r - j + 1, a[j - l]);
		while (p < s.size() && s[p] == s[p - j]) p++;
		a[j] = p - j;
		if (p > r)
		{
			l = j; r = p - 1;
		}
	}

	int n=s.size();
	for (int i = 0; i < s.size(); ++i)
	{
		if (s.size() - a[i] == i)
		{
			n = s.size() - a[i];
			break;
		}
	}

	if (n > s.size() / 2)
	{
        cout<<n;
		return 0;
	}

	auto it = s.begin();
	it+=n;
	string str(it, s.end());
	vector<int> b(str.size());
	for (int j = 1, l = 0, r = 0; j < str.size(); j++)
	{
		int p = j > r ? j : j + min(r - j + 1, b[j - l]);
		while (p < str.size() && str[p] == str[p - j]) p++;
		b[j] = p - j;
		if (p > r)
		{
			l = j; r = p - 1;
		}
	}

	int res = str.size();
	for (int i = 0; i < str.size(); ++i)
	{
		res = min(res, (int)(str.size() - b[i]));
	}
    cout<<res;
	return 0;
}
