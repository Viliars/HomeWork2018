#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    int n,m,k;
    unsigned long long buf=0;
    std::cin>>n>>m>>k;
    std::vector<int> a(m);
    std::vector<unsigned long long> key;
    std::vector<int> ans;
    //std::vector<int> proba;
    int z[]={73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151};
    int z2[]= {661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769};
    //std::cout<<"Z = "<<z<<std::endl;
    for(int j=0;j<n;++j)
    {
        for(int i=0;i<m;++i) std::cin>>a[i];
        std::sort(a.begin(),a.end());
        buf=0;
        for(int i=0;i<a.size();++i)
            buf+=(long long)a[i]*z[i%16]*z2[i%16];

        key.push_back(buf);
    }
    //std::sort(key.begin(),key.end());
    //std::cout<<"------------------------------\n";
    //std::copy(key.begin(), key.end(), std::ostream_iterator<int>(std::cout, "\n"));
    for(int i=0;i<k;++i)
    {
        for(int i=0;i<m;++i) std::cin>>a[i];
        std::sort(a.begin(),a.end());
        buf=0;
        //std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " "));
        for(int i=0;i<m;++i)
            buf+=(long long)a[i]*z[i%16]*z2[i%16];
        //std::cout<<std::endl<<buf<<std::endl;
        auto it=std::lower_bound(key.begin(),key.end(),buf);
        if(it!=key.end()&&*it==buf) ans.push_back(1);
        else ans.push_back(0);
    }

    std::copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, "\n"));
    return 0;
}
