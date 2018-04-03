#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
int n,k;
cin>>n>>k;
vector<int> a(n);
for(int i=0;i<n;++i)
{
    cin>>a[i];
}
sort(a.begin(),a.end());
int max=a[n-1];
int lf=0;
int rg=max;
int sum=0;
while(lf+1<rg)
{
    int mid=(lf+rg)>>1;
    sum=0;
    for(int i=0;i<n;++i) sum+=a[i]/mid;
    if(sum>=k) lf=mid;
    else rg=mid;
}
sum=0;
for(int i=0;i<n;++i) sum+=a[i]/rg;
if(sum>=k) cout<<rg;
else cout<<lf;
    return 0;
}
