#include <iostream>
#include <vector>
using namespace std;
int buf[FF];
int main()
{
int n;
unsigned k,m,l;
const unsigned FF=256;
const unsigned eight=8;
cin>>n>>k>>m>>l;
vector<unsigned> a(n);
vector<unsigned> bufer(n);
int point[FF];
a[0] = k;
for (int i = 1; i < n; ++i)
	{
		a[i] = (unsigned int) ((a[i - 1] * (unsigned long long) m) & 0xFFFFFFFFU) % l;
	}
unsigned long long sum=0;
for (int i = 0; i < 32; i+=eight)
{
    point[0] = 0;
    for (int k = 0; k < FF; ++k) buf[k] = 0;
    for (int k = 0; k < n; ++k) ++buf[a[k] >> i & (FF-1)];
    for (int k = 1; k < FF; ++k) point[k] = point[k - 1] + buf[k - 1];
    for (int k = 0; k < n; ++k) bufer[point[a[k] >> i & (FF-1)]++] = a[k];
    a.swap(bufer);
}

for (int i = 0; i < n; i+=2)
{
    sum+=a[i];
}
sum%=l;
cout<<sum;
    return 0;
}
