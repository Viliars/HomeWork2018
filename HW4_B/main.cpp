#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	int rez;
	int core;
	int buf;
	scanf("%d %d",&n,&m);
	vector< vector<int> > a(n);
	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < m; ++k)
		{
			scanf("%d",&buf); a[i].push_back(buf);
		}
	}
    // all sort
	for(int i=0;i<n;++i) sort(a[i].begin(),a[i].end());
//------------------------------------------------------
    rez=0;
	for (int i = 0; i < n; ++i)
		for (int k = i + 1; k < n; ++k)
		{
			core = 0;
			int j=0;
			int l=0;
			while(true)
            {
                if(j >= m || l >= m) break;
                if (a[i][j] < a[k][l]) j++;
                else
                    if(a[i][j] > a[k][l]) l++;
                    else { core++; j++; l++; }
            }
			if (rez < core) rez = core;
		}
	printf("%d",rez);
	return 0;
}
