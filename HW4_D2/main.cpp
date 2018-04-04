#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
typedef vector<int> BigInt;
int sizeS;
const int base = 1000*1000*1000;

    void scan(BigInt& a,string s)
    {
        for (int i=(int)s.length(); i>0; i-=9)
	if (i < 9)
		a.push_back (atoi (s.substr (0, i).c_str()));
	else
		a.push_back (atoi (s.substr (i-9, 9).c_str()));
    }
    void print(BigInt& a)
    {
    printf ("%d", a.empty() ? 0 : a.back());
    for (int i=(int)a.size()-2; i>=0; --i)
	printf ("%09d", a[i]);
    }

BigInt add(BigInt a,BigInt& b)
{
    int carry = 0;
    for (size_t i=0; i<max(a.size(),b.size()) || carry; ++i) {
	if (i == a.size())
		a.push_back (0);
	a[i] += carry + (i < b.size() ? b[i] : 0);
	carry = a[i] >= base;
	if (carry)  a[i] -= base;
}
return a;
}
BigInt mul(BigInt& a,BigInt& b)
{
    BigInt c(a.size()+b.size());
    for (size_t i=0; i<a.size(); ++i)
	for (int j=0, carry=0; j<(int)b.size() || carry; ++j) {
		long long cur = c[i+j] + a[i] * 1ll * (j < (int)b.size() ? b[j] : 0) + carry;
		c[i+j] = int (cur % base);
		carry = int (cur / base);
	}
while (c.size() > 1 && c.back() == 0)
	c.pop_back();
    return c;
}
void del(BigInt& a,int b=2)
{
    int carry = 0;
for (int i=(int)a.size()-1; i>=0; --i) {
	long long cur = a[i] + carry * 1ll * base;
	a[i] = int (cur / b);
	carry = int (cur % b);
}
while (a.size() > 1 && a.back() == 0)
	a.pop_back();
}

BigInt sub(BigInt a,BigInt&b )
{
    int carry = 0;
    for (size_t i=0; i<b.size() || carry; ++i) {
	a[i] -= carry + (i < b.size() ? b[i] : 0);
	carry = a[i] < 0;
	if (carry)  a[i] += base;
}
while (a.size() > 1 && a.back() == 0)
	a.pop_back();
return a;
}




BigInt sqrt(BigInt& another)
{
    string s1(sizeS/2-1,'0');
    string s2((sizeS+1)/2,'0');
    string s3='1'+s1;
    string s4='1'+s2;
    //cout<<"LEN = "<<sizeS<<endl;
    BigInt l,r;
    scan(l,s3);
    scan(r,s4);
    //cout<<l<<" "<<r<<endl;
    BigInt m,buf,res;
    cout<<"ADASDASDASDasd\n";
    while (l<=r)
    {
      m=add(l,r);
      del(m);
      cout<<"------------------------------\n";
      if (mul(m,m) <= another)
      {
        res = m;
        scan(buf,"1");
        l = add(m,buf);
      }
      else{
         scan(buf,"1");
         cout<<"+++++++++++++++++++++++++++++\n";
        r = sub(m,buf);
        cout<<"-------------------------------\n";
      }
    }
    return res;
}




int main()
{
   string s1;
   cin>>s1;
   sizeS=s1.size();
   BigInt a,b;
   cout<<"ALL GOOD\n";
   scan(a,s1);
   cout<<"AND TUT\n";
   b=sqrt(a);
   print(b);
    return 0;
}
