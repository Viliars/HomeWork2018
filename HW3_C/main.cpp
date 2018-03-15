#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> CONST;
int k;
int k1;

bool cmp(const pair<string,vector<int> >& a,const pair<string,vector<int> > & b )
{
    if(k1==k) { k1=0; //cout<<a.first<<" sor "<<b.first<<endl;
    return false; }
    if(a.second[CONST[k1]]<b.second[CONST[k1]]) { //cout<<a.first<<' '<<a.second[CONST[k1]]<<" < "<<b.first<<' '<<b.second[CONST[k1]]<<endl;
            k1=0; return true; }
    if(a.second[CONST[k1]]==b.second[CONST[k1]]) { //cout<<a.first<<' '<<a.second[CONST[k1]]<<" == "<<b.first<<' '<<b.second[CONST[k1]]<<endl;
        k1++; return cmp(a,b); }
    //cout<<a.first<<' '<<a.second[CONST[k1]]<<" > "<<b.first<<' '<<b.second[CONST[k1]]<<endl;
    k1=0;
    return false;
}


int main()
{
   int n;
   int z;
   cin>>n;
   cin>>k;
   k1=0;
   for(int i=0;i<k;i++) { cin>>z; z--; CONST.push_back(z); }
   string str;
   pair<string,vector<int> > s;
   vector<pair<string,vector<int> > > a;
   for(int i=0;i<n;i++)
   {
    vector<int> buf;
    cin>>str;
    for(int j=0;j<k;j++) { cin>>z; buf.push_back(z); }
    s=make_pair(str,buf);
    a.push_back(s);
   }


   sort(a.begin(),a.end(),cmp);
   for(int i=n-1;i>=0;i--) cout<<a[i].first<<endl;
    return 0;
}
