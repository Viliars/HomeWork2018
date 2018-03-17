#include <iostream>
using namespace std;

void BitsRadixSort(unsigned int a[], int n)
{
    //  255 = 11111111
    unsigned bufer[n];
    int buf[256];
    int point[256];
    for (int i = 0; i < 32; i +=8)
	{
		point[0] = 0;

		// buf=0
		for (int j = 0; j < 256; j++) buf[j] = 0;

		for (int j = 0; j < n; j++) buf[a[j] >> i & 255]++;
		for (int j = 1; j < 256; j++) point[j] = point[j - 1] + buf[j - 1];
		for (int j = 0; j < n; ++j) bufer[point[a[j] >> i & 255]++] = a[j];
		for(int i=0;i<n;i++) a[i]=bufer[i];
	}
}

int main()
{
unsigned n,k,m,l;
cin>>n>>k>>m>>l;
unsigned a[n];
// ------------------------------------------------------------------------------------------------------------
a[0] = k;
for (unsigned int i = 0; i < n-1; i++) a[i+1] = (unsigned int)((a[i]*(unsigned long long)m)&0xFFFFFFFFU)%l;
// ------------------------------------------------------------------------------------------------------------
unsigned long long sum=0;

BitsRadixSort(a,n);

for (int i = 0; i < n; i += 2)
{
    sum = (sum + a[i]) % l;
}
cout << sum;

    return 0;
}
