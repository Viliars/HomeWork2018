#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,sol;
    int rez=60;
    int buf=0;
    cin>>sol>>n;
    long long sum=0;
    vector<int> a(2*n);
    for(int i=0;i<2*n;i+=2)
    {
        sum+=2*a[i];
        cin>>a[i];
        a[i+1]=a[i];
    }
    if(sum<sol) { cout<<"Impossible"; return 0; }
    if(sum==sol) { cout<<2*n; return 0; }
    int x=0,y=0;
    n*=2;
        for (int mask = 1; mask < (1 << n); mask++) {
            int tmp = mask;
            for (int i = 1; i <= n; i++) {
                if (tmp % 2) { x+=a[i]; buf++; }
                tmp /= 2;
                if(x>sol) break;
            }
            if(x==sol) rez=min(rez,buf);
            x=0;
        }
        if(rez!=60) cout<<rez;
        else cout<<Change;
    return 0;
    }
