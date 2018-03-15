#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


bool cmp(pair<double,int>& a,pair<double,int>& b)
{
    return a.first<b.first||(a.first==b.first&&a.second>b.second);
}

int main() {
int n;
double f;
vector< pair<double,int> > a;
pair<double,int> s;
    cin>>n;
    string str1,str2;
    for(int i=0;i<n;i++)
    {
    cin>>str1>>str2;
    str1[2]='.';
    str2[2]='.';
    f=atof(str1.c_str());
    s=make_pair(f,1);
    a.push_back(s);
    f=atof(str2.c_str());
    s=make_pair(f,-1);
    a.push_back(s);
    }
    int max=-1;
    int sum=0;
    sort(a.begin(),a.end(),cmp);

    for(int i=0;i<2*n;i++)
    {
        sum+=a[i].second;
        if(max<sum) max=sum;
    }
    cout<<max;
    return 0;
}
