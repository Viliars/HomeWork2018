#include <iostream>
using namespace std;

long num[27];
char word(int n,long k)
{
    if(k==0) return (char)(n+'a'-1);
    return word(n-1,(k-1)%num[n-1]);
}


int main() {
    int n;
    long k,l;
    cin>>n>>k>>l;
    num[1]=1;
    k--;
    l--;
    for(int i=2;i<27;i++) num[i]=num[i-1]*2+1;
    for(int i=k;i<=l;i++) cout<<word(n,i);
    return 0;
}