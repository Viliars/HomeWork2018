#include <iostream>
using namespace std;
// RADIX
void BitsRadixSort(unsigned int a[], int n)
{
    //  255 = 11111111
    unsigned bufer[n];
    int buf[256];
    int point[256];
    for (int i = 0; i < 32; i +=8)
	{
	    // vector for sum
		point[0] = 0;
		// buf=0
		for (int k = 0; k < 256; k++) buf[k] = 0;
        // count
		for (int k = 0; k < n; k++) buf[a[k] >> i & 255]++;
        // run sum
		for (int k = 1; k < 256; k++) point[k] = point[k - 1] + buf[k - 1];
        // set locate
		for (int k = 0; k < n; k++) bufer[point[a[k] >> i & 255]++] = a[k];

		// swap
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
