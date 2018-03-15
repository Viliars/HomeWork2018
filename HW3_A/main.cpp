#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


bool cmp(pair<int,int>& a,pair<int,int>& b)
{
    return a.first<b.first;
}

int main() {

pair <int,int> s;
    vector< pair<int,int> > a;
    int n,x,y;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        s=make_pair(x,i);
        a.push_back(s);
    }
    sort(a.begin(),a.end(),cmp);
    int min=1000*1000*1001;
     for(int i=1;i<n;i++)
    {
        if(min>(a[i].first-a[i-1].first)) { min=a[i].first-a[i-1].first; x=a[i-1].second; y=a[i].second; }
    }
    cout<<min<<endl;
    cout<<std::min(x,y)<<" "<<std::max(x,y);
    return 0;
}
