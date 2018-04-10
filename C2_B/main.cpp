#include <iostream>
#include <vector>
using namespace std;

int main()
{
   string s;
   cin>>s;
   int res=0;
   vector<int> a(s.size());
    for (int j = 1, l = 0, r = 0; j < s.size(); j++)
    {
        int p = j > r ? j : j+min(r-j+1,a[j-l]);
        while (p < s.size() && s[p] == s[p-j]) p++;
        a[j] = p-j;
        if (p > r)
        {
            l = j;
            r = p-1;
        }
    }

    for(auto& x:a) { if(x!=0)
        {
            break;
        }
        res++;
    }
    int res2;
    int max1=0,max2=0;
    for(auto& x:a)
    {
        if(max1<x) { max2=max1; max1=x; }
            else
                if(max2<x) max2=x;
    }
    res2=max1-max2;
    if(res>=a.size()/2)  cout<<res;
    else cout<<res2;
    return 0;
}
