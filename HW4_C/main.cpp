#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;


void sort_bubble(vector<unsigned>& a) {
   int n=(int)a.size();
   bool sorted = false;
   while (!sorted) {
      sorted = true;
      for (int i = 0; i < n-1; i++) {
        if (a[i] > a[i+1]) {
           int tmp = a[i];
           a[i] = a[i+1];
           a[i+1] = tmp;
           sorted = false;
        }
      }
    }
}

typedef unsigned long ulong;
int main()
{
    int n;
    double sum=0;
    cin>>n;
    vector<ulong> a(n);
    for(auto& x:a) cin>>x;
    ulong c1,c2;
    priority_queue<ulong, vector<ulong>, greater<ulong>> q(a.begin(), a.end());

            while(q.size()>(size_t)1)
            {
                c1=q.top();
                //cout<<c1<<" ";
                q.pop();
                c2=q.top();
                //cout<<c2<<endl;
                q.pop();
                sum+=c1+c2;
                q.push(c1+c2);
            }

    //sum+=q.top();
    /*vector<unsigned> bufer(n);
    int point[FF];
    int buf[FF];
    for(int i=0;i<n;i++) cin>>a[i];
    for (int i = 0; i < 32; i+=eight)
    {
        point[0] = 0;
        for (int k = 0; k < FF; ++k) buf[k] = 0;
        for (int k = 0; k < n; ++k) ++buf[a[k] >> i & (FF-1)];
        for (int k = 1; k < FF; ++k) point[k] = point[k - 1] + buf[k - 1];
        for (int k = 0; k < n; ++k) bufer[point[a[k] >> i & (FF-1)]++] = a[k];
        a.swap(bufer);
    }
    for(size_t i=0;i<a.size();++i)
                cout<<a[i]<<" ";
                cout<<endl;

    while(a.size()!=(size_t)1)
    {
                a[0]+=a[1];
                sum+=a[0];
                a.erase(a.begin()+1);
                sort_bubble(a);
    }

    //for(size_t i=0;i<a.size();++i)
          //      cout<<a[i]<<" ";
          */
    sum/=100;

        printf("%.2f", sum);
    return 0;
}
