#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, m, rez = 0;
	int core;
	int buf;
	cin >> n >> m;
	vector<vector<int> > a(n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> buf; a[i].push_back(buf);
		}
	}
    // all sort
	for(int i=0;i<n;++i) sort(a[i].begin(),a[i].end());
//------------------------------------------------------
	for (int i = 0; i < n; ++i)
		for (int k = i + 1; k < n; ++k)
		{
			core = 0;
			int j=0;
			int l=0;
			for (; j < m && l < m;)
            {
                if (a[i][j] < a[k][l]) j++;
                else
                    if(a[i][j] > a[k][l]) l++;
                    else { core++, j++, l++; }
            }
			if (rez < core) rez = core;
		}
	cout << rez;
	return 0;
}
