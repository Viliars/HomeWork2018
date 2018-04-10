#include<cstdio>
#include<iostream>
#include <vector>
using namespace std;
int main()
{
int n;
int buf;
scanf("%d",&n);
int max1=-1,max2=-1,max3=-1;
int mmax1=1,mmax2=1;
bool flag;
for(int i=0;i<n;++i)
{
    scanf("%d",&buf);
    if(buf<0)
    {
        if(mmax1>buf) { mmax2=mmax1; mmax1=buf; }
        else
            if(mmax2>buf) mmax2=buf;
    }
    else
    {
        if(max1<buf) { max3=max2; max2=max1; max1=buf; }
        else
            if(max2<buf) { max3=max2; max2=buf; }
            else
                if(max3<buf) max3=buf;
    }
}
flag=(mmax1!=1&&mmax2!=1)? true : false;

long long answer2;
long long answer1;
long long answer;
answer1=(long long)mmax1*mmax2*max1;
answer2=(long long)max1*max2*max3;
if(flag) { answer=max(answer1,answer2); }
else answer=answer2;

cout<<answer;
//for(auto& x:a) cout<<x<<" ";

    return 0;
}
