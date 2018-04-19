#include<iostream>
#include<vector>
#include<iterator>

int calc(std::vector<int>& a, unsigned left,unsigned right,bool flag)
{
    if(flag)
        {
            if(left==1) return 0;
            a[left>>1]=a[left]^a[left^1];
            calc(a,left>>1,0,true);
        }
    else
        {
            int res=0;
            if(left&1) res^=a[left++];
            if(!(right&1)) res^=a[right--];
            if (right>left) res^=calc(a,left>>1,right>>1,false);
            return res;
        }
return 0;
}

int main()
{
	unsigned n, m;
	std::vector<int> a;
	std::cin>>n>>m;
    unsigned left, right;
    unsigned core;
    unsigned code;
	for (code = 1; (n - 1) >> code > 0; ++code);
	core = (1 << code);
    a.reserve(core << 1);
	for (unsigned i = 0; i < n; ++i)
	{
		std::cin>>a[i+core];
	}
	for(unsigned i=0;i<n;i++) calc(a,i+core,0,true);
	std::vector<int> res;
	for (unsigned i=0;i<m;++i)
	{
		std::cin>>code>>left>>right;
		if (code == 1) res.push_back(calc(a, core + left, core + right,false));
		else a[core+left]=right,calc(a,core+left,0,true);
	}
	std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, "\n"));
	return 0;
}
