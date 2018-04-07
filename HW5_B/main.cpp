#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
    int buf;
    cin>>n;
    vector< vector<int> > a(n);
    for(auto& x:a)
    {
        for(int i=0;i<n;++i) { cin>>buf; x.push_back(buf); }
    }
    int x;
	cin>>x;
	int lf,rg;
	for (int i=0;i<n;++i)
	{
	    lf=0;
	    rg=n-1;
		// bin search
		while (lf!=rg)
		{
			int mid=(lf+rg)>>1;
			if (x>a[i][mid])
                lf=mid+1;
			else
                rg=mid;
		}
		if (a[i][lf]==x )
		{
			cout << "yes";
			return 0;
		}
	}
	cout << "no";
	return 0;
}
