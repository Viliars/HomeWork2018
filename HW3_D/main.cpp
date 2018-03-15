#include <iostream>
using namespace std;

int getMax(unsigned int arr[], unsigned int n)
{
    int mx = arr[0];
    for (unsigned int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(unsigned int arr[], unsigned int n, int exp)
{
    int output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}


void radixsort(unsigned int arr[], int n)
{

    int m = getMax(arr, n);
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main()
{
unsigned int n,k,m,l;
cin>>n>>k>>m>>l;
unsigned int a[n];
a[0] = k;
for (unsigned int i = 0; i < n-1; i++)
a[i+1] = (unsigned int)((a[i]*(unsigned long long)m)&0xFFFFFFFFU)%l;
radixsort(a,n);
unsigned long long sum=0;
unsigned half=n/2;
for(unsigned int i=0;i<n;i++)
{
    cout<<a[i]<<" ";
}
cout<<endl;
for(unsigned int i=0;i<n;i+=2)
{
    sum+=a[i];
    if(i==half) sum%=l;
}

cout<<sum%l;

    return 0;
}
