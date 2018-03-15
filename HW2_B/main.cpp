
#include<iostream>

using namespace std;

bool flag;

long long evklid (long long a, long long b, long long & x, long long & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    long long buf_x, buf_y;
    long long d = evklid (b%a, a, buf_x, buf_y);
    x = buf_y - (b / a) * buf_x;
    y = buf_x;
    return d;
}

void inter (long long a, long long b, long long n, long long & x0, long long & y0, long long & e) {
    e = evklid (abs(a), abs(b), x0, y0);
    if (n % e != 0) { flag=false; return; }
    x0 *= n / e;
    y0 *= n / e;
    if (a < 0)   x0 *= -1;
    if (b < 0)   y0 *= -1;
    if(x0<=0) while(x0<=0) x0+=abs(b/e);
    else { while(x0>0) x0-=abs(b/e); x0+=abs(b/e); }
    y0=(n-a*x0)/b;
    flag=true;
}
int main()
{
    long long a,b,n;
    long long x0,y0,e;
    cin>>a>>b>>n;
    if(a==0&&b==0&&n==0) cout<<1<<" "<<0;

    inter(a,b,n,x0,y0,e);
    if(flag) cout<<x0<<" "<<y0;
    else cout<<"No";
    return 0;
}
